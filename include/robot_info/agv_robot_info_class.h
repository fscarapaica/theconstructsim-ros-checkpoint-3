#pragma once
#include "robot_info_class.h"
#include "ros/subscriber.h"
#include <nav_msgs/Odometry.h>

class AGVRobotInfo : public RobotInfo {

  std::string maximum_payload;

public:
  AGVRobotInfo(ros::NodeHandle *nh, std::string robot_description,
               std::string serial_number, std::string ip_address,
               std::string firmware_version, std::string maximum_payload);

  void publish_data() override;
};