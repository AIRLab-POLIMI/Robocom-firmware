#pragma once

#include <core/mw/CoreConfiguration.hpp>

namespace core {
namespace led {

CORE_CONFIGURATION_BEGIN(PublisherConfiguration) //LED Publisher node configuration
// --- FIELDS -----------------------------------------------------------------
	CORE_CONFIGURATION_FIELD(led, UINT32, 1) // Which led
	CORE_CONFIGURATION_FIELD(topic, CHAR, 16) // Name of the topic to publish to
// ----------------------------------------------------------------------------
CORE_CONFIGURATION_SIGNATURE(0x63466e50)
CORE_CONFIGURATION_LENGTH(2)
CORE_CONFIGURATION_END()

}
}
