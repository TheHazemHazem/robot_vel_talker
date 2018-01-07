#!/usr/bin/env python
import roslib
import rospy
from std_msgs.msg import String
from geometry_msgs.msg import Twist
from sound_play.libsoundplay import SoundClient
import sys


def callback(cmd_RC):
    #rospy.loginfo("Received a /cmd_vel message!")

    linearv=cmd_RC.linear.x
    angularv=cmd_RC.angular.z
    rospy.loginfo("Linear velocity x: [%f]"%(linearv))
    rospy.loginfo("Angular velocity x: [%f]"%(angularv))

    if linearv == 0 and angularv == 0:
	soundhandle.say("keylo. Stop.", voice)
	rospy.sleep(6)
    elif linearv > 0 and angularv == 0:
	soundhandle.say("KEYLO. Moving. Forward.", voice)
	rospy.sleep(6)
    elif linearv < 0 and angularv == 0:
	soundhandle.say("KEYLO. Moving. Backward.", voice)
	rospy.sleep(1)
    elif linearv == 0 and angularv > 0:
	soundhandle.say("KEYLO. Turning. Right.", voice)
	rospy.sleep(6)
    elif linearv == 0 and angularv < 0:
	soundhandle.say("KEYLO. Turning. Left.", voice)
	rospy.sleep(6)
'''
    while True:
        angularv1=angularv
        linearv1=linearv
        linearv=cmd_RC.linear.x
        angularv=cmd_RC.angular.z
        rospy.loginfo("Linear velocity x: [%f]"%(linearv))
        rospy.loginfo("Angular velocity x: [%f]"%(angularv))	   
        if linearv1 <> linearv or angularv1 <> angularv:
	   break
'''

def listener():
    #Initialize ROS
    rospy.init_node('listener', anonymous=True)
    # The start message
    soundhandle.say("Ready. For. Start.", voice)
    rospy.sleep(5)
    #Subscribe to the /cmd_vel topic
    rospy.Subscriber("/cmd_vel", Twist, callback)

    # spin() simply keeps python from exiting until this node is stopped
    rospy.spin()


if __name__ == '__main__':
    # Set the default TTS voice to use
    voice = rospy.get_param("~voice", "voice_don_diphone")
    #Create the sound client object
    soundhandle = SoundClient()
    listener()
