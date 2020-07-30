cmake_minimum_required(VERSION 3.0.2)
project(tutorial_cpp)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS
	roscpp
	std_msgs
	genmsg
	tutorial_msgs)

## Declare a catkin package
catkin_package()

## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS} ${tutorial_msgs_INCLUDE_DIRS})

add_executable(talker src/talker.cpp)
target_link_libraries(talker ${catkin_LIBRARIES})

add_executable(listener src/listener.cpp)
target_link_libraries(listener ${catkin_LIBRARIES})

## Build ros_bridge example node
add_executable(ros_bridge_1 src/ros_bridge.cpp)
add_dependencies(ros_bridge_1 ${catkin_EXPORTED_TARGETS})
target_link_libraries(ros_bridge_1 ${catkin_LIBRARIES})