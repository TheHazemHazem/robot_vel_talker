# robot_vel_talker
THE GOAL is that humans around the robot should be able to understand if and how fast the robot moves just by listening to it.  
In the directoy, we have both c++ code and python script

The code is adpted for ***ROS kinetic***

To test and evaluate the wyca_test:

1.Install the prerequisite using "wyca_test_pre.sh" // Open a terminal in wyca_test folder and run bash wyca_test_pre.sh
2.run the sound play node using "rosrun sound_play soundplay_node.py"
3.run the listener node:
******** For c++ node ********
3.1.rosrun wyca_test listener
******** For python node ********
3.1.rosrun wyca_test listener.py

4.play the test.bag using "rosbag play test.bag"
