#include <core/sensor_publisher/Configuration.hpp>

namespace core {
namespace sensor_publisher {

CORE_CONFIGURATION_MAP_BEGIN(Configuration)
	CORE_CONFIGURATION_MAP_ENTRY(Configuration, topic, CHAR, 16)
CORE_CONFIGURATION_MAP_END()

}
}
