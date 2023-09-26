#include "robot_info/robot_info_class.h"
#include "ros/init.h"
#include <ros/ros.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "robot_info_node");
  ros::NodeHandle nh;
  RobotInfo robot_info = RobotInfo(
  &nh,
  "Mir100",
  "567A359",
  "169.254.5.180",
  "3.5.8"
  );
  robot_info.publish_data();
  ros::spin();
}