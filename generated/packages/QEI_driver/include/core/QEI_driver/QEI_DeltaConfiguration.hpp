#pragma once

#include <core/mw/CoreConfiguration.hpp>

namespace core {
namespace QEI_driver {

CORE_CONFIGURATION_BEGIN(QEI_DeltaConfiguration) //QEI_Delta
// --- FIELDS -----------------------------------------------------------------
	CORE_CONFIGURATION_FIELD(ticks, FLOAT32, 1) // Number of ticks per revolution
	CORE_CONFIGURATION_FIELD(period, UINT16, 1) // Update period [ms]
	CORE_CONFIGURATION_FIELD(invert, UINT8, 1) // Invert rotation direction
// ----------------------------------------------------------------------------
CORE_CONFIGURATION_SIGNATURE(0x10112029)
CORE_CONFIGURATION_LENGTH(3)
CORE_CONFIGURATION_END()

}
}
