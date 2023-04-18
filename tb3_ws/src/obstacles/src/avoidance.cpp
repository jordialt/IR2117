#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "example_interfaces/msg/bool.hpp"

enum State{
  St_1,
  St_2,
  St_3
};

State state = St_1;

using namespace std::chrono_literals;

bool front_obs=false, left_obs=false,right_obs=false;

void callback_front(const example_interfaces::msg::Bool::SharedPtr msg)
{
  front_obs=msg->data;

}

void callback_left(const example_interfaces::msg::Bool::SharedPtr msg)
{
  left_obs=msg->data;
}

void callback_right(const example_interfaces::msg::Bool::SharedPtr msg)
{
  right_obs=msg->data;
}

int main(int argc, char * argv[])
{
    rclcpp::init(argc,argv);
    auto node = rclcpp::Node::make_shared("avoidance");
    auto publisher = node->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);
    auto subs_front = node->create_subscription<example_interfaces::msg::Bool>("/front/obstacle", 10,callback_front);
    auto subs_left = node->create_subscription<example_interfaces::msg::Bool>("/left/obstacle", 10,callback_left);
    auto subs_right = node->create_subscription<example_interfaces::msg::Bool>("/right/obstacle", 10,callback_right);
    geometry_msgs::msg::Twist message;
    rclcpp::WallRate loop_rate(50ms);

    while (rclcpp::ok()){

      switch (state)
      {
      case St_1:
        /* code */
        if(front_obs){
          state=St_2;
        }
        break;
      
      case St_2:
                if(left_obs & front_obs){
                  state=St_3;
                }else if( not front_obs){
                  state=St_1;
                }
                break;
      case St_3:
                if (not front_obs){
                  state=St_1;
                }
                break;

      }
      if (state==St_1){
        message.linear.x = 0.5;
        message.angular.z = 0;
      } else if(state==St_2) {
        message.linear.x = 0;
        message.angular.z = 0.5;
      }else if ( state==St_3){
        message.linear.x = 0;
        message.angular.z = -0.5;
      }
      publisher->publish(message);
      rclcpp::spin_some(node);
      loop_rate.sleep();
    
    }
    rclcpp::shutdown();
    return 0;
}