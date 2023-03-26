#define _USE_MATH_DEFINES

#include <cmath>
#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "nav_msgs/msg/odometry.hpp"

using namespace std::chrono_literals;

double x,y,w,ang;

double x_ini,y_ini,w_ini,ang_ini,dist,dif_ang;
bool turn=false;

void odom_callback(nav_msgs::msg::Odometry::SharedPtr msg){
    
    if(turn){
        x_ini = msg->pose.pose.position.x;
        y_ini = msg->pose.pose.position.y;
        w_ini =msg->pose.pose.orientation.w;
        ang_ini=acos(w_ini)*2;
        
        
    }
    
    turn=false;
	
    x = msg->pose.pose.position.x;
    y = msg->pose.pose.position.y;
    w=msg->pose.pose.orientation.w;
    ang=acos(w)*2;
    dist=std::sqrt(std::pow((x-x_ini),2) + std::pow((y-y_ini),2));
    dif_ang=std::abs(ang-ang_ini);
    std::cout<<"X: "<<x<<std::endl;
    std::cout<<"Y: "<<y<<std::endl;
    std::cout<<"Theta: "<< ang <<std::endl;
    std::cout<<"Dist: "<<dist<<std::endl;
    std::cout<<"Diferencia de angles: "<<dif_ang<<std::endl;
}

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("publisher");
  auto publisher = node->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);
  auto subscription = node->create_subscription<nav_msgs::msg::Odometry>("odom", 10,odom_callback);
  node->declare_parameter("linear_speed",0.1);
  node->declare_parameter("angular_speed",3.1416/20);
  node->declare_parameter("square_length",1.0);
  
  
  geometry_msgs::msg::Twist message;
  nav_msgs::msg::Odometry odometry;
  rclcpp::WallRate loop_rate(10ms);
  
 
  double linear_speed = node->get_parameter("linear_speed").get_parameter_value().get<double>();
  double angular_speed = node->get_parameter("angular_speed").get_parameter_value().get<double>();
  double square_length = node->get_parameter("square_length").get_parameter_value().get<double>();
  
  for(int j=0;j<5;j++){
  for(int j=0;j<4;j++){
  	turn=true;
  	while (rclcpp::ok() && ((dist+0.001<square_length))) {
  		message.linear.x = linear_speed;
    		publisher->publish(message);
    		rclcpp::spin_some(node);
    		loop_rate.sleep();
    		dist = std::sqrt(std::pow((x-x_ini),2) + std::pow((y-y_ini),2));
  	}
  	//send zero velocity to topic
  	message.linear.x = 0.0;
  	publisher->publish(message);
  	rclcpp::spin_some(node);
  	loop_rate.sleep();
  
	
  	while (rclcpp::ok() && ((dif_ang < M_PI/2))) {
  		message.angular.z = angular_speed;
    		publisher->publish(message);
    		rclcpp::spin_some(node);
    		loop_rate.sleep();
    		dif_ang=abs(ang-ang_ini);
  	}
  	message.angular.z = 0.0;
  	publisher->publish(message);
  	rclcpp::spin_some(node);
  	loop_rate.sleep();
  	
  }
  }
  
  	
  message.linear.x = 0.0;
  message.angular.z = 0.0;
  publisher->publish(message);
  rclcpp::spin_some(node);
  loop_rate.sleep();
  rclcpp::shutdown();
  return 0;

}

