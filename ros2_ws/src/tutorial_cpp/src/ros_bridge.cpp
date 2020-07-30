#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "tutorial_interfaces/msg/custom_message.hpp"
using std::placeholders::_1;

class ROS1Subscriber : public rclcpp::Node
{
  public:
    ROS1Subscriber()
    : Node("ros_bridge_2")
    {
      subscription_ = this->create_subscription<tutorial_interfaces::msg::CustomMessage>(
      "topic", 10, std::bind(&ROS1Subscriber::class_callback, this, _1));
    }

  private:
    void class_callback(const tutorial_interfaces::msg::CustomMessage::SharedPtr msg) const
    {
      RCLCPP_INFO(this->get_logger(), "Class detected: '%s'", msg->class_name.c_str());
    }
    rclcpp::Subscription<tutorial_interfaces::msg::CustomMessage>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ROS1Subscriber>());
  rclcpp::shutdown();
  return 0;
}