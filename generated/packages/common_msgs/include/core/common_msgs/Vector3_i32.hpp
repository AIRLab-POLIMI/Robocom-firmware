#pragma once

#include <core/mw/CoreMessage.hpp>

namespace core {
namespace common_msgs {

CORE_MESSAGE_BEGIN(Vector3_i32) //A 3D vector of INT32
	CORE_MESSAGE_FIELD(x, INT32, 1) // x
	CORE_MESSAGE_FIELD(y, INT32, 1) // y
	CORE_MESSAGE_FIELD(z, INT32, 1) // z
CORE_MESSAGE_END

}
}