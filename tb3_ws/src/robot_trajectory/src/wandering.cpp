#include <chrono>
#include <vector>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"

using namespace std::chrono_literals;


double min=1.5;


void scan_callback(sensor_msgs::msg::LaserScan::SharedPtr msg){
    auto v = msg->ranges;
    std::vector<float>  vx{};
    
    for(int i=0; i<10;i++)
        vx.push_back(v[i]);
    
    for(int i=350;i<360;i++)
        vx.push_back(v[i]);
    
    min = vx[0];
    for(long unsigned int i=1;i<vx.size();i++) {
        if(vx[i]<min) {
            min=vx[i];
        }
    }
    
    std::cout<<"Mínimo: "<<min<<std::endl;

    
}


int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("publisher");
  auto publisher = node->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);
  auto subscription = node->create_subscription<sensor_msgs::msg::LaserScan>("scan", 10,scan_callback);
  
  geometry_msgs::msg::Twist message;
  
  rclcpp::WallRate loop_rate(10ms);

  while (rclcpp::ok() && min>1.0) {
    message.linear.x = 0.6;
    publisher->publish(message);
    rclcpp::spin_some(node);
    loop_rate.sleep();
  }
  message.linear.x = 0.0;
  publisher->publish(message);
  rclcpp::spin_some(node);
  loop_rate.sleep();
  rclcpp::shutdown();
  return 0;
}

