#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"
#include <sound_play/sound_play.h>
#include <unistd.h>


void cmdRCCallback(const geometry_msgs::Twist::ConstPtr& cmd_RC)
{
	float linearv=cmd_RC->linear.x;
	float angularv=cmd_RC->angular.z;
	//std::cout << "Linear velocity x: "<< cmd_RC->linear.x << " \t Angular velocity z: "<< cmd_RC->angular.z << std::endl;
	ROS_INFO("Linear velocity x: [%f]",linearv);
        ROS_INFO("Angular velocity z: [%f]",angularv);
	sound_play::SoundClient sc;

	if (linearv == 0 and angularv == 0)
	{		
		sc.say("keylo. Stop..","voice_don_diphone");
		sleep(6);
	}
 	else if (linearv > 0 and angularv == 0)
	{
				
		sc.say("KEYLO. Moving. Forward.","voice_don_diphone");
		sleep(6);
	}
  	else if (linearv < 0 and angularv == 0)
	{		
		sc.say("KEYLO. Moving. Backward.","voice_don_diphone");
		sleep(6);
	}
        else if (linearv == 0 and angularv > 0)
	{			
		sc.say("KEYLO. Turning. Right.","voice_don_diphone");
		sleep(6);
	}
        else if (linearv == 0 and angularv < 0)
	{
					
		sc.say("KEYLO. Turning. Left.","voice_don_diphone");
		sleep(6);
	}

	
}
void sleepok(int t, ros::NodeHandle &nh)
{
   if (nh.ok())
   sleep(t);
}

int main(int argc, char **argv)
{
	//Initialize ROS
	ros::init(argc, argv, "listener");
        //NodeHandle is the main access point to communications with the ROS system.
	ros::NodeHandle nh;
	//Create the sound client object
        sound_play::SoundClient sc;
        sleepok(1, nh);
	// Set the default TTS voice to use
	sc.say("Ready. For. Start.","voice_don_diphone");
	//Subscribe to the /cmd_vel topic 
	ros::Subscriber sub = nh.subscribe("cmd_vel", 100, cmdRCCallback);
	
    while (ros::ok())
    {
      ros::spin();
    }

    return 0;
}







