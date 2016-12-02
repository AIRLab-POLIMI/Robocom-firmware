/* COPYRIGHT (c) 2016 Nova Labs SRL
 *
 * All rights reserved. All use of this software and documentation is
 * subject to the License Agreement located in the file LICENSE.
 */

#include <core/QEI_driver/QEI.hpp>
#include <Module.hpp>

#include <core/utils/math/Constants.hpp>

namespace core {
namespace QEI_driver {
QEI::QEI(
   core::hw::QEI& qei
) : _qei(qei) {}

QEI::~QEI()
{}

bool
QEI::probe()
{
   return true;
}       // QEI::init

QEI_Delta::QEI_Delta(
   const char* name,
   QEI&        device
) : CoreConfigurable<QEI_DeltaConfiguration>::CoreConfigurable(name),
   _timestamp(core::os::Time::IMMEDIATE),
   _device(device)
{}

QEI_Delta::~QEI_Delta()
{}

bool
QEI_Delta::init()
{
   return true;
}       // QEI::init

bool
QEI_Delta::configure()
{
   return true;
}

bool
QEI_Delta::start()
{
   CORE_ASSERT(isConfigured());

   _device._qei.enable();
   _timestamp = core::os::Time::IMMEDIATE;
   return true;
}

bool
QEI_Delta::stop()
{
   _device._qei.disable();
   return true;
}

bool
QEI_Delta::update()
{
   return true;
}       // QEI_Delta::update

void
QEI_Delta::get(
   DataType& data
)
{
   data.value = (_device._qei.getDelta() / (float)configuration().ticks) * (1000.0 / configuration().period) * (2.0f * core::utils::math::constants::pi<float>());

   if ((uint8_t)configuration().invert) {
      data.value = -data.value;
   }
}       // QEI::update

bool
QEI_Delta::waitUntilReady()
{
   // FIXME !!!!!
   /*
      if (_timestamp != core::os::Time::IMMEDIATE) {
      core::os::Thread::sleep_until(_timestamp + core::os::Time::ms(configuration.period));
      }

      _timestamp = core::os::Time::now();
    */

   chThdSleepMilliseconds((uint16_t)configuration().period);

   return true;
}
}
}
