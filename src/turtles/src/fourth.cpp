#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <iostream>






int main(int argc, char** argv)
{

	ros::init(argc, argv, "turtle_runner");    //노드이름은 turtle_runner

	double starttime, VEL_MSG,  finaltime,  runtime,  distance;

	ros::NodeHandle su; //노드핸들 선언, 핸들 이름 su

	ros::Publisher pubname = su.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 100);   //퍼블리셔 이름은 pubname

	geometry_msgs::Twist velocity;

	ros::Rate rate(100);   

		ROS_INFO("VELOCITY?");
		std::cin>>VEL_MSG;

		ROS_INFO("distance?");
		std::cin>>distance;


	while(ros::ok())
	{

		
	starttime = ros::Time::now().toSec();
	runtime = distance / VEL_MSG;
	finaltime = starttime + runtime;

		//오른쪽으로 이동
		while(ros::Time::now().toSec() <= finaltime)
		{		
			velocity.linear.x = VEL_MSG;
			velocity.linear.y = 0;
			pubname.publish(velocity);
			ros::spinOnce();
		}

	starttime = ros::Time::now().toSec();
	runtime = distance / VEL_MSG;
	finaltime = starttime + runtime;

		//위쪽으로 이동
		while(ros::Time::now().toSec() <= finaltime)
		{
		velocity.linear.x = 0;
		velocity.linear.y = VEL_MSG;
		pubname.publish(velocity);
		ros::spinOnce();
		}

	starttime = ros::Time::now().toSec();
	runtime = distance / VEL_MSG;
	finaltime = starttime + runtime;

		//왼쪽으로 이동
		while(ros::Time::now().toSec() <= finaltime)
		{
		velocity.linear.x = -VEL_MSG;
		velocity.linear.y = 0;
		pubname.publish(velocity);
		ros::spinOnce();
		}

	starttime = ros::Time::now().toSec();
	runtime = distance / VEL_MSG;
	finaltime = starttime + runtime;


		//아래쪽으로 이동
		while(ros::Time::now().toSec() <= finaltime)
		{
		velocity.linear.x = 0;
		velocity.linear.y = - VEL_MSG;	
		pubname.publish(velocity);
		ros::spinOnce();
		}

		//브레이크
		velocity.linear.x = 0;
		velocity.linear.y = 0;
		pubname.publish(velocity);
		ros::spinOnce();
	
	 
		rate.sleep();


	}
	return 0;


}


