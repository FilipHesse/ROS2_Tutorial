#!/usr/bin/env python3
import rospy
from tutorial_msgs.msg import CustomMessage
from random import seed
from random import randint

def ros_bridge():
    seed(1)
    pub = rospy.Publisher('classification', CustomMessage, queue_size=10)
    rospy.init_node('ros_bridge_1', anonymous=True)
    rate = rospy.Rate(10) # 10hz
    classes = ["Apple", "Banana", "Watermelon"]
    while not rospy.is_shutdown():
        msg = CustomMessage()
        msg.class_name = classes[randint(0, 2)];
        msg.confidence = float(randint(0, 10000))/100.0;
        msg.bounding_box_coords[0] = randint(0, 125);
        msg.bounding_box_coords[1] = randint(0, 125);
        msg.bounding_box_coords[2] = randint(0, 125) + 125;
        msg.bounding_box_coords[3] = randint(0, 125) + 125;
        pub.publish(msg)
        rate.sleep()

if __name__ == '__main__':
    try:
        ros_bridge()
    except rospy.ROSInterruptException:
        pass
