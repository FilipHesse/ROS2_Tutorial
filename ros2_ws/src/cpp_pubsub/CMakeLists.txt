cmake_minimum_required(VERSION 3.5)
project(cpp_pubsub)

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
find_package(geometry_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)




add_executable(A src/A.cpp)
ament_target_dependencies(A rclcpp std_msgs)

add_executable(B src/B.cpp)
ament_target_dependencies(B rclcpp std_msgs)

add_executable(C src/C.cpp)
ament_target_dependencies(C rclcpp std_msgs)

add_executable(D src/D.cpp)
ament_target_dependencies(D rclcpp std_msgs geometry_msgs)

ament_export_dependencies(rosidl_default_runtime)


install(TARGETS
  A
  B
  C
  D
  DESTINATION lib/${PROJECT_NAME})

ament_package()
