// Copyright 2016 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <memory>
#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

//#include "geometry_msgs/msg/posestamped.hpp"
using std::placeholders::_1;

class Subscriber_Publisher : public rclcpp::Node
{
public:
Subscriber_Publisher()
        : Node("D")
{
        subscription_A = this->create_subscription<std_msgs::msg::String>(
                "A", 10, std::bind(&Subscriber_Publisher::topic_callbackA, this, _1));
        subscription_B = this->create_subscription<std_msgs::msg::String>(
                "B", 10, std::bind(&Subscriber_Publisher::topic_callbackB, this, _1));
        subscription_C = this->create_subscription<std_msgs::msg::String>(
                "C", 10, std::bind(&Subscriber_Publisher::topic_callbackC, this, _1));

}

private:
void topic_callbackA(const std_msgs::msg::String::SharedPtr msg) const
{
        RCLCPP_INFO(this->get_logger(), "FROM: [A]: '%s'", msg->data.c_str());
}
void topic_callbackB(const std_msgs::msg::String::SharedPtr msg) const
{
        RCLCPP_INFO(this->get_logger(), "FROM:[B]: '%s'", msg->data.c_str());
}
void topic_callbackC(const std_msgs::msg::String::SharedPtr msg) const
{
        RCLCPP_INFO(this->get_logger(), "FROM:[C]: '%s'", msg->data.c_str());
}

rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_A;
rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_B;
rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_C;


};

int main(int argc, char * argv[])
{
        rclcpp::init(argc, argv);
        rclcpp::spin(std::make_shared<Subscriber_Publisher>());
        rclcpp::shutdown();
        return 0;
}
