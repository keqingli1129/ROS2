#include "rclcpp/rclcpp.hpp"
// #include "std_msgs/msg/string.hpp"  
// #include <memory>
// #include <string>
// #include <iostream>
// using namespace std::chrono_literals;
class MyFirstNode : public rclcpp::Node
{
    public:
        MyFirstNode()
        : Node("my_first_node"), counter_(0)
        {
            RCLCPP_INFO(this->get_logger(), "Node has been created successfully.");
            timer_ = this->create_wall_timer(std::chrono::seconds(1), std::bind(&MyFirstNode::timer_callback, this));
        }
    private:
        void timer_callback()
        {
            RCLCPP_INFO(this->get_logger(), "Hello %d", counter_++);
        }

        rclcpp::TimerBase::SharedPtr timer_;
        int counter_;
};
int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<MyFirstNode>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}   

