#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"

using namespace std::chrono_literals;


void scan_callback(sensor_msgs::msg::LaserScan::SharedPtr msg){
    std::cout<<msg<<std::endl;
    
}


int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("publisher");
  auto publisher = node->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);
  auto subscription = node->create_subscription<sensor_msgs::msg::LaserScan>("scan", 10,scan_callback);
  
  geometry_msgs::msg::Twist message;
  
  rclcpp::WallRate loop_rate(10ms);

  while (rclcpp::ok()) {
    message.linear.x = 0.0;
    publisher->publish(message);
    rclcpp::spin_some(node);
    loop_rate.sleep();
  }
  rclcpp::shutdown();
  return 0;
}

