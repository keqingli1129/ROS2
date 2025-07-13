#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from std_msgs.msg import String
class MyFirstNode(Node):
    def __init__(self):
        super().__init__('my_first_node')
        self.publisher_ = self.create_publisher(String, 'my_topic', 10)
        timer_period = 1  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.get_logger().info('MyFirstNode has been started.')

    def timer_callback(self):
        msg = String()
        msg.data = 'Hello, ROS 2!'
        self.publisher_.publish(msg)
        self.get_logger().info(f'Publishing: "{msg.data}"')
    
def main(args=None):
        rclpy.init(args=args)       
        node = MyFirstNode()
        rclpy.spin(node)  
        node.destroy_node()
        rclpy.shutdown()
        
if __name__ == '__main__':
    main()
# This code defines a simple ROS 2 node that publishes messages to a topic.
# It initializes the node, creates a publisher, and publishes a message every second.
# The node logs the messages it publishes to the console.
# Make sure to run this node in a ROS 2 environment with the necessary dependencies installed.
# To run this node, use the command: ros2 run my_py_pkg my_first_node
# Ensure that the package is built and sourced correctly before running the node.             