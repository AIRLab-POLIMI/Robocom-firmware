#pragma once

#include <core/mw/CoreMessage.hpp>

namespace core {
namespace sensor_msgs {

CORE_MESSAGE_BEGIN(MagneticField) //Magnetometer measurements
	CORE_MESSAGE_FIELD(magnetic_field, FLOAT32, 3) // magnetic field measurements
CORE_MESSAGE_END

}
}