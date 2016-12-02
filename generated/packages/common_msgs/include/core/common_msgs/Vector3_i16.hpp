#pragma once

#include <core/mw/CoreMessage.hpp>

namespace core {
namespace common_msgs {

CORE_MESSAGE_BEGIN(Vector3_i16) //A 3D vector of INT16
	CORE_MESSAGE_FIELD(x, INT16, 1) // x
	CORE_MESSAGE_FIELD(y, INT16, 1) // y
	CORE_MESSAGE_FIELD(z, INT16, 1) // z
CORE_MESSAGE_END

}
}