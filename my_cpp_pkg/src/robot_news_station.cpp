#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp" 
using namespace std::chrono_literals;

class RobotNewsStationNode : public rclcpp::Node 
{
    public:
        RobotNewsStationNode() : Node("robot_news_station"), robot_name_("R2D2")
        {
            RCLCPP_INFO(this->get_logger(), "Robot News Station Node has been created successfully.");
            // Here you can add more functionality, like creating publishers or subscribers
            // For example, to publish news:
            publisher_ = this->create_publisher<example_interfaces::msg::String>("robot_news", 10);
            timer_ = this->create_wall_timer(
                0.5s,
                std::bind(&RobotNewsStationNode::publishNews, this)
            );
            // robot_name_ = "RobotNewsStation"; // You can set this to any name you want
            RCLCPP_INFO(this->get_logger(), "Robot News Station Node is ready to publish news.");
        }
    
    private:
        void publishNews()
        {
            auto msg = example_interfaces::msg::String();
            msg.data = std::string("Hi, this is ") + robot_name_ + std::string(" from Robot News Station!");
            RCLCPP_INFO(this->get_logger(), "Publishing news: '%s'", msg.data.c_str());
            publisher_->publish(msg);
        }
        std::string robot_name_;
        rclcpp::Publisher<example_interfaces::msg::String>::SharedPtr publisher_;
        rclcpp::TimerBase::SharedPtr timer_;
        // You can add more private members and methods as needed
};
 
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<RobotNewsStationNode>(); 
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}