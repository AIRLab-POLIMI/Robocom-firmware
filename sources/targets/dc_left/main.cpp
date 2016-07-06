#include <Configuration.hpp>
#include <Module.hpp>

// --- MESSAGES ---------------------------------------------------------------
#include <common_msgs/Led.hpp>
#include <actuator_msgs/Setpoint_f32.hpp>
#include <pid/PIDNode.hpp>

// --- NODES ------------------------------------------------------------------
#include <sensor_publisher/Publisher.hpp>
#include <actuator_subscriber/Subscriber.hpp>
#include <led/Subscriber.hpp>

// --- BOARD IMPL -------------------------------------------------------------
#include <QEI_driver/QEI.hpp>
#include <A4957_driver/A4957.hpp>

// *** DO NOT MOVE ***
Module module;

// --- TYPES ------------------------------------------------------------------
using QEI_Publisher = sensor_publisher::Publisher<Configuration::QEI_DELTA_DATATYPE>;
using PWM_Subscriber = actuator_subscriber::Subscriber<float, actuator_msgs::Setpoint_f32>;

// --- NODES ------------------------------------------------------------------
led::Subscriber led_subscriber("led_subscriber",
		Core::MW::Thread::PriorityEnum::LOWEST);

QEI_Publisher encoder("encoder", module.qei,
		Core::MW::Thread::PriorityEnum::NORMAL);
PWM_Subscriber motor("actuator_sub", module.hbridge_pwm,
		Core::MW::Thread::PriorityEnum::NORMAL);

pid::PIDNode speed_pid("pid", Core::MW::Thread::PriorityEnum::NORMAL);
PID speed_pidz;

/*
 * PID node
 */

struct pid_conf {
	float k;
	float ti;
	float td;
	float ts;
};

bool enc_callback(const sensor_msgs::Delta_f32& msg, Core::MW::Node* node) {

	float pwm = speed_pidz.update(msg.value);
	module.hbridge_pwm.set(pwm);

	return true;
}

void sp(void * arg) {
	Core::MW::Node node("sp");
	Core::MW::Publisher<common_msgs::Float32> speed_pub;
	node.advertise(speed_pub, "speed_left");

	while (1) {
		common_msgs::Float32* msgp;

		if (speed_pub.alloc(msgp)) {
			msgp->value = 10.0;
			speed_pub.publish(msgp);
		}
		Core::MW::Thread::sleep(Core::MW::Time::ms(500));
	}
}

void pid_node(void * arg) {
	pid_conf * conf = reinterpret_cast<pid_conf *>(arg);
	Core::MW::Node node("pid");
	Core::MW::Subscriber<common_msgs::Float32, 5> speed_sub;
	Core::MW::Subscriber<sensor_msgs::Delta_f32, 5> enc_sub(enc_callback);
	common_msgs::Float32 * msgp;
	Core::MW::Time last_setpoint(0);

	(void) arg;
	chRegSetThreadName("pid");

	speed_pidz.config(conf->k, conf->ti, conf->td, conf->ts, -1.0, 1.0);

	node.subscribe(speed_sub, "speed_left");
	node.subscribe(enc_sub, "enc_left");

	module.hbridge_pwm.start();
	for (;;) {
		if (node.spin(Core::MW::Time::ms(1000))) {
			if (speed_sub.fetch(msgp)) {
				speed_pidz.set(msgp->value);
				last_setpoint = Core::MW::Time::now();
				speed_sub.release(*msgp);
			} else if (Core::MW::Time::now() - last_setpoint
					> Core::MW::Time::ms(1000)) {
				speed_pidz.set(0);
			}
		} else {
			speed_pidz.set(0);
		}
	}
	module.hbridge_pwm.stop();
}

// --- MAIN -------------------------------------------------------------------
extern "C" {
int main() {
	module.initialize();

	// Module configuration
	module.qei.configuration.period = 50;
	module.qei.configuration.ticks = 48.0f * 3.0f * 3.14f;

	// Nodes configuration
	led_subscriber.configuration["topic"] = "led";
	encoder.configuration["topic"] = "enc_left";
	motor.configuration["topic"] = "pwm_left";
#if 0
	//Must set PID parameters
	speed_pid.configuration.setpoint_topic = "speed_left";
	speed_pid.configuration.measure_topic = "enc_left";
	speed_pid.configuration.output_topic = "pwm_left";

	speed_pid.configuration.kp = 0.2;//PID Gain
	speed_pid.configuration.ti = 0.0;//Integral time
	speed_pid.configuration.td = 0.0;//Derivative time
	speed_pid.configuration.ts = 0.05;//Sampling time
	speed_pid.configuration.min = -1.0;//Minmum output
	speed_pid.configuration.max = 1.0;//Maximum ouput
	speed_pid.configuration.timeout = 0;//Timeout for setpoint
	speed_pid.configuration.idle = 0;//Default output in case of setpoint timeout2
#endif
#if 0
	module.hbridge_pwm.start();
	float x = 0;
	while(1) {
		x = 0.0f;
		module.hbridge_pwm.set(x);
		Core::MW::Thread::sleep(Core::MW::Time::ms(500));
		x = 0.85;
		module.hbridge_pwm.set(x);
		Core::MW::Thread::sleep(Core::MW::Time::ms(500));
		x = 0.0f;
		module.hbridge_pwm.set(x);
		Core::MW::Thread::sleep(Core::MW::Time::ms(500));
	}
#endif

/// CONFIGURE ME!!!
	pid_conf pid_conf = { 0.2, 0, 0, 0.01 };

	Core::MW::Thread::create_heap(NULL, THD_WORKING_AREA_SIZE(2048),
			NORMALPRIO + 1, pid_node, &pid_conf);
	//Core::MW::Thread::create_heap(NULL, THD_WORKING_AREA_SIZE(2048), NORMALPRIO, sp, nullptr);

	// Add nodes to the node manager (== board)...
	module.add(led_subscriber);
	module.add(encoder);
	// module.add(motor);
	// module.add(speed_pid);

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
