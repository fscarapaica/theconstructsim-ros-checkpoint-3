#include "robot_info/agv_robot_info_class.h"
#include "robot_info/hydraulic_system_monitor.h"
#include "ros/init.h"
#include <ros/ros.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "agv_robot_info_node");
  ros::NodeHandle nh;
  AGVRobotInfo robot_info =
      AGVRobotInfo(&nh, "Mir100", "567A359", "169.254.5.180",
                   "3.5.8", "100 Kg");
  robot_info.hydraulic_system_monitor =
      HydraulicSystemMonitor("45C", "100%", "250 bar");
  robot_info.publish_data();
  ros::spin();
}