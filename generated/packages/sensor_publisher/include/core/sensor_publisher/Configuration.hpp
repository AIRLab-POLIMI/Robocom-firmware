#pragma once

#include <core/mw/CoreConfiguration.hpp>

namespace core {
namespace sensor_publisher {

CORE_CONFIGURATION_BEGIN(Configuration) //Sensor Publisher node configuration
// --- FIELDS -----------------------------------------------------------------
	CORE_CONFIGURATION_FIELD(topic, CHAR, 16) // Name of the topic to publish to
// ----------------------------------------------------------------------------
CORE_CONFIGURATION_SIGNATURE(0xe44fc5cb)
CORE_CONFIGURATION_LENGTH(1)
CORE_CONFIGURATION_END()

}
}
