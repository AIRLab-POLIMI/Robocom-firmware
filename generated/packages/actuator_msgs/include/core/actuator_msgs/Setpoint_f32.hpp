#pragma once

#include <core/mw/CoreMessage.hpp>

namespace core {
namespace actuator_msgs {

CORE_MESSAGE_BEGIN(Setpoint_f32) //A generic setpoint
	CORE_MESSAGE_FIELD(value, FLOAT32, 1) // The value
CORE_MESSAGE_END

}
}