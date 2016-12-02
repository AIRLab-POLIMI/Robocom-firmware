#pragma once

#include <core/mw/CoreMessage.hpp>

namespace core {
namespace sensor_msgs {

CORE_MESSAGE_BEGIN(Delta_f32) //A generic difference of something
	CORE_MESSAGE_FIELD(value, FLOAT32, 1) // Delta
CORE_MESSAGE_END

}
}