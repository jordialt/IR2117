#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "example_interfaces/msg/bool.hpp"

using namespace std::chrono_literals;

enum class State {FORWARD, TURN_LEFT, TURN_RIGHT}; // Define the states of the FSM

bool front_obstacle = false, left_obstacle = false, right_obstacle = false;
State current_state = State::FORWARD; // Initialize the current state as FORWARD

void callback_front(const example_interfaces::msg::Bool::SharedPtr msg)
{
    front_obstacle = msg->data;
}
void callback_left(const example_interfaces::msg::Bool::SharedPtr msg)
{
    left_obstacle = msg->data;
}
void callback_right(const example_interfaces::msg::Bool::SharedPtr msg)
{
    right_obstacle = msg->data;
}

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared("avoidance");
    auto publisher = node->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);
    auto subs_front = node->create_subscription<example_interfaces::msg::Bool>("/front/obstacle", 10, callback_front);
    auto subs_left = node->create_subscription<example_interfaces::msg::Bool>("/left/obstacle", 10, callback_left);
    auto subs_right = node->create_subscription<example_interfaces::msg::Bool>("/right/obstacle", 10, callback_right);
    geometry_msgs::msg::Twist message;
    rclcpp::WallRate loop_rate(50ms);

    while (rclcpp::ok()) {
        switch (current_state) { // Check the current state and take the appropriate action
            case State::FORWARD:
                if (front_obstacle) {
                    current_state = State::TURN_LEFT; // Update the state if there's an obstacle in front
                }
                message.linear.x = 0.2; // Move forward with a linear velocity of 0.2 m/s
                message.angular.z = 0; // Stop turning
                break;
            case State::TURN_LEFT:
                if (!front_obstacle) {
                    current_state = State::FORWARD; // Update the state if the obstacle in front is cleared
                }
                if (left_obstacle) {
                    current_state = State::TURN_RIGHT; // Update the state if there's an obstacle on the left
                }
                message.linear.x = 0; // Stop moving forward
                message.angular.z = 0.5; // Turn left with an angular velocity of 0.5 rad/s
                break;
            case State::TURN_RIGHT:
                if (!left_obstacle) {
                    current_state = State::FORWARD; // Update the state if the obstacle on the left is cleared
                }
                message.linear.x = 0; // Stop moving forward
                message.angular.z = -0.5; // Turn right with an angular velocity of -0.5 rad/s
                break;
            default:
                // This should never happen
                RCLCPP_ERROR(node->get_logger(), "Invalid state");
                break;
        }
        publisher->publish(message); // Publish the message to move the robot
        rclcpp::spin_some(node); // Process any incoming messages
        loop_rate.sleep(); // Sleep for the specified rate
    }

    rclcpp::shutdown();
    return 0;
}
