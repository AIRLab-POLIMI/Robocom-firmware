#include <core/led/SubscriberConfiguration.hpp>

namespace core {
namespace led {

CORE_CONFIGURATION_MAP_BEGIN(SubscriberConfiguration)
	CORE_CONFIGURATION_MAP_ENTRY(SubscriberConfiguration, topic, CHAR, 16)
CORE_CONFIGURATION_MAP_END()

}
}
