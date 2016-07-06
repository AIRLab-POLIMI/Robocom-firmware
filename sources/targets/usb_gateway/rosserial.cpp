#define USE_USB_SERIAL 1

#include "ch.h"
#include "hal.h"
#include "usbcfg.h"

#include <Configuration.hpp>
#include <Module.hpp>
#include <Core/MW/Publisher.hpp>
#include <Core/MW/Subscriber.hpp>
#include <differential_drive_kinematics/Forward.hpp>
#include <differential_drive_kinematics/Inverse.hpp>

#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Float32.h>
#include <geometry_msgs/Twist.h>
#include <nav_msgs/Odometry.h>

struct odometry_data_t {
	float linear;
	float angular;
} odometry_data;

bool odometry_cb(const differential_drive_msgs::Velocity &msg, Core::MW::Node* node) {

	odometry_data.linear = msg.linear;
	odometry_data.angular= msg.angular;

	return true;
}
/*
 * ROS rosserial publisher thread.
 */

ros::NodeHandle nh;

float yaw = 0;
geometry_msgs::Vector3 odom_msg;

void rosserial_pub_thread(void * arg) {
	Core::MW::Node node("rosserial_pub");
	Core::MW::Subscriber<differential_drive_msgs::Velocity, 5> odometry_sub(odometry_cb);
	geometry_msgs::Twist odometry_msg;
	ros::Publisher odometry_pub("odometry", &odometry_msg);

	(void) arg;
	chRegSetThreadName("rosserial_pub");

	odom_msg.x = 0.0;
	odom_msg.y = 0.0;
	odom_msg.z = 0.0;

	node.subscribe(odometry_sub, "odometry");

	nh.initNode();
	nh.advertise(odometry_pub);

	for (;;) {
		if (node.spin(Core::MW::Time::ms(500))) {
			odometry_msg.linear.x = odometry_data.linear;
			odometry_msg.angular.z = odometry_data.angular;
			odometry_pub.publish(&odometry_msg);

			nh.spinOnce();
		}
	}
}


/*
 * ROS rosserial subscriber thread.
 */
Core::MW::Publisher<differential_drive_msgs::Velocity> velocity_pub;

void cmd_vel_cb( const geometry_msgs::Twist& cmd_vel_msg){
	differential_drive_msgs::Velocity * msgp;

	if (velocity_pub.alloc(msgp)) {
		msgp->linear = cmd_vel_msg.linear.x;
		msgp->angular = cmd_vel_msg.angular.z;
		velocity_pub.publish(*msgp);
	}
}

void rosserial_sub_thread(void * arg) {
	Core::MW::Node node("rosserial_sub", false);
	ros::Subscriber<geometry_msgs::Twist> cmd_vel_sub("cmd_vel", &cmd_vel_cb );
	(void) arg;
	chRegSetThreadName("rosserial_sub");

	node.advertise(velocity_pub, "cmd_vel");

	nh.initNode();
	nh.subscribe(cmd_vel_sub);

	for (;;) {
		nh.spinOnce();
		chThdSleepMilliseconds(5);
	}
}