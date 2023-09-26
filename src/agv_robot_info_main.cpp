#include "robot_info/agv_robot_info_class.h"
#include "robot_info/hydraulic_system_monitor.h"
#include "ros/init.h"
#include <ros/ros.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "agv_robot_info_node");
  ros::NodeHandle nh;
  AGVRobotInfo robot_info =
      AGVRobotInfo(&nh, "This is my description", "ABC-DEF-GHI", "192.169.1.1",
                   "ver_2.0.1-dev", "2000 Kg");
  robot_info.hydraulic_system_monitor =
      HydraulicSystemMonitor("45C", "100%", "250 bar");
  robot_info.publish_data();
  ros::spin();
}