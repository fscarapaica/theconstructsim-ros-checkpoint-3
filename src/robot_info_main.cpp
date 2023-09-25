#include "robot_info/robot_info_class.h"
#include "ros/init.h"
#include <ros/ros.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "robot_info_node");
  ros::NodeHandle nh;
  RobotInfo robot_info = RobotInfo(
  &nh,
  "This is my description",
  "ABC-DEF-GHI",
  "192.169.1.1",
  "ver_2.0.1-dev"
  );
  robot_info.publish_data();
  ros::spin();
}