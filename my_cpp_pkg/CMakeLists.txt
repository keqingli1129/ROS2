cmake_minimum_required(VERSION 3.8)
project(my_cpp_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(example_interfaces REQUIRED)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

add_executable(my_cpp_node src/my_first_node.cpp)
ament_target_dependencies(my_cpp_node
  rclcpp
)
add_executable(robot_news_station src/robot_news_station.cpp)
ament_target_dependencies(robot_news_station
  rclcpp
  example_interfaces
)

add_executable(smartphone src/smartphone.cpp)
ament_target_dependencies(smartphone
  rclcpp
  example_interfaces  
)
install(TARGETS
  my_cpp_node
  robot_news_station
  smartphone
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
