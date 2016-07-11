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

#include <differential_drive_kinematics/ForwardConfiguration.hpp>
#include <differential_drive_msgs/Velocity.hpp>
#include <differential_drive_msgs/Speeds.hpp>

namespace differential_drive_kinematics {
   class Forward:
      public Core::MW::CoreNode
   {
public:
      Forward(
         const char*                name,
         Core::MW::Thread::Priority priority = Core::MW::Thread::PriorityEnum::NORMAL
      );
      virtual
      ~Forward();

public:
      ForwardConfiguration configuration;

private:
    	

private:
      bool
      onPrepareMW();

      bool
      onLoop();

      static bool
      callback_left(
         const differential_drive_msgs::Speeds& msg,
         Core::MW::Node*                             node
      );
      static bool
            callback_right(
               const differential_drive_msgs::Speeds& msg,
               Core::MW::Node*                             node
            );



private:
      Core::MW::Subscriber<differential_drive_msgs::Speeds, 2> _subscriber_left;
      Core::MW::Subscriber<differential_drive_msgs::Speeds, 2> _subscriber_right;
      Core::MW::Publisher<differential_drive_msgs::Velocity> _publisher;
   };
}
