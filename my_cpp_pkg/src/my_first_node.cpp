#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"  
#include <memory>
#include <string>
#include <iostream>
using namespace std::chrono_literals;
class MyFirstNode : public rclcpp::Node
{
    public:
    MyFirstNode()
    : Node("my_first_node")
    {
        publisher_ = this->create_publisher<std_msgs::msg::String>("my_topic", 10);
        timer_ = this->create_wall_timer(
        500ms, std::bind(&MyFirstNode::timer_callback, this));
    }
    private:
    void timer_callback()
    {
        auto message = std_msgs::msg::String();
        message.data = "Hello, ROS 2!";
        RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
        publisher_->publish(message);
    }

    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};
int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MyFirstNode>());
  rclcpp::shutdown();
  return 0;
}   

