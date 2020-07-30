# ROS2_Tutorial

## Tutorial Files
You can follow the tutorial [here](doc/ROS2_Tutorial.pdf).

## Installation

Clone the repo:

```bash
cd ~
git clone https://github.com/FilipHesse/ROS2_Tutorial.git --recurse-submodules
```

Build the packages inside ros1_ws:

```bash
cd ~/ROS2_Tutorial/ros1_ws
source /opt/ros/<ros1_distro>/setup.bash
catkin_make
catkin_make_isolated --install
```
Build the packages inside ros1_ws:

```bash
cd ~/ROS2_Tutorial/ros2_ws
source /opt/ros/<ros2_distro>/setup.bash
colcon build --symlink-install
```

Build the ros1_bridge package inside bridge_ws:

```bash
cd ~/ROS2_Tutorial
source /opt/ros/<ros1_distro>/setup.bash
source /opt/ros/<ros2_distro>/setup.bash
source ros1_ws/install_isolated/setup.bash
source ros2_ws/install/local_setup.bash
cd bridge_ws
colcon build --symlink-install --packages-select ros1_bridge --cmake-force-configure
```

## Covered Subjects:

 1. Introduction
 2. ROS2 Basic Elements
 3. ROS2 Application Managment
 4. Hands on: Create a basic Publisher and Subscriber
 5. Building and compiling nodes
 6. ROS Bridge
 7. Real Time
 8. SROS


