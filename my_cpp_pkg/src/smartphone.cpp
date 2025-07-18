#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp"

using namespace std::placeholders;
 
class SmartphoneNode : public rclcpp::Node 
{
    public:
        SmartphoneNode() : Node("smartphone") 
        {
            subscriber_ = this->create_subscription<example_interfaces::msg::String>(
                "robot_news", 10, std::bind(&SmartphoneNode::calbackRobotNews, this, _1)
            );
            RCLCPP_INFO(this->get_logger(), "Smartphone Node has been created successfully.");
        }
    
    private:
        void calbackRobotNews(const example_interfaces::msg::String::SharedPtr msg) 
        {
            RCLCPP_INFO(this->get_logger(), "Received news: '%s'", msg->data.c_str());
        }   
        rclcpp::Subscription<example_interfaces::msg::String>::SharedPtr subscriber_;
};
    
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<SmartphoneNode>(); 
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}