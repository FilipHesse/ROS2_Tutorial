#include "ros/ros.h"
#include <tutorial_msgs/CustomMessage.h>

#include <ctime>

int main(int argc, char **argv) {
	srand((unsigned) time(0));

	ros::init(argc, argv, "ros_bridge_1");
	ros::NodeHandle nh;

	ros::Publisher classifier_pub = nh.advertise<tutorial_msgs::CustomMessage>("classification", 1000);

	ros::Rate loop_rate(10);

	std::string classes[3] = {"Apple", "Banana", "Watermelon"};

	int i;

	while(ros::ok()){
		tutorial_msgs::CustomMessage msg;

		i = rand() % 3;
		msg.class_name = classes[i];

		msg.confidence = static_cast<float>(rand()) / static_cast<float>(RAND_MAX/100);
		for(i = 0; i < 4; i++){
			msg.bounding_box_coords[0] = rand() % 125;
			msg.bounding_box_coords[1] = rand() % 125;
			msg.bounding_box_coords[2] = (rand() % 125) + 125;
			msg.bounding_box_coords[3] = (rand() % 125) + 125;
		}

		classifier_pub.publish(msg);

		ros::spinOnce();
    	loop_rate.sleep();
	}

	return 0;
}