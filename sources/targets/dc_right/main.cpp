#include <Configuration.hpp>
#include <Module.hpp>

// --- MESSAGES ---------------------------------------------------------------
#include <common_msgs/Led.hpp>
#include <actuator_msgs/Setpoint_f32.hpp>

// --- NODES ------------------------------------------------------------------
#include <sensor_publisher/Publisher.hpp>
#include <actuator_subscriber/Subscriber.hpp>
#include <actuator_subscriber/Speed.hpp>
#include <led/Subscriber.hpp>

// --- BOARD IMPL -------------------------------------------------------------
#include <QEI_driver/QEI.hpp>
#include <A4957_driver/A4957.hpp>

// *** DO NOT MOVE ***
Module module;

// --- TYPES ------------------------------------------------------------------
using QEI_Publisher = sensor_publisher::Publisher<Configuration::QEI_DELTA_DATATYPE>;
using PWM_Subscriber = actuator_subscriber::Subscriber<float, actuator_msgs::Setpoint_f32>;
using Speed_Subscriber = actuator_subscriber::Speed<float, actuator_msgs::Setpoint_f32>;

// --- NODES ------------------------------------------------------------------
led::Subscriber led_subscriber("led_subscriber",
		Core::MW::Thread::PriorityEnum::LOWEST);

QEI_Publisher encoder("encoder", module.qei,
		Core::MW::Thread::PriorityEnum::NORMAL);
PWM_Subscriber motor_pwm("actuator_sub", module.hbridge_pwm,
		Core::MW::Thread::PriorityEnum::NORMAL);
Speed_Subscriber motor_speed("actuator_sub", module.hbridge_pwm,
		Core::MW::Thread::PriorityEnum::NORMAL);

// --- MAIN -------------------------------------------------------------------
extern "C" {
int main() {
	module.initialize();

	// Module configuration
	module.qei.configuration.period = 50.0f;
	module.qei.configuration.ticks = 48.0f * 3.0f * 3.14f;

	// Nodes configuration
	led_subscriber.configuration["topic"] = "led";
	encoder.configuration["topic"] = "enc_right";
	motor_pwm.configuration["topic"] = "pwm_right";

	motor_speed.configuration.encoder_topic = encoder.configuration.topic;
	motor_speed.configuration.setpoint_topic = "speed_right";
	motor_speed.configuration.idle = 0.0f;
	motor_speed.configuration.kp = 0.0077f;
	motor_speed.configuration.ti = 0.016f;
	motor_speed.configuration.td = 0.0f;
	motor_speed.configuration.ts = module.qei.configuration.period / 1000.0f;
	motor_speed.configuration.max = 1.0f;
	motor_speed.configuration.min = -1.0f;
	motor_speed.configuration.timeout = 1000.0f;

#if 0
	//Must set PID parameters
	speed_pid.configuration.setpoint_topic = "speed_right";
	speed_pid.configuration.measure_topic = "enc_right";
	speed_pid.configuration.output_topic = "pwm_right";

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

	//Core::MW::Thread::create_heap(NULL, THD_WORKING_AREA_SIZE(2048), NORMALPRIO, sp, nullptr);

	// Add nodes to the node manager (== board)...
	module.add(led_subscriber);
	module.add(encoder);
	module.add(motor_speed);
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
