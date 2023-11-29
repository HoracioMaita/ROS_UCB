// This program subscribes to turtle1/pose and shows its
// messages on the screen.
#include <ros/ros.h>
#include <turtlesim/Pose.h>
#include <iomanip> // for std::setprecision and std::fixed
#include "beginner_tutorials/distancia.h"
 
// A callback function.  Executed each time a new pose
// message arrives.
 
float X1;
float Y1;
float X2;
float Y2;
 
 
void turtlePose1(const turtlesim::Pose& msg) {
    X1 = msg.x;
    Y1 = msg.y;
}
void turtlePose2(const turtlesim::Pose& msg) {
    X2 = msg.x;
    Y2 = msg.y;
}
 
 
int main(int argc, char **argv) {
  // Initialize the ROS system and become a node.
  ros::init(argc, argv, "distance observer");
  ros::NodeHandle nh;
  // Create a subscriber object.
  ros::Subscriber sub1 = nh.subscribe("turtle1/pose", 1000, &turtlePose1);
  ros::Subscriber sub2 = nh.subscribe("turtle2/pose", 1000, &turtlePose2);
  ros::ServiceClient client = nh.serviceClient<beginner_tutorials::distancia>("calcular_distancia");
 
 
  beginner_tutorials::distancia srv;
 
 
  ros::Rate rate(0.2);
 
  while (ros::ok()) {
 
    ros::spinOnce();
 
    srv.request.x1 = X1;
    srv.request.y1 = Y1;
    srv.request.x2 = X2;
    srv.request.y2 = Y2;
 
    if (client.call(srv))
    {
      ROS_INFO("distancia: %f", srv.response.distancia);
    }
    else
    {
      ROS_ERROR("Failed to call service distance");
      return 1;
    }
 
    rate.sleep();
  }
 
  return 0;
}