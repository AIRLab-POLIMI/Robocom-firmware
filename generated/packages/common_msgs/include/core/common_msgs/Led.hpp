#pragma once

#include <core/mw/CoreMessage.hpp>

namespace core {
namespace common_msgs {

CORE_MESSAGE_BEGIN(Led) //Status LED
	CORE_MESSAGE_FIELD(led, UINT32, 1) // Which led FIXME: messages with size smaller than sizeof(void*) fail
	CORE_MESSAGE_FIELD(value, UINT8, 1) // Value of the led
CORE_MESSAGE_END

}
}