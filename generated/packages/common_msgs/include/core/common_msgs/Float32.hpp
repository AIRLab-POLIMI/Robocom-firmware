#pragma once

#include <core/mw/CoreMessage.hpp>

namespace core {
namespace common_msgs {

CORE_MESSAGE_BEGIN(Float32) //A 32-bit float
	CORE_MESSAGE_FIELD(value, FLOAT32, 1) // value
CORE_MESSAGE_END

}
}