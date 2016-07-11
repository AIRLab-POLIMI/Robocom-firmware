/* COPYRIGHT (c) 2016 Nova Labs SRL
 *
 * All rights reserved. All use of this software and documentation is
 * subject to the License Agreement located in the file LICENSE.
 */

#include <Module.hpp>

#include <differential_drive_kinematics/Forward.hpp>
#include <Core/Utils/Math/Constants.hpp>
#include <Core/Utils/Math/Conversions.hpp>

#include <differential_drive_msgs/Velocity.hpp>
#include <differential_drive_msgs/Speeds.hpp>

namespace differential_drive_kinematics {
   Forward::Forward(
      const char*                name,
      Core::MW::Thread::Priority priority
   ) :
      CoreNode::CoreNode(name, priority)
   {
      _workingAreaSize = 512;
   }

   Forward::~Forward()
   {
      teardown();
   }

   bool
   Forward::onPrepareMW()
   {
		_subscriber_left.set_callback(Forward::callback_left);
		_subscriber_right.set_callback(Forward::callback_right);

		this->subscribe(_subscriber_left, configuration.left_input);
		this->subscribe(_subscriber_left, configuration.right_input);
		this->advertise(_publisher, configuration.output);

		return true;
   }

   bool
   Forward::onLoop()
   {


         if (!this->spin(Configuration::SUBSCRIBER_SPIN_TIME)) {
         }

   
     
      return true;
   }

   bool
   Forward::callback_left(
      const differential_drive_msgs::Speeds& msg,
      Core::MW::Node*                             node
   )
   {
      Forward* _this = static_cast<Forward*>(node);
      differential_drive_msgs::Velocity* velocity;

      float spleft = msg.left;
      float spright = msg.right;



   if (_this->_publisher.alloc(velocity)) {
            /// PUBLISH THE RESULTS
	      velocity->angular = (spright - spleft) * 0.5f;
	      velocity->linear = (spright + spleft) * 0.5f;

            if (!_this->_publisher.publish(velocity)) {
               return false;
            }
         }
      return true;
   }

   bool
   Forward::callback_right(
      const differential_drive_msgs::Speeds& msg,
      Core::MW::Node*                             node
   )
   {
      Forward* _this = static_cast<Forward*>(node);
      differential_drive_msgs::Velocity* velocity;

      float spleft = msg.left;
      float spright = msg.right;



   if (_this->_publisher.alloc(velocity)) {
            /// PUBLISH THE RESULTS
	      velocity->angular = (spright - spleft) * 0.5f;
	      velocity->linear = (spright + spleft) * 0.5f;

            if (!_this->_publisher.publish(velocity)) {
               return false;
            }
         }
      return true;
   }
}
