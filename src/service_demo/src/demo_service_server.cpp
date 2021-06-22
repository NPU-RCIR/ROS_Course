//
// Created by yuhang on 2021/6/22.
//

#include <iostream>
#include "ros/ros.h"
#include "service_demo/srv_demo.h"
#include <sstream>
using namespace std;

bool demo_service_callback(service_demo::srv_demo::Request &req, service_demo::srv_demo::Response &res) {
  std::stringstream ss;
  ss<<"Received Here";
  res.out = ss.str();
  ROS_INFO("From Client [%s], Server says [%s]", req.in.c_str(), res.out.c_str());
  return true;
}

int main (int argc, char **argv)
{
  ros::init(argc, argv, "demo_service_server");
  ros::NodeHandle nh;
  ros::ServiceServer service = nh.advertiseService("demo_service", demo_service_callback);
  ROS_INFO("Ready to receive from client.");
  ros::spin();
  return 0;
}