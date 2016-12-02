#include <core/QEI_driver/QEI_DeltaConfiguration.hpp>

namespace core {
namespace QEI_driver {

CORE_CONFIGURATION_MAP_BEGIN(QEI_DeltaConfiguration)
	CORE_CONFIGURATION_MAP_ENTRY(QEI_DeltaConfiguration, period, UINT16, 1)
	CORE_CONFIGURATION_MAP_ENTRY(QEI_DeltaConfiguration, ticks, FLOAT32, 1)
	CORE_CONFIGURATION_MAP_ENTRY(QEI_DeltaConfiguration, invert, UINT8, 1)
CORE_CONFIGURATION_MAP_END()

}
}
