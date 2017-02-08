/* COPYRIGHT (c) 2016 Nova Labs SRL
 *
 * All rights reserved. All use of this software and documentation is
 * subject to the License Agreement located in the file LICENSE.
 */

#pragma once

#include <ModuleConfiguration.hpp>

#include <core/hw/QEI.hpp>
#include <core/utils/BasicSensor.hpp>
#include <core/QEI_driver/QEI_DeltaConfiguration.hpp>

namespace core {
namespace QEI_driver {
class QEI
{
public:
   QEI(
      core::hw::QEI& qei
   );

   virtual
   ~QEI();

public:
   bool
   probe();


public:
   core::hw::QEI& _qei;
};

class QEI_Delta:
   public core::utils::BasicSensor<ModuleConfiguration::QEI_DELTA_DATATYPE>,
   public core::mw::CoreConfigurable<core::QEI_driver::QEI_DeltaConfiguration>
{
public:
   QEI_Delta(
      const char* name,
      QEI&        device
   );

   virtual
   ~QEI_Delta();

private:
public:
   bool
   init();

   bool
   configure();

   bool
   start();

   bool
   stop();

   bool
   waitUntilReady();

   bool
   update();

   void
   get(
      DataType& data
   );


protected:
   core::os::Time _timestamp;

private:
   QEI& _device;
};
}
}
