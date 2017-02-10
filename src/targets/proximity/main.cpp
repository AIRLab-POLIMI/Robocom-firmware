#include <ModuleConfiguration.hpp>
#include <Module.hpp>

// MESSAGES
#include <core/common_msgs/Led.hpp>

// NODES
#include <core/led/Subscriber.hpp>
#include <core/sonar_publisher/SonarNode.hpp>

// BOARD IMPL

// *** DO NOT MOVE ***
Module module;

// TYPES

// NODES
core::led::Subscriber led_subscriber("led_subscriber", core::os::Thread::PriorityEnum::LOWEST);
core::sonar_publisher::SonarNode sonars("sonar_pub", core::os::Thread::PriorityEnum::NORMAL);

// MAIN
extern "C" {
   int
   main()
   {
      module.initialize();



      // Led subscriber node
      core::led::SubscriberConfiguration led_subscriber_configuration;
      led_subscriber_configuration.topic = "led";
      led_subscriber.setConfiguration(led_subscriber_configuration);

      // sonar publisher node

      core::sonar_publisher::SonarNodeConfiguration sonar_conf;
      sonar_conf.topic = "proximity";
      sonar_conf.frequency = 50;
      sonar_conf.pulse_width = 20;
      sonars.setConfiguration(sonar_conf);

      module.add(led_subscriber);
      module.add(sonars);

      // Setup and run
      module.setup();
      module.run();

      // Is everything going well?
      for (;;) {
         if (!module.isOk()) {
            module.halt("This must not happen!");
         }

         module.keepAlive();

         core::os::Thread::sleep(core::os::Time::ms(500));
      }

      return core::os::Thread::OK;
   } // main
}
