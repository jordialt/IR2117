#include <chrono>
#include <vector>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"

using namespace std::chrono_literals;


double minl=1.5,minr=1.5,mint=1.5;
bool turn_left=false;
bool turn_right=false;


void scan_callback(sensor_msgs::msg::LaserScan::SharedPtr msg){
    auto v = msg->ranges;
    std::vector<float>  vt{};
    std::vector<float>  v1{};
    std::vector<float>  v2{};
    
    for(int i=0; i<10;i++){
        v1.push_back(v[i]);
        vt.push_back(v[i]);
    }
    for(int i=350;i<360;i++){
        v2.push_back(v[i]);
        vt.push_back(v[i]);
    }
    minl = v1[0];
    minr = v2[0];
    mint = vt[0];
    
    for(long unsigned int i=1;i<vt.size();i++) {
        if(vt[i]<mint) {
            minl=vt[i];
        }
    }

    for(long unsigned int i=1;i<v1.size();i++) {
        if(v1[i]<minl) {
            minl=v1[i];
        }
    }
    for(long unsigned int i=1;i<v2.size();i++) {
        if(v2[i]<minr) {
            minr=v2[i];
        }
    }
    
    std::cout<<"Mínimo L: "<<minl<<std::endl;
    std::cout<<"Mínimo R: "<<minr<<std::endl;

    
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
  
    if(turn_left==false && turn_right==false){
    	message.linear.x = 0.5;
    	message.angular.z = 0.0;
    	publisher->publish(message);
    	rclcpp::spin_some(node);
    	loop_rate.sleep();
    	if(mint<1.0){
    		if(minl>minr){
    			turn_left=true;
    			
    			}else{
    				turn_right=true;
    
    				}
    	}}else{
    	if(turn_left){
    		while(minl<1.0){
    			message.linear.x = 0.0;
        	message.angular.z = 0.2;
        	publisher->publish(message);
        	rclcpp::spin_some(node);
        	loop_rate.sleep();
    		}
    		turn_left=false;
    	}else{
    		while(minr<1.0){
    			message.linear.x = 0.0;
        	message.angular.z = -0.2;
        	publisher->publish(message);
        	rclcpp::spin_some(node);
        	loop_rate.sleep();
    	}
    	turn_right=false;
    }
  }
  
}
rclcpp::shutdown();
  return 0;
}

