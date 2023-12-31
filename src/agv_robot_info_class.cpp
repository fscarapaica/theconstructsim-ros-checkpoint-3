#include "robot_info/agv_robot_info_class.h"
#include "../include/robot_info/robot_info_class.h"
#include <robotinfo_msgs/RobotInfo10Fields.h>
#include <ros/ros.h>
#include <vector>

AGVRobotInfo::AGVRobotInfo(ros::NodeHandle *nh, std::string robot_description,
                           std::string serial_number, std::string ip_address,
                           std::string firmware_version,
                           std::string maximum_payload)
    : RobotInfo(nh, robot_description, serial_number, ip_address,
                firmware_version) {
  this->maximum_payload = maximum_payload;
}

void AGVRobotInfo::publish_data() {
  generate_robot_info_msg();
  std::vector<std::pair<std::string, std::string>>::iterator itr;
  std::vector<std::pair<std::string, std::string>> hydraulic_monitor_magnitudes =
      hydraulic_system_monitor.getHydraulicMonitorMagnitudes();

  int index = 4;
  *msg_fields[index] = "maximum_payload: " + maximum_payload;
  for (itr = hydraulic_monitor_magnitudes.begin();
       itr != hydraulic_monitor_magnitudes.end(); ++itr) {
    *msg_fields[++index] = itr->first + ": " + itr->second;
  }

  ros::Rate loop_rate(1);
  while (ros::ok()) {
    robot_info_pub.publish(robot_info_msg);
    ros::spinOnce();
    loop_rate.sleep();
  }
}