#include <ros/ros.h>
#include <turtlesim/Pose.h>
#include <iostream>

void where_callback(const turtlesim::Pose& now)
{

		ROS_INFO("x axis : %lf, y axis : %lf", now.x, now.y);
}






int main(int argc, char **argv)
{
	ros::init(argc, argv, "turtle_Pose");    

	ros::NodeHandle uk;


	ros::Subscriber subname = uk.subscribe("/turtle1/pose", 1000, where_callback);  

	ros::spin();

	return 0;
}