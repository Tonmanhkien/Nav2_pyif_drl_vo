#! /usr/bin/env python3

from geometry_msgs.msg import PoseStamped, TwistStamped
import numpy as np
from stable_baselines3 import PPO

goal_pose = PoseStamped()       
position_all = []             
latest_scan = None            


def updateScan(scan_msg):
    """
    This function should be called from your /scan callback to update the latest lidar scan.
    """
    global latest_scan
    latest_scan = scan_msg


def computeVelocityCommands(occupancy_grid, pose, twist):
    model = PPO.load('/home/kien/colcon_ws/src/nav2_pyif/drl_vo_controller/model/drl_vo.zip')
    """
    Compute velocity commands using PPO inference.
    The observation is composed of:
      - A pedestrian map (80x80x2), set as zeros.
      - A lidar scan (80x80) obtained from the latest /scan data.
      - A goal position (2x1) extracted from the global goal.
    The PPO model then outputs an action which is mapped to a TwistStamped command.
    
    Parameters:
      occupancy_grid: (unused in this implementation)
      pose: The current robot pose (used for header information)
      twist: (unused in this implementation)
      
    Returns:
      A TwistStamped message with the computed linear.x and angular.z velocities.
    """
    ped_pos = np.zeros((80, 80, 2), dtype=np.float32)
    
    #Lidar scan is set to zero for now 
    latest_scan = None
    if latest_scan is not None:
        # Convert the ranges to a NumPy array.
        scan_arr = np.array(latest_scan.ranges, dtype=np.float32)
        scan_resized = np.resize(scan_arr, (80, 80))
    else:
        scan_resized = np.zeros((80, 80), dtype=np.float32)
    
    if goal_pose is not None:
        goal_arr = np.array([goal_pose.pose.position.x, goal_pose.pose.position.y], dtype=np.float32)
        goal_arr = goal_arr.reshape(2, 1)
    else:
        goal_arr = np.zeros((2, 1), dtype=np.float32)

    observation = np.concatenate((ped_pos.flatten(), scan_resized.flatten(), goal_arr.flatten()))

    # Use the PPO model to predict an action.
    action, _ = model.predict(observation)
    
    # Map the action output to command velocities.
    vx_min = - 0.2
    vx_max = 0.2
    vz_min = -1.0
    vz_max = 1.0
    
    linear_x = (action[0] + 1) * (vx_max - vx_min) / 2 + vx_min
    angular_z = (action[1] + 1) * (vz_max - vz_min) / 2 + vz_min
    
    cmd_vel = TwistStamped()
    cmd_vel.header = pose.header
    cmd_vel.twist.linear.x = linear_x
    cmd_vel.twist.angular.z = angular_z
    cmd_vel = TwistStamped()
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
