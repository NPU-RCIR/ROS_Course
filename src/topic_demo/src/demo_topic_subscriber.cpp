//
// Created by yuhang on 2021/6/22.
//
#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include <iostream>
void number_callback(const std_msgs::Int32::ConstPtr& msg) {
  ROS_INFO("Received [%d]", msg->data);
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "demo_topic_subscriber");
  ros::NodeHandle nh;
  ros::Subscriber number_subscriber = nh.subscribe("/numbers", 10, number_callback);
  ros::spin();
  return 0;
}
