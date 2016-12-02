LIST( APPEND WORKSPACE_MODULES_MODULES dc )
SET( WORKSPACE_MODULES_dc_REQUIRED_PACKAGES
  common_msgs
  led
  A4957_driver
  actuator_msgs
  actuator_subscriber
  QEI_driver
  sensor_msgs
  sensor_publisher
)
SET( WORKSPACE_MODULES_dc_CHIBIOS_REQUIRED_COMPONENTS
  rt
  hal
  adc
  ext
  pal
  pwm
  serial
  uart
  syscalls
  chprintf
)
SET( WORKSPACE_MODULES_dc_SOURCES
  ${WORKSPACE_MODULES_PATH}/dc/src/Module.cpp
  ${WORKSPACE_MODULES_PATH}/dc/src/board.c
  ${WORKSPACE_MODULES_PATH}/dc/src/qei.c
  ${WORKSPACE_MODULES_PATH}/dc/src/qei_lld.c
)
SET( WORKSPACE_MODULES_dc_INCLUDES
  ${WORKSPACE_MODULES_PATH}/dc/include
  ${WORKSPACE_MODULES_PATH}/dc/include/dc
)
