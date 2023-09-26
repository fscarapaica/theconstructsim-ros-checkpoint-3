#include "../include/robot_info/robot_info_class.h"
#include <robotinfo_msgs/RobotInfo10Fields.h>
#include <ros/ros.h>

// Constructor
RobotInfo::RobotInfo(ros::NodeHandle *nh, std::string robot_description,
                     std::string serial_number, std::string ip_address,
                     std::string firmware_version) {
  // Fill Robot Info parameter
  this->robot_description = robot_description;
  this->serial_number = serial_number;
  this->ip_address = ip_address;
  this->firmware_version = firmware_version;

  // Init publisher
  robot_info_pub = nh->advertise<robotinfo_msgs::RobotInfo10Fields>(
      robot_info_topic_name, 10);
}

RobotInfo::~RobotInfo() {
  // Clear ros dependencies
  robot_info_pub.shutdown();
}

void RobotInfo::generate_robot_info_msg() {
  *msg_fields[0] = "robot_description: " + robot_description;
  *msg_fields[1] = "serial_number: " + serial_number;
  *msg_fields[2] = "ip_address: "+ ip_address;
  *msg_fields[3] = "firmware_version: "+ firmware_version;
}

void RobotInfo::publish_data() {
  generate_robot_info_msg();
  
  ros::Rate loop_rate(1); // Set a publish rate of 2 Hz
  while (ros::ok()) {
    robot_info_pub.publish(robot_info_msg);
    ros::spinOnce();
    loop_rate.sleep(); // Make sure the publish rate maintains at 2 Hz
  }
}