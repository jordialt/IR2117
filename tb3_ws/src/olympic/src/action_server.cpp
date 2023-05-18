#include <inttypes.h>
#include <memory>
#include "olympic_interfaces/action/rings.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "geometry_msgs/msg/twist.hpp"

using Rings = 
  olympic_interfaces::action::Rings;

using GoalHandleRings = 
  rclcpp_action::ServerGoalHandle<Rings>;
  
rclcpp::Node::SharedPtr node = nullptr;

// Callback for handling new goals. This implementation accepts all goals
rclcpp_action::GoalResponse handle_goal(
  const rclcpp_action::GoalUUID & uuid, 
  std::shared_ptr<const Rings::Goal> goal)
{
  RCLCPP_INFO(rclcpp::get_logger("server"), 
    "Got goal request for a circle with radius %.*f", 2, goal->radius); // 2 decimal places
  (void)uuid;
  return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
}

// Callback for dealing with cancellation. This implementation just tells the client it accepted the cancellation
rclcpp_action::CancelResponse handle_cancel(
  const std::shared_ptr<GoalHandleRings> goal_handle)
{
  RCLCPP_INFO(rclcpp::get_logger("server"), 
    "Got request to cancel goal");
  (void)goal_handle;
  return rclcpp_action::CancelResponse::ACCEPT;
}

// This last set of callbacks accepts a new goal and starts processing it.
void execute(const std::shared_ptr<GoalHandleRings>);

void handle_accepted(
  const std::shared_ptr<GoalHandleRings> goal_handle)
{
  std::thread{execute, goal_handle}.detach();
}

void execute(const std::shared_ptr<GoalHandleRings> goal_handle)
{
  // Action related
  RCLCPP_INFO(rclcpp::get_logger("server"), "Executing goal");
  const auto goal = goal_handle->get_goal();
  auto feedback = std::make_shared<Rings::Feedback>();
  auto result = std::make_shared<Rings::Result>();

  // Ring related
  float radius = goal->radius;  // Get the goal from the client
  
  // Print the received radius
  RCLCPP_INFO(rclcpp::get_logger("server"), "Received goal with radius: %.*f", 2, radius);

  // Set the result and send success
  result->success = true;
  goal_handle->succeed(result);
}
int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("action_server");
  auto action_server = 
    rclcpp_action::create_server<Rings>(node,
      "rings",
      handle_goal,
      handle_cancel,
      handle_accepted);
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}


