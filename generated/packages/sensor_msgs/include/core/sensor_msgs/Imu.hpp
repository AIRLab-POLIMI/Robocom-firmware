#pragma once

#include <core/mw/CoreMessage.hpp>

namespace core {
namespace sensor_msgs {

CORE_MESSAGE_BEGIN(Imu) //Imu outputs
	CORE_MESSAGE_FIELD(orientation, FLOAT32, 4) // quaternion orientaton
	CORE_MESSAGE_FIELD(angular_velocity, FLOAT32, 3) // angular velocities
	CORE_MESSAGE_FIELD(linear_acceleration, FLOAT32, 3) // linear accelerations
CORE_MESSAGE_END

}
}