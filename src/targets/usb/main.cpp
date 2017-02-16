#include <ModuleConfiguration.hpp>
#include <Module.hpp>

// --- MESSAGES ---------------------------------------------------------------
#include <core/common_msgs/Led.hpp>

// --- NODES ------------------------------------------------------------------
#include <core/led/Subscriber.hpp>
#include <core/led/Publisher.hpp>
#include <core/differential_drive_kinematics/Inverse.hpp>
#include <core/differential_drive_kinematics/Forward.hpp>
#include "rosserial.hpp"

// --- BOARD IMPL -------------------------------------------------------------

// --- MISC -------------------------------------------------------------------

// *** DO NOT MOVE ***
Module module;

// --- NODES ------------------------------------------------------------------
core::led::Subscriber led_subscriber("led_subscriber", core::os::Thread::PriorityEnum::LOWEST);
core::led::Publisher  led_publisher("led_publisher");
core::differential_drive_kinematics::Inverse inverse("inverse", core::os::Thread::PriorityEnum::NORMAL);
core::differential_drive_kinematics::Forward forward("inverse", core::os::Thread::PriorityEnum::NORMAL);
rosserial::RosSerialPublisher rosSerialPublisher("rosserial",core::os::Thread::PriorityEnum::NORMAL);
/*
 * Application entry point.
 */
extern "C" {
   int
   main(
      void
   )
   {
      module.initialize();

      // Led publisher node
      core::led::PublisherConfiguration led_publisher_configuration;
      led_publisher_configuration.topic = "led";
      led_publisher_configuration.led   = 1;
      led_publisher.setConfiguration(led_publisher_configuration);

      // Led subscriber node
      core::led::SubscriberConfiguration led_subscriber_configuration;
      led_subscriber_configuration.topic = "led";
      led_subscriber.setConfiguration(led_subscriber_configuration);

      // Kinematics
      core::differential_drive_kinematics::InverseConfiguration inv_conf;
      inv_conf.distance = 0.45f;
      inv_conf.left_radius = 0.3;
      inv_conf.right_radius = 0.3f;
      inv_conf.velocity_input = "cmd_vel";
      inv_conf.left_output = "speed_left";
      inv_conf.right_output = "speed_right";
      inverse.setConfiguration(inv_conf);

      core::differential_drive_kinematics::ForwardConfiguration for_conf;
      for_conf.distance = 0.45f;
      for_conf.left_radius = 0.3;
      for_conf.right_radius = 0.3f;
      for_conf.left_input = "encoder_left";
      for_conf.right_input = "encoder_right";
      for_conf.output = "vel";
      forward.setConfiguration(for_conf);
      // Add nodes to the node manager (== board)...
      module.add(inverse);
      module.add(forward);
      module.add(led_subscriber);
      module.add(led_publisher);
      module.add(rosSerialPublisher);

      // ... and let's play!
      module.setup();
      module.run();

      // Is everything going well?
      for (;;) {
         if (!module.isOk()) {
            module.halt("This must not happen!");
         }

         core::os::Thread::sleep(core::os::Time::ms(500));
      }

      return core::os::Thread::OK;
   } // main
}
