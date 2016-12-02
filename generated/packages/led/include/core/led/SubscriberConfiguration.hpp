#pragma once

#include <core/mw/CoreConfiguration.hpp>

namespace core {
namespace led {

CORE_CONFIGURATION_BEGIN(SubscriberConfiguration) //LED Subscriber node configuration
// --- FIELDS -----------------------------------------------------------------
	CORE_CONFIGURATION_FIELD(topic, CHAR, 16) // Name of the topic to subscribe to
// ----------------------------------------------------------------------------
CORE_CONFIGURATION_SIGNATURE(0xcc416f1b)
CORE_CONFIGURATION_LENGTH(1)
CORE_CONFIGURATION_END()

}
}
