#include <core/actuator_subscriber/Configuration.hpp>

namespace core {
namespace actuator_subscriber {

CORE_CONFIGURATION_MAP_BEGIN(Configuration)
	CORE_CONFIGURATION_MAP_ENTRY(Configuration, topic, CHAR, 16)
CORE_CONFIGURATION_MAP_END()

}
}
