/* COPYRIGHT (c) 2016 Nova Labs SRL
 *
 * All rights reserved. All use of this software and documentation is
 * subject to the License Agreement located in the file LICENSE.
 */

#pragma once

#include <Core/MW/Publisher.hpp>
#include <Core/MW/Subscriber.hpp>
#include <Core/MW/CoreNode.hpp>
#include <Core/MW/CoreSensor.hpp>
#include <Core/MW/Callback.hpp>

#include <Configuration.hpp>

#include <differential_drive_kinematics/InverseConfiguration.hpp>
#include <differential_drive_msgs/Velocity.hpp>
#include <actuator_msgs/Setpoint_f32.hpp>

namespace differential_drive_kinematics {
   class Inverse:
      public Core::MW::CoreNode
   {
public:
      Inverse(
         const char*                name,
         Core::MW::Thread::Priority priority = Core::MW::Thread::PriorityEnum::NORMAL
      );
      virtual
      ~Inverse();

public:
      InverseConfiguration configuration;

private:
    	

private:
      bool
      onPrepareMW();

      bool
      onLoop();

      static bool
      callback(
         const differential_drive_msgs::Velocity& msg,
         Core::MW::Node*                             node
      );



private:
      Core::MW::Subscriber<differential_drive_msgs::Velocity, 5> _subscriber;
      Core::MW::Publisher<actuator_msgs::Setpoint_f32> _left_wheel_publisher;
      Core::MW::Publisher<actuator_msgs::Setpoint_f32> _right_wheel_publisher;
   };
}
