#pragma once

#include <core/mw/CoreMessage.hpp>

namespace core {
namespace differential_drive_msgs {

CORE_MESSAGE_BEGIN(Speeds) //Speed
	CORE_MESSAGE_FIELD(left, FLOAT32, 1) // The left wheel speed
	CORE_MESSAGE_FIELD(right, FLOAT32, 1) // The right wheel speed
CORE_MESSAGE_END

}
}