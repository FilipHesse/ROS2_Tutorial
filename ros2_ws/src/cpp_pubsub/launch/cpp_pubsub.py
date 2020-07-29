from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='cpp_pubsub',
            node_executable='A',
            node_name='A'
        ),
        Node(
            package='cpp_pubsub',
            node_executable='B',
            node_name='B'
        ),
        Node(
            package='cpp_pubsub',
            node_executable='C',
            node_name='C'
        ),

        Node(
            package='cpp_pubsub',
            node_executable='D',
            node_name='D',
            remappings = [('/D', '/D_remapped')]
        ),


    ])
