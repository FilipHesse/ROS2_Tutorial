cmake_minimum_required(VERSION 3.0.2)
project(tutorial_py)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  rospy
  std_msgs
  tutorial_msgs
)

catkin_package()

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(${catkin_INCLUDE_DIRS}
	${tutorial_msgs_INCLUDE_DIRS}
)