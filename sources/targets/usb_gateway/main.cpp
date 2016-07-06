#include <Configuration.hpp>
#include <Module.hpp>
#include <Core/MW/Publisher.hpp>
// --- MESSAGES ---------------------------------------------------------------
#include <common_msgs/Led.hpp>
#include <common_msgs/Float32.hpp>
// --- NODES ------------------------------------------------------------------
#include <led/Subscriber.hpp>
#include <led/Publisher.hpp>
#include <differential_drive_kinematics/Forward.hpp>
#include <differential_drive_kinematics/Inverse.hpp>


// --- BOARD IMPL -------------------------------------------------------------

// --- MISC -------------------------------------------------------------------
#include "rosserial.hpp"

// *** DO NOT MOVE ***
Module module;

// --- NODES ------------------------------------------------------------------
led::Subscriber led_subscriber("led_subscriber", Core::MW::Thread::PriorityEnum::LOWEST);
led::Publisher  led_publisher("led_publisher");

differential_drive_kinematics::Forward forward("forward");
differential_drive_kinematics::Inverse inverse("inverse");

void
		test_publisher_node(
				void* arg
		)
		{
			common_msgs::Float32* msgp;

			Core::MW::Node node("test_pub");
			Core::MW::Publisher<common_msgs::Float32 > publisher;
			node.advertise(publisher, "speed_left");
			while(1) {
			if (publisher.alloc(msgp)) {

				msgp->value = -0.8f ;


				if (!publisher.publish(*msgp))  {
					msgp->value = 0;
				}

			}
			Core::MW::Thread::sleep(Core::MW::Time::ms(500));

			}



		}

void

	test_publisher_node2(
			void* arg
	)
	{
		differential_drive_msgs::Speeds* msgp;

		Core::MW::Node node("test_pub2");
		Core::MW::Publisher<differential_drive_msgs::Speeds > publisher;
		node.advertise(publisher, "test_speeds");
		while(1) {
			if (publisher.alloc(msgp)) {

				msgp->left = 10.0f ;
				msgp->right = 10.0f;

				if (!publisher.publish(*msgp))  {
					msgp->left = 0;
					msgp->right = 0;
				}
			}
			Core::MW::Thread::sleep(Core::MW::Time::ms(500));
		}
}

void
test_subscriber_node(
                void* arg
)
{
        common_msgs::Float32 * msgp;

        Core::MW::Node node("test_sub");
        Core::MW::Subscriber<common_msgs::Float32, 5> subscriber;
        node.subscribe(subscriber, "test_velocity");

        for (;;) {
                node.spin(Core::MW::Time::ms(1000));

                if (subscriber.fetch(msgp)) {
                        module.stream.printf("%f\r\n", msgp->value);
                        subscriber.release(*msgp);
                }
        }
}




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

		led_publisher.configuration["topic"] = "led";
		led_publisher.configuration["led"]   = (uint32_t)1;
		led_subscriber.configuration["topic"] = led_publisher.configuration["topic"];

		forward.configuration.distance = 1;
		forward.configuration.length_left = 1;
		forward.configuration.length_right = 1;
		forward.configuration.left_input = "enc_left";
		forward.configuration.right_input = "enc_right";
		forward.configuration.output = "odometry";

		inverse.configuration.distance = 1;
		inverse.configuration.length_left = 1;
		inverse.configuration.length_right = 1;
		inverse.configuration.topicInput = "cmd_vel";
		inverse.configuration.output_left = "speed_left";
		inverse.configuration.output_right = "speed_right";

		// Add nodes to the node manager (== board)...
		module.add(led_subscriber);
		module.add(led_publisher);
		module.add(forward);
		module.add(inverse);

		//Core::MW::Thread::create_heap(NULL, THD_WORKING_AREA_SIZE(2048), NORMALPRIO, test_publisher_node, nullptr);
		Core::MW::Thread::create_heap(NULL, THD_WORKING_AREA_SIZE(2048), NORMALPRIO, test_publisher_node2, nullptr);
		Core::MW::Thread::create_heap(NULL, THD_WORKING_AREA_SIZE(2048), NORMALPRIO, test_subscriber_node, nullptr);

		Core::MW::Thread::create_heap(NULL, THD_WORKING_AREA_SIZE(2048), NORMALPRIO, rosserial_pub_thread, nullptr);
		Core::MW::Thread::create_heap(NULL, THD_WORKING_AREA_SIZE(2048), NORMALPRIO, rosserial_sub_thread, nullptr);

		// ... and let's play!
		module.setup();
		module.run();

		// Is everything going well?
		for (;;) {
			if (!module.isOk()) {
				module.halt("This must not happen!");

			}

			Core::MW::Thread::sleep(Core::MW::Time::ms(500));
		}






		return Core::MW::Thread::OK;
	} // main
}
