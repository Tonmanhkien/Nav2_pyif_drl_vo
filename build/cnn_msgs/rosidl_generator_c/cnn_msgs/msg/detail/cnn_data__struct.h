// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cnn_msgs:msg/CNNData.idl
// generated code does not contain a copyright notice

#ifndef CNN_MSGS__MSG__DETAIL__CNN_DATA__STRUCT_H_
#define CNN_MSGS__MSG__DETAIL__CNN_DATA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'ped_pos_map'
// Member 'scan'
// Member 'scan_all'
// Member 'image_gray'
// Member 'depth'
// Member 'goal_cart'
// Member 'goal_final_polar'
// Member 'vel'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/CNNData in the package cnn_msgs.
/**
  * CNN_data.msg
 */
typedef struct cnn_msgs__msg__CNNData
{
  /// Pedestrian position costmap in Cartesian coordinates (2 channels, 20m x 20m)
  rosidl_runtime_c__float__Sequence ped_pos_map;
  /// Laser scan data: 720 range values from the laser scanner
  rosidl_runtime_c__float__Sequence scan;
  /// Extended laser scan data: 1080 range values from the laser scanner
  rosidl_runtime_c__float__Sequence scan_all;
  /// Grayscale image data from the ZED camera
  rosidl_runtime_c__float__Sequence image_gray;
  /// Depth image data from the ZED camera
  rosidl_runtime_c__float__Sequence depth;
  /// Current goal in the robot frame (Cartesian coordinates)
  rosidl_runtime_c__float__Sequence goal_cart;
  /// Final goal in the robot frame (polar coordinates)
  rosidl_runtime_c__float__Sequence goal_final_polar;
  /// Current velocity in the robot frame
  rosidl_runtime_c__float__Sequence vel;
} cnn_msgs__msg__CNNData;

// Struct for a sequence of cnn_msgs__msg__CNNData.
typedef struct cnn_msgs__msg__CNNData__Sequence
{
  cnn_msgs__msg__CNNData * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cnn_msgs__msg__CNNData__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CNN_MSGS__MSG__DETAIL__CNN_DATA__STRUCT_H_
