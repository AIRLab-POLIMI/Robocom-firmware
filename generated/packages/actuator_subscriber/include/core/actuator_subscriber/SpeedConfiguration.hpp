#pragma once

#include <core/mw/CoreConfiguration.hpp>

namespace core {
namespace actuator_subscriber {

CORE_CONFIGURATION_BEGIN(SpeedConfiguration) //Actuator speed subscriber node configuration
// --- FIELDS -----------------------------------------------------------------
	CORE_CONFIGURATION_FIELD(kp, FLOAT32, 1) // PID Gain
	CORE_CONFIGURATION_FIELD(ti, FLOAT32, 1) // Integral time
	CORE_CONFIGURATION_FIELD(td, FLOAT32, 1) // Derivative time
	CORE_CONFIGURATION_FIELD(ts, FLOAT32, 1) // Sampling time
	CORE_CONFIGURATION_FIELD(min, FLOAT32, 1) // Minimum output
	CORE_CONFIGURATION_FIELD(max, FLOAT32, 1) // Maximum output
	CORE_CONFIGURATION_FIELD(idle, FLOAT32, 1) // Default output in case of setpoint timeout
	CORE_CONFIGURATION_FIELD(timeout, INT16, 1) // Timeout for setpoint topic [ms]
	CORE_CONFIGURATION_FIELD(setpoint_topic, CHAR, 16) // Name of the setpoint topic to subscribe to
	CORE_CONFIGURATION_FIELD(encoder_topic, CHAR, 16) // Name of the encoder topic to subscribe to
// ----------------------------------------------------------------------------
CORE_CONFIGURATION_SIGNATURE(0xd9e3620f)
CORE_CONFIGURATION_LENGTH(10)
CORE_CONFIGURATION_END()

}
}
