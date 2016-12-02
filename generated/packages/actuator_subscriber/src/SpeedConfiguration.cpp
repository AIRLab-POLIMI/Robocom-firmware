#include <core/actuator_subscriber/SpeedConfiguration.hpp>

namespace core {
namespace actuator_subscriber {

CORE_CONFIGURATION_MAP_BEGIN(SpeedConfiguration)
	CORE_CONFIGURATION_MAP_ENTRY(SpeedConfiguration, setpoint_topic, CHAR, 16)
	CORE_CONFIGURATION_MAP_ENTRY(SpeedConfiguration, encoder_topic, CHAR, 16)
	CORE_CONFIGURATION_MAP_ENTRY(SpeedConfiguration, kp, FLOAT32, 1)
	CORE_CONFIGURATION_MAP_ENTRY(SpeedConfiguration, ti, FLOAT32, 1)
	CORE_CONFIGURATION_MAP_ENTRY(SpeedConfiguration, td, FLOAT32, 1)
	CORE_CONFIGURATION_MAP_ENTRY(SpeedConfiguration, ts, FLOAT32, 1)
	CORE_CONFIGURATION_MAP_ENTRY(SpeedConfiguration, min, FLOAT32, 1)
	CORE_CONFIGURATION_MAP_ENTRY(SpeedConfiguration, max, FLOAT32, 1)
	CORE_CONFIGURATION_MAP_ENTRY(SpeedConfiguration, timeout, INT16, 1)
	CORE_CONFIGURATION_MAP_ENTRY(SpeedConfiguration, idle, FLOAT32, 1)
CORE_CONFIGURATION_MAP_END()

}
}
