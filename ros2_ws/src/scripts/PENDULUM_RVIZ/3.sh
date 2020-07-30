source ~/ROS2_Tutorial/ros2_ws/install/local_setup.bash
export LC_NUMERIC="en_US.UTF-8" # Make sure that your locales are correctly setup.
ros2 run rviz2 rviz2 -d `ros2 pkg prefix pendulum_bringup --share`/config/pendulum.rviz