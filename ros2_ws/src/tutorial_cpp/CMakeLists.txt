cmake_minimum_required(VERSION 3.5)
project(tutorial_cpp)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(tutorial_msgs REQUIRED)

add_executable(talker src/talker.cpp)
ament_target_dependencies(talker rclcpp std_msgs)

add_executable(listener src/listener.cpp)
ament_target_dependencies(listener rclcpp std_msgs)

add_executable(ros_bridge_2 src/ros_bridge.cpp)
ament_target_dependencies(ros_bridge_2 rclcpp tutorial_msgs)

install(TARGETS
  talker
  listener
  ros_bridge_2
  DESTINATION lib/${PROJECT_NAME})

ament_package()
