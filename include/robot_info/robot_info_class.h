#pragma once
#include "ros/publisher.h"
#include <robotinfo_msgs/RobotInfo10Fields.h>
#include <ros/ros.h>

class RobotInfo {
private:
  // Robot info
  std::string robot_description;
  std::string serial_number;
  std::string ip_address;
  std::string firmware_version;

protected:
  // ROS publisher
  ros::Publisher robot_info_pub;
  robotinfo_msgs::RobotInfo10Fields robot_info_msg;
  std::string *msg_fields[10] = {
      &robot_info_msg.data_field_01, &robot_info_msg.data_field_02,
      &robot_info_msg.data_field_03, &robot_info_msg.data_field_04,
      &robot_info_msg.data_field_05, &robot_info_msg.data_field_06,
      &robot_info_msg.data_field_07, &robot_info_msg.data_field_08,
      &robot_info_msg.data_field_09, &robot_info_msg.data_field_10};
      
  // Default topic `/robot_info`
  std::string robot_info_topic_name = "robot_info";

public:
  // Constructor
  RobotInfo() {}
  RobotInfo(ros::NodeHandle *nh, std::string robot_description,
            std::string serial_number, std::string ip_address,
            std::string firmware_version);
  // Destructor
  ~RobotInfo();

  void generate_robot_info_msg();

  virtual void publish_data();
};