cmake_minimum_required(VERSION 3.0.2)
project(tutorial_interfaces)

## Find catkin macros and libraries, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
    message_generation
)

## Generate messages in the 'msg' folder
add_message_files(
    FILES
    custom_message.msg
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

catkin_package(
    CATKIN_DEPENDS message_runtime
)

## Declare a C++ executable
# add_executable(${PROJECT_NAME}_node src/tutorial_interfaces_node.cpp)

## Add cmake target dependencies of the executable
# add_dependencies(${PROJECT_NAME}_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})