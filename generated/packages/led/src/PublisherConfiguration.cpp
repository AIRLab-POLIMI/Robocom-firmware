#include <core/led/PublisherConfiguration.hpp>

namespace core {
namespace led {

CORE_CONFIGURATION_MAP_BEGIN(PublisherConfiguration)
	CORE_CONFIGURATION_MAP_ENTRY(PublisherConfiguration, topic, CHAR, 16)
	CORE_CONFIGURATION_MAP_ENTRY(PublisherConfiguration, led, UINT32, 1)
CORE_CONFIGURATION_MAP_END()

}
}
