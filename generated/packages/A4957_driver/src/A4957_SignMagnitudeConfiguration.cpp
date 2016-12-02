#include <core/A4957_driver/A4957_SignMagnitudeConfiguration.hpp>

namespace core {
namespace A4957_driver {

CORE_CONFIGURATION_MAP_BEGIN(A4957_SignMagnitudeConfiguration)
	CORE_CONFIGURATION_MAP_ENTRY(A4957_SignMagnitudeConfiguration, frequency, UINT32, 1)
	CORE_CONFIGURATION_MAP_ENTRY(A4957_SignMagnitudeConfiguration, period, UINT32, 1)
CORE_CONFIGURATION_MAP_END()

}
}
