#pragma once

#include <core/mw/CoreMessage.hpp>

namespace core {
namespace sensor_msgs {

CORE_MESSAGE_BEGIN(Proximity) //Proximity outputs
	CORE_MESSAGE_FIELD(value, UINT16, 8) // distance in mm
CORE_MESSAGE_END

}
}