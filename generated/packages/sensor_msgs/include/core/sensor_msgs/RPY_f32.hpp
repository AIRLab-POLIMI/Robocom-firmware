#pragma once

#include <core/mw/CoreMessage.hpp>

namespace core {
namespace sensor_msgs {

CORE_MESSAGE_BEGIN(RPY_f32) //RPY Attitude (FLOAT32)
	CORE_MESSAGE_FIELD(roll, FLOAT32, 1) // roll
	CORE_MESSAGE_FIELD(pitch, FLOAT32, 1) // pitch
	CORE_MESSAGE_FIELD(yaw, FLOAT32, 1) // yaw
CORE_MESSAGE_END

}
}