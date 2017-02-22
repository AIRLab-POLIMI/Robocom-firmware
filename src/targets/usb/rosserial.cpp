#include "rosserial.hpp"

ros::NodeHandle nh;

const char* setpointName = "cmd_vel";
const char* twist_name = "vel";
const char* enc_name = "enc";
const char* proximity_name = "proximity";
//const char* pixy_name = "pixy";
//const char* pixy_led_name = "pixy_led";
//const char* pixy_servo_name = "pixy_servo";

const float encoderFrequency = 100;

namespace rosserial {

std::function<void(const geometry_msgs::Twist&)> RosSerialPublisher::rosCallbackTwist;
//std::function<void(const std_msgs::ColorRGBA&)> RosSerialPublisher::rosCallbackPixyColor;
//std::function<void(const triskar_msgs::PixyServo&)> RosSerialPublisher::rosCallbackPixyServo;

RosSerialPublisher::RosSerialPublisher(const char* name,
		core::os::Thread::Priority priority) :
		CoreNode::CoreNode(name, priority),
		twist_pub(twist_name, &ros_twist_msg),
		//TODO BISOGNA RIFARE MESSAGGIO PROXIMITY LATO ROS
		proximity_pub(proximity_name, &ros_proximity_msg),
		enc_pub(enc_name, &ros_enc_msg),
		setpoint_sub(setpointName, RosSerialPublisher::setpointCallback)
{
	_workingAreaSize = 1024;
	twist = false;
	//pixy = false;
	proximity = false;

	for(unsigned int i = 0; i < 3; i++)
		encoder[i] = false;
}

bool RosSerialPublisher::onPrepareMW() {
	rosCallbackTwist = std::bind(&RosSerialPublisher::setpointCallbackPrivate, this, std::placeholders::_1);

	_subscriberTwist.set_callback(twistCallback);
	subscribe(_subscriberTwist, twist_name);

	_subscriberProximity.set_callback(proximityCallback);
	subscribe(_subscriberProximity, proximity_name);

	_subscriberEncoder[0].set_callback(encoderCallback_0);
	subscribe(_subscriberEncoder[0], "encoder_right");

	_subscriberEncoder[1].set_callback(encoderCallback_1);
	subscribe(_subscriberEncoder[1], "encoder_left");

	advertise(_cmd_publisher, setpointName);
	return true;
}

bool RosSerialPublisher::twistCallback(const core::differential_drive_msgs::Velocity& msg,
			   void* node)
{
	RosSerialPublisher* tmp = static_cast<RosSerialPublisher*>(node);


	tmp->ros_twist_msg.angular.z = msg.angular;
	tmp->ros_twist_msg.angular.x = 0;
	tmp->ros_twist_msg.angular.y = 0;

	tmp->ros_twist_msg.linear.x = msg.linear;
	tmp->ros_twist_msg.linear.y = 0;
	tmp->ros_twist_msg.linear.z = 0;

	tmp->twist = true;

	return true;
}


bool RosSerialPublisher::proximityCallback(const core::sensor_msgs::Proximity& msg,
				   void* node)
{
	RosSerialPublisher* tmp = static_cast<RosSerialPublisher*>(node);

	for(unsigned int i = 0; i < 8; i++)
		tmp->ros_proximity_msg.range[i] = msg.value[i];


	tmp->proximity = true;

	return true;
}

bool RosSerialPublisher::encoderCallback_0(const core::sensor_msgs::Delta_f32& msg,
				   void* node)
{
	RosSerialPublisher* tmp = static_cast<RosSerialPublisher*>(node);

	tmp->ros_enc_msg.x = msg.value;


	tmp->encoder[0] = true;

	return true;
}

bool RosSerialPublisher::encoderCallback_1(const core::sensor_msgs::Delta_f32& msg,
					   void* node)
{
	RosSerialPublisher* tmp = static_cast<RosSerialPublisher*>(node);

	tmp->ros_enc_msg.y = msg.value;


	tmp->encoder[1] = true;

	return true;
}


void RosSerialPublisher::setpointCallback(const geometry_msgs::Twist& setpoint_msg)
{
	rosCallbackTwist(setpoint_msg);
}


void RosSerialPublisher::setpointCallbackPrivate(const geometry_msgs::Twist& setpoint_msg)
{
	 core::differential_drive_msgs::Velocity* msgp;

	 if (_cmd_publisher.alloc(msgp))
	 {
		 // TODO qui devo cambiare messaggio e mettere messaggio solo linear angular con differential drive

		 msgp->linear = setpoint_msg.linear.x;
		 msgp->angular = setpoint_msg.angular.z;

		 _cmd_publisher.publish(*msgp);
	 }
}


bool RosSerialPublisher::onStart()
{
	nh.initNode();
	nh.advertise(twist_pub);
	// TODO DA RIAGGIUNGERE PUBLISHER DI PROXIMITY
	nh.advertise(proximity_pub);
	nh.advertise(enc_pub);

	nh.subscribe(setpoint_sub);


	nh.spinOnce();
	core::os::Thread::sleep(core::os::Time::ms(100));

	_stamp = core::os::Time::now();

	return true;
}


bool RosSerialPublisher::onLoop() {

	core::os::Thread::sleep_until(_stamp + core::os::Time::hz(100));

	if(this->spin(core::os::Time::ms(1)))
	{

		if(twist)
		{
			twist_pub.publish(&ros_twist_msg);
			twist = false;
		}

		if(proximity)
		{
			proximity_pub.publish(&ros_proximity_msg);
			proximity = false;
		}


		if(encoder[0] && encoder[1])
		{
			enc_pub.publish(&ros_enc_msg);

			for(unsigned int i = 0; i < 2; i++)
				encoder[i] = false;
		}
	}

	nh.spinOnce();

	_stamp = core::os::Time::now();


	return true;
}

}
