#pragma once

#include <core/mw/CoreMessage.hpp>

namespace core {
namespace common_msgs {

CORE_MESSAGE_BEGIN(String64) //String64
	CORE_MESSAGE_FIELD(data, CHAR, 64) // 64 bytes long string
CORE_MESSAGE_END

}
}