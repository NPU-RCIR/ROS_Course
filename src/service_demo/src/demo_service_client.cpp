//
// Created by yuhang on 2021/6/22.
//

#include <iostream>
#include "ros/ros.h"
#include "service_demo/srv_demo.h"
#include <sstream>
using namespace std;

int main (int argc, char **argv)
{
  ros::init(argc, argv, "demo_service_client");
  ros::NodeHandle nh;
  ros::Rate loop_rate(10);
  ros::ServiceClient client = nh.serviceClient<service_demo::srv_demo>("demo_service");
  while (ros::ok())
  {
    service_demo::srv_demo srv;
    std::stringstream ss;
    ss<<"Sending from Here";
    srv.request.in = ss.str();
    if(client.call(srv))
    {
      ROS_INFO("From Client [%s], Server says [%s]", srv.request.in.c_str(), srv.response.out.c_str());
    } else {
      ROS_ERROR("Failed to call service");
      return 1;
    }
    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}