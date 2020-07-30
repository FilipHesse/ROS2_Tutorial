cd ~
mkdir -p store
export ROS_SECURITY_ROOT_DIRECTORY=~/store
export ROS_SECURITY_ENABLE=true
export ROS_SECURITY_STRATEGY=Enforce
export ROS_DOMAIN_ID=10
ros2 security create_keystore store
ros2 security create_key store /talker
ros2 run demo_nodes_cpp talker