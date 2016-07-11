/* COPYRIGHT (c) 2016 Nova Labs SRL
 *
 * All rights reserved. All use of this software and documentation is
 * subject to the License Agreement located in the file LICENSE.
 */

#include <Module.hpp>

#include <differential_drive_kinematics/Inverse.hpp>
#include <Core/Utils/Math/Constants.hpp>
#include <Core/Utils/Math/Conversions.hpp>

#include <differential_drive_msgs/Velocity.hpp>
#include <actuator_msgs/Setpoint_f32.hpp>

namespace differential_drive_kinematics {
Inverse::Inverse(const char* name, Core::MW::Thread::Priority priority) :
		CoreNode::CoreNode(name, priority) {
	_workingAreaSize = 512;
}

Inverse::~Inverse() {
	teardown();
}

bool Inverse::onPrepareMW() {
	_subscriber.set_callback(Inverse::callback);

	this->subscribe(_subscriber, configuration.topicInput);
	this->advertise(_left_wheel_publisher, configuration.output_left);
	this->advertise(_right_wheel_publisher, configuration.output_right);

	return true;
}

bool Inverse::onLoop() {

	if (!this->spin(Configuration::SUBSCRIBER_SPIN_TIME)) {
	}

	return true;
}

bool Inverse::callback(const differential_drive_msgs::Velocity& msg,
		Core::MW::Node* node) {
	Inverse* _this = static_cast<Inverse*>(node);
	actuator_msgs::Setpoint_f32* left_speed;
	actuator_msgs::Setpoint_f32* right_speed;
	float v = msg.linear;
	float omega = msg.angular;

	float d = _this->configuration.distance;

	/// DO THE MATH

	if (_this->_left_wheel_publisher.alloc(left_speed)) {
		/// PUBLISH THE RESULTS
		left_speed->value = v - ((d * omega) * 0.5f);

		if (!_this->_left_wheel_publisher.publish(left_speed)) {
			return false;
		}
	}

	if (_this->_right_wheel_publisher.alloc(right_speed)) {
		/// PUBLISH THE RESULTS
		right_speed->value = v + ((d * omega) * 0.5f);

		if (!_this->_right_wheel_publisher.publish(right_speed)) {
			return false;
		}
	}

	return true;
}

}
