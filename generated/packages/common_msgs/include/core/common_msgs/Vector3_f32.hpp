#pragma once

#include <core/mw/CoreMessage.hpp>

namespace core {
namespace common_msgs {

CORE_MESSAGE_BEGIN(Vector3_f32) //A 3D vector of FLOAT16
	CORE_MESSAGE_FIELD(x, FLOAT32, 1) // x
	CORE_MESSAGE_FIELD(y, FLOAT32, 1) // y
	CORE_MESSAGE_FIELD(z, FLOAT32, 1) // z
CORE_MESSAGE_END

}
}