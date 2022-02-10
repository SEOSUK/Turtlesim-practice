/*#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <iostream>


int main(int argc, char** argv)
{
	ros::init(argc, argv, "turtle_runner");
    geometry_msgs::Twist velocity;
   	ros::NodeHandle su; //노드핸들 선언, 핸들 이름 su 
    ros::Publisher pubname = su.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 100);   



	double VEL_MSG, starttime, finaltime, runtime, distance;



	ros::Rate rate(8);   

	while(ros::ok())
	{

	ROS_INFO("VELOCITY?");
		std::cin>>VEL_MSG;


	ROS_INFO("distance?");
		std::cin>>VEL_MSG;



		starttime = ros::Time::now().toSec();
		runtime = distance / VEL_MSG;
		finaltime = starttime + runtime;


			while(ros::Time::now().toSec() <= finaltime)
				{
			velocity.linear.x = VEL_MSG;
			pubname.publish(velocity);
			ros::spinOnce();
				}

		starttime = ros::Time::now().toSec();
		runtime = distance / VEL_MSG;
		finaltime = starttime + runtime;


			while(ros::Time::now().toSec() <= starttime + 1)
				{
			velocity.angular.z = 3.141592/4;
			pubname.publish(velocity);
			ros::spinOnce();
				}



	rate.sleep();

	}
	return 0;


}
*/





#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <iostream>






int main(int argc, char** argv)
{

	ros::init(argc, argv, "turtle_runner");    //노드이름은 turtle_runner

	/*double starttime, VEL_MSG;*/

	ros::NodeHandle su; //노드핸들 선언, 핸들 이름 su

	ros::Publisher pubname = su.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 100);   //퍼블리셔 이름은 pubname

	geometry_msgs::Twist velocity;

	ros::Rate rate(100);   




	/*ROS_INFO("VELOCITY?");
		std::cin>>VEL_MSG;
*/


	while(ros::ok())
	{
		velocity.linear.x = 4;
		velocity.linear.y = 0;
		velocity.angular.z = 3.141592/2;
		pubname.publish(velocity);
		ros::spinOnce();
	}


/*
	starttime = ros::Time::now().toSec();

		//오른쪽으로 이동
        while(ros::Time::now().toSec() <= starttime + 1)
		{
		velocity.linear.x = VEL_MSG;
		velocity.linear.y = 0;
		pubname.publish(velocity);
		ros::spinOnce();
		}

	starttime = ros::Time::now().toSec();

        while(ros::Time::now().toSec() <= starttime + 1)
		{		
		velocity.angular.z = 3.141592/2;
		pubname.publish(velocity);
		ros::spinOnce();
		}


	starttime = ros::Time::now().toSec();


		//위쪽으로 이동
        while(ros::Time::now().toSec() <= starttime + 1)
		{
		velocity.angular.z = 0;		
		pubname.publish(velocity);
		ros::spinOnce();
		}

	starttime = ros::Time::now().toSec();

        while(ros::Time::now().toSec() <= starttime + 1)
		{		
		velocity.angular.z = 3.141592/2;
		pubname.publish(velocity);
		ros::spinOnce();
		}


	starttime = ros::Time::now().toSec();


		//왼쪽으로 이동
        while(ros::Time::now().toSec() <= starttime + 1)
		{
		velocity.angular.z = 0;		
		pubname.publish(velocity);
		ros::spinOnce();
		}

	starttime = ros::Time::now().toSec();

        while(ros::Time::now().toSec() <= starttime + 1)
		{
		velocity.angular.z = 3.141592/2;
		pubname.publish(velocity);
		ros::spinOnce();
		}		



	starttime = ros::Time::now().toSec();


		//아래쪽으로 이동
        while(ros::Time::now().toSec() <= starttime + 1)
		{
		velocity.angular.z = 0;			
		pubname.publish(velocity);
		ros::spinOnce();
		}
		
	starttime = ros::Time::now().toSec();


        while(ros::Time::now().toSec() <= starttime + 1)
		{		
		velocity.angular.z = 3.141592/2;
		pubname.publish(velocity);
		ros::spinOnce();
		}	

        while(ros::Time::now().toSec() <= starttime + 1)
		{
		velocity.angular.z = 0;			
		pubname.publish(velocity);
		ros::spinOnce();
		}					

		//브레이크
		velocity.linear.x = 0;
		velocity.angular.z = 0;				
		pubname.publish(velocity);
		ros::spinOnce();
	
	 
		rate.sleep();


	}
	*/
	return 0;


}