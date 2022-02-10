#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <iostream>
#include <stdlib.h>




//움직임에 관한 함수입니다
void move(double x_axis, double y_axis, double distance)
{
ros::NodeHandle su;
ros::Publisher pubname = su.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 100);   
geometry_msgs::Twist velocity;
  //여기까지 기본 ROS 선언



		double starttime, finaltime,  runtime ; 


		starttime = ros::Time::now().toSec();
		runtime = distance / abs(x_axis + y_axis);
		finaltime = starttime + runtime;
        // 시작시간, 끝시간 사이의 시간 간격을 거리/속도로 지정



			velocity.linear.x = x_axis;
			velocity.linear.y = y_axis;

			while(ros::Time::now().toSec() <= finaltime)
				{

			pubname.publish(velocity);
			ros::spinOnce();
				}
}




int main(int argc, char** argv)
{
	ros::init(argc, argv, "turtle_runner");
	ros::NodeHandle su; //노드핸들 선언, 핸들 이름 su



	double VEL_MSG, distance;


	ros::Rate rate(100);   


	ROS_INFO("VELOCITY?");
		std::cin>>VEL_MSG;

	ROS_INFO("distance?");
		std::cin>>distance;		


	while(ros::ok())
	{
	
	move(VEL_MSG, 0, distance);

	move(0, VEL_MSG, distance);

	move(-VEL_MSG, 0, distance);

	move(0, -VEL_MSG, distance);


	rate.sleep();

	}
	return 0;


}

