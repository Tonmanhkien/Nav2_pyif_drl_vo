// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cnn_msgs:msg/CNNData.idl
// generated code does not contain a copyright notice

#ifndef CNN_MSGS__MSG__DETAIL__CNN_DATA__BUILDER_HPP_
#define CNN_MSGS__MSG__DETAIL__CNN_DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cnn_msgs/msg/detail/cnn_data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cnn_msgs
{

namespace msg
{

namespace builder
{

class Init_CNNData_vel
{
public:
  explicit Init_CNNData_vel(::cnn_msgs::msg::CNNData & msg)
  : msg_(msg)
  {}
  ::cnn_msgs::msg::CNNData vel(::cnn_msgs::msg::CNNData::_vel_type arg)
  {
    msg_.vel = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cnn_msgs::msg::CNNData msg_;
};

class Init_CNNData_goal_final_polar
{
public:
  explicit Init_CNNData_goal_final_polar(::cnn_msgs::msg::CNNData & msg)
  : msg_(msg)
  {}
  Init_CNNData_vel goal_final_polar(::cnn_msgs::msg::CNNData::_goal_final_polar_type arg)
  {
    msg_.goal_final_polar = std::move(arg);
    return Init_CNNData_vel(msg_);
  }

private:
  ::cnn_msgs::msg::CNNData msg_;
};

class Init_CNNData_goal_cart
{
public:
  explicit Init_CNNData_goal_cart(::cnn_msgs::msg::CNNData & msg)
  : msg_(msg)
  {}
  Init_CNNData_goal_final_polar goal_cart(::cnn_msgs::msg::CNNData::_goal_cart_type arg)
  {
    msg_.goal_cart = std::move(arg);
    return Init_CNNData_goal_final_polar(msg_);
  }

private:
  ::cnn_msgs::msg::CNNData msg_;
};

class Init_CNNData_depth
{
public:
  explicit Init_CNNData_depth(::cnn_msgs::msg::CNNData & msg)
  : msg_(msg)
  {}
  Init_CNNData_goal_cart depth(::cnn_msgs::msg::CNNData::_depth_type arg)
  {
    msg_.depth = std::move(arg);
    return Init_CNNData_goal_cart(msg_);
  }

private:
  ::cnn_msgs::msg::CNNData msg_;
};

class Init_CNNData_image_gray
{
public:
  explicit Init_CNNData_image_gray(::cnn_msgs::msg::CNNData & msg)
  : msg_(msg)
  {}
  Init_CNNData_depth image_gray(::cnn_msgs::msg::CNNData::_image_gray_type arg)
  {
    msg_.image_gray = std::move(arg);
    return Init_CNNData_depth(msg_);
  }

private:
  ::cnn_msgs::msg::CNNData msg_;
};

class Init_CNNData_scan_all
{
public:
  explicit Init_CNNData_scan_all(::cnn_msgs::msg::CNNData & msg)
  : msg_(msg)
  {}
  Init_CNNData_image_gray scan_all(::cnn_msgs::msg::CNNData::_scan_all_type arg)
  {
    msg_.scan_all = std::move(arg);
    return Init_CNNData_image_gray(msg_);
  }

private:
  ::cnn_msgs::msg::CNNData msg_;
};

class Init_CNNData_scan
{
public:
  explicit Init_CNNData_scan(::cnn_msgs::msg::CNNData & msg)
  : msg_(msg)
  {}
  Init_CNNData_scan_all scan(::cnn_msgs::msg::CNNData::_scan_type arg)
  {
    msg_.scan = std::move(arg);
    return Init_CNNData_scan_all(msg_);
  }

private:
  ::cnn_msgs::msg::CNNData msg_;
};

class Init_CNNData_ped_pos_map
{
public:
  Init_CNNData_ped_pos_map()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CNNData_scan ped_pos_map(::cnn_msgs::msg::CNNData::_ped_pos_map_type arg)
  {
    msg_.ped_pos_map = std::move(arg);
    return Init_CNNData_scan(msg_);
  }

private:
  ::cnn_msgs::msg::CNNData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::cnn_msgs::msg::CNNData>()
{
  return cnn_msgs::msg::builder::Init_CNNData_ped_pos_map();
}

}  // namespace cnn_msgs

#endif  // CNN_MSGS__MSG__DETAIL__CNN_DATA__BUILDER_HPP_
