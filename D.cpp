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
#include <string>
#include <iostream>
#include <boost/lexical_cast.hpp>// for lexical_cast()
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

//#include "geometry_msgs/msg/posestamped.hpp"
using std::placeholders::_1;
using namespace std::chrono_literals;


std::string msgA, msgB, msgC;


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

        publisher_ = this->create_publisher<std_msgs::msg::String>("D", 10);
        timer_ = this->create_wall_timer(500ms, std::bind(&Subscriber_Publisher::timer_callback, this));

}

private:
void topic_callbackA(const std_msgs::msg::String::SharedPtr msg) const
{
        RCLCPP_INFO(this->get_logger(), "FROM: [A]: '%s'", msg->data.c_str());
        msgA=msg->data;
}
void topic_callbackB(const std_msgs::msg::String::SharedPtr msg) const
{
        RCLCPP_INFO(this->get_logger(), "FROM:[B]: '%s'", msg->data.c_str());
        msgB=msg->data;
}
void topic_callbackC(const std_msgs::msg::String::SharedPtr msg) const
{
        RCLCPP_INFO(this->get_logger(), "FROM:[C]: '%s'", msg->data.c_str());
        msgC=msg->data;
}

//creating 3 subscriptions
rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_A;
rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_B;
rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_C;



//creating piblisher and callback to intialize messages
void timer_callback()
{
        auto message = std_msgs::msg::String();

        message.data = "I heard:" + msgA + msgB +  msgC;

        RCLCPP_INFO(this->get_logger(), "Publishing: '%s' '%s' '%s'", msgA, msgB, msgC);

        publisher_->publish(message); //here you actually publish the message
}
rclcpp::TimerBase::SharedPtr timer_;
rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
size_t count_;


};

int main(int argc, char * argv[])
{
        rclcpp::init(argc, argv);
        rclcpp::spin(std::make_shared<Subscriber_Publisher>());
        rclcpp::shutdown();
        return 0;
}
