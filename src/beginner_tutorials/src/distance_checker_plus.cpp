
#include <ros/ros.h>
//The srv class for the service.
#include <turtlesim/Spawn.h>
#include "beginner_tutorials/distancia.h"
#include <cmath>
 
bool calcularDistancia(beginner_tutorials::distancia::Request  &req,
                       beginner_tutorials::distancia::Response &res)
{
    double X1 = req.x1;
    double Y1 = req.y1;
    double X2 = req.x2;
    double Y2 = req.y2;
 
    double distancia = std::sqrt(std::pow(X2 - X1, 2) + std::pow(Y2 - Y1, 2));
    res.distancia = distancia;
    return true;
}
 
int main(int argc, char **argv){
 
    ros::init(argc, argv, "spawn_turtle_calculate_distance");
    ros::NodeHandle nh;
 
//Create a client object for the spawn cd service. This
//needs to know the data type of the service and its name.
    ros::ServiceClient spawnClient = nh.serviceClient<turtlesim::Spawn>("spawn");
    ros::ServiceServer service = nh.advertiseService("calcular_distancia", calcularDistancia);
 
//Create the request and response objects.
    turtlesim::Spawn::Request req;
    turtlesim::Spawn::Response resp;
 
 
    req.x = 5.5;
    req.y = 5.5;
    req.theta = 0;
    req.name = "turtle2";
 
    ros::service::waitForService("spawn", ros::Duration(5));
    bool success = spawnClient.call(req,resp);
 
    if(success){
    ROS_INFO_STREAM("Spawned a turtle named "
            << resp.name);
    }else{
    ROS_ERROR_STREAM("Failed to spawn.");
    }
 
    ros::spin();
    return 0;
 
 
}
 