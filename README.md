# ROS2_RealTime-Tutorial

## Installation

Download the repo using this comand

```bash
cd ~
git clone https://github.com/FilipHesse/ROS2_Tutorial.git --recurse-submodules
```

To install the packages inside ros1_ws we will use the following command:

```bash
cd ~/ROS2_Tutorial/ros1_ws
source /opt/ros/<ros1_distro>/setup.bash
catkin_make
catkin_make_isolated --install
```
To install the packages inside ros1_ws we will use the following command:

```bash
cd ~/ROS2_Tutorial/ros2_ws
source /opt/ros/<ros2_distro>/setup.bash
colcon build --symlink-install
```

To install the package inside bridge_ws we will use the following command:

```bash
cd ~/ROS2_Tutorial
source /opt/ros/<ros1_distro>/setup.bash
source /opt/ros/<ros2_distro>/setup.bash
source ros1_ws/install_isolated/setup.bash
source ros2_ws/install/local_setup.bash
colcon build --symlink-install --packages-select ros1_bridge --cmake-force-configure
```

## Modules

### SROS Example

The SROS Example 


