#pragma once

#include <core/mw/CoreConfiguration.hpp>

namespace core {
namespace A4957_driver {

CORE_CONFIGURATION_BEGIN(A4957_SignMagnitudeConfiguration) //A4957_SignMagnitudeConfiguration
// --- FIELDS -----------------------------------------------------------------
	CORE_CONFIGURATION_FIELD(frequency, UINT32, 1) // Frequency [Hz]
	CORE_CONFIGURATION_FIELD(period, UINT32, 1) // PWM Period (in clock cycles)
// ----------------------------------------------------------------------------
CORE_CONFIGURATION_SIGNATURE(0x79519786)
CORE_CONFIGURATION_LENGTH(2)
CORE_CONFIGURATION_END()

}
}
