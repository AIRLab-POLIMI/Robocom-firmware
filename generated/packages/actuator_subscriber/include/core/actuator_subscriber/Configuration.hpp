#pragma once

#include <core/mw/CoreConfiguration.hpp>

namespace core {
namespace actuator_subscriber {

CORE_CONFIGURATION_BEGIN(Configuration) //Actuator subscriber node configuration
// --- FIELDS -----------------------------------------------------------------
	CORE_CONFIGURATION_FIELD(topic, CHAR, 16) // Name of the topic to subscribe to
// ----------------------------------------------------------------------------
CORE_CONFIGURATION_SIGNATURE(0xa1c395b)
CORE_CONFIGURATION_LENGTH(1)
CORE_CONFIGURATION_END()

}
}
