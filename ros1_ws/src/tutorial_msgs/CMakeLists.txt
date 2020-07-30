cmake_minimum_required(VERSION 3.0.2)
project(tutorial_interfaces)

## Find catkin macros and libraries, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
    message_generation
    std_msgs
)

## Generate messages in the 'msg' folder
add_message_files(
    FILES
    CustomMessage.msg
)

## Generate services in the 'srv' folder
# add_service_files(
#   FILES
#   Service1.srv
#   Service2.srv
# )

## Generate actions in the 'action' folder
# add_action_files(
#   FILES
#   Action1.action
#   Action2.action
# )

generate_messages(
	DEPENDENCIES
	std_msgs
)

catkin_package(
    CATKIN_DEPENDS
    message_runtime
    std_msgs
)