#!/usr/bin/env python3

from geometry_msgs.msg import PoseStamped, TwistStamped
from sensor_msgs.msg import LaserScan
import numpy as np
import numpy.matlib
from stable_baselines3 import PPO
import rclpy
from rclpy.node import Node
import rclpy.logging
import math 

import sys
from . import custom_cnn_full

sys.modules['custom_cnn_full'] = custom_cnn_full
logger = rclpy.logging.get_logger('controller_server')


model = PPO.load('/home/kien/colcon_ws/src/nav2_pyif/drl_vo_controller/model/drl_vo.zip', device='cpu')
goal_pose = PoseStamped()       
position_all = []             

#Store last 10 scans 
scan_buffer = []         

def upsample_scan(scan, target_length = 720):
    original_length = len(scan)
    x_old = np.linspace(0, 1, original_length)
    x_new = np.linspace(0, 1, target_length)
    upsampled_scan = np.interp(x_new, x_old, scan)
    return upsampled_scan

def scan_callback(msg):
    global scan_buffer
    scan_arr = np.array(msg.ranges, dtype=np.float32)
    if len(scan_arr) == 360:
        scan_arr = upsample_scan(scan_arr, target_length=720)
    scan_buffer.append(scan_arr)
    if len(scan_buffer) > 10:
        scan_buffer.pop(0)
    rclpy.logging.get_logger('controller_server').info(f"Lidar scan updated. Buffer size: {len(scan_buffer)}")

class LidarSubscriber(Node):
    def __init__(self):
        super().__init__('lidar_subscriber')
        self.create_subscription(
            LaserScan,
            '/scan',  
            scan_callback,
            10
        )

def computeVelocityCommands(occupancy_grid, pose, twist):
    """
    Compute velocity commands using PPO inference.
    The observation is composed of:
      - A pedestrian map (80x80x2), set as zeros.
      - A lidar scan (80x80) processed from the /scan data.
      - A goal position (2x1) extracted from the global goal.
    The PPO model then outputs an action which is mapped to a TwistStamped command.
    
    Parameters:
      occupancy_grid: (unused in this implementation)
      pose: The current robot pose (used for header information)
      twist: (unused in this implementation)
      
    Returns:
      A TwistStamped message with the computed linear.x and angular.z velocities.
    """
    logger = rclpy.logging.get_logger('controller_server')

    global model, scan_buffer, goal_pose

    ped_pos = np.zeros((80, 80, 2), dtype=np.float32)
    
    cmd_vel = TwistStamped()
    cmd_vel.header = pose.header

    # #Process lidar data 
    if len(scan_buffer) < 10:
        # Not enough scans collected; use a default (zeros) 10x720 array.
        raw_scan = np.zeros((10, 720), dtype=np.float32)
        logger.warn("Insufficient lidar scans in buffer; using zeros for lidar data.")
    else:
        raw_scan = np.stack(scan_buffer, axis=0)
    

    # If the goal is close (safety check)
    if len(scan_buffer) > 1:
        recent_scan = scan_buffer[-1]
        min_scan_dist  = np.min(recent_scan)
    else:
        min_scan_dist = 10
    
    dx = goal_pose.pose.position.x - pose.pose.position.x
    dy = goal_pose.pose.position.y - pose.pose.position.y

    distance_to_go = math.sqrt(dx**2 + dy**2)

    if distance_to_go <= 0.9:
        logger.info("Option 1")
        cmd_vel.twist.linear.x = 0
        cmd_vel.twist.angular.z = 0 

    elif min_scan_dist <= 0.4:
        logger.info("Option 2")
        cmd_vel.twist.linear.x = 0
        cmd_vel.twist.angular.z = 0.7
    else:
        logger.info("Option 3")
        if goal_pose is not None:
            goal_arr = np.array([goal_pose.pose.position.x, goal_pose.pose.position.y], dtype=np.float32)
            goal_arr = goal_arr.reshape(2, 1)
        else:
            goal_arr = np.zeros((2, 1), dtype=np.float32)
        scan_avg = np.zeros((20, 80), dtype=np.float32)

        for n in range(10):
            scan_tmp = raw_scan[n, :]
            for i in range(80):
                segment = scan_tmp[i*9:(i+1)*9]
                scan_avg[2*n, i] = np.min(segment)
                scan_avg[2*n+1, i] = np.mean(segment)
        scan_avg = scan_avg.reshape(1600)
        scan_avg_map = np.matlib.repmat(scan_avg, 1, 4)
        scan_norm = np.array(scan_avg_map).reshape(6400)
        s_min = 0
        s_max = 30
        scan_norm = 2 * (scan_norm - s_min) / (s_max - s_min) - 1

        #goal
        #MaxAbsScaler :
        g_min = -2
        g_max = 2

        goal = 2 * (goal_arr - g_min) / (g_max -g_min) - 1

        observation = np.concatenate((ped_pos.flatten(), scan_norm.flatten(), goal.flatten()))
        # Use the PPO model to predict an action.
        action, _ = model.predict(observation)
        # Map the action output to command velocities.
        vx_min = - 0.2
        vx_max = 0.2
        vz_min = -1.0
        vz_max = 1.0
        
        linear_x = (action[0] + 1) * (vx_max - vx_min) / 2 + vx_min
        angular_z = (action[1] + 1) * (vz_max - vz_min) / 2 + vz_min
        
        cmd_vel.twist.linear.x = linear_x
        cmd_vel.twist.angular.z = angular_z
    return cmd_vel

def handleGlobalPlan(global_path):
    position_x = []
    position_y = []
    i=0
    while(i <= len(global_path.poses)-1):
        position_x.append(global_path.poses[i].pose.position.x)
        position_y.append(global_path.poses[i].pose.position.y)
        i=i+1
    position_all = [list(double) for double in zip(position_x,position_y)]
    
    return position_all

def setPath(global_plan):
    global goal_pose 
    goal_pose = global_plan.poses[-1]
    global position_all
    position_all = handleGlobalPlan(global_plan)
    return


def setSpeedLimit(speed_limit, is_percentage):
    return

rclpy.init(args=None)
lidar_subscriber = LidarSubscriber()
import threading
sub_thread = threading.Thread(target=rclpy.spin, args=(lidar_subscriber,), daemon=True)
sub_thread.start()