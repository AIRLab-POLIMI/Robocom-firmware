#pragma once

#include <core/mw/CoreMessage.hpp>

namespace core {
namespace differential_drive_msgs {

CORE_MESSAGE_BEGIN(Velocity) //A velocity setpoint
	CORE_MESSAGE_FIELD(linear, FLOAT32, 1) // The linear velocity
	CORE_MESSAGE_FIELD(angular, FLOAT32, 1) // The angular velocity
CORE_MESSAGE_END

}
}