#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <turtlesim/Spawn.h>

ros::Publisher second_turtle_pub;

void turtleCmdVelCallback(const geometry_msgs::Twist::ConstPtr& msg) {
  geometry_msgs::Twist second_turtle_cmd_vel;
  second_turtle_cmd_vel.linear.x = -msg->linear.x;
  second_turtle_cmd_vel.angular.z = -msg->angular.z;

  second_turtle_pub.publish(second_turtle_cmd_vel);
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "move_second_turtle");
  ros::NodeHandle nh;

  // Subscriber 
  ros::Subscriber cmd_vel_sub = nh.subscribe("turtle1/cmd_vel", 1000, turtleCmdVelCallback);

  // Publisher 
  second_turtle_pub = nh.advertise<geometry_msgs::Twist>("second_turtle/cmd_vel", 1000);

  // spawn nueva tortuga
  ros::ServiceClient spawnClient = nh.serviceClient<turtlesim::Spawn>("spawn");
 
  turtlesim::Spawn::Request req;
  turtlesim::Spawn::Response resp;
//acomodar spawn
  req.x = 5.5;  
  req.y = 5.5;  
  req.theta = 0.0; 
  req.name = "second_turtle";  

  if (spawnClient.call(req, resp)) {
    ROS_INFO("Spawned a new turtle: [%s]", resp.name.c_str());
  } else {
    ROS_ERROR("Failed to spawn a new turtle");
    return 1;
  }


  ros::spin();

  return 0;
}
