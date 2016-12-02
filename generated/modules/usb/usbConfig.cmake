LIST( APPEND WORKSPACE_MODULES_MODULES usb )
SET( WORKSPACE_MODULES_usb_REQUIRED_PACKAGES
  common_msgs
  led
)
SET( WORKSPACE_MODULES_usb_CHIBIOS_REQUIRED_COMPONENTS
  rt
  hal
  pal
  serial
  mmc_spi
  spi
  serial_usb
  hal_buffers
  usb
  uart
  chprintf
  shell
  syscalls
)
SET( WORKSPACE_MODULES_usb_SOURCES
  ${WORKSPACE_MODULES_PATH}/usb/src/Module.cpp
  ${WORKSPACE_MODULES_PATH}/usb/src/board.c
  ${WORKSPACE_MODULES_PATH}/usb/src/usbcfg.c
)
SET( WORKSPACE_MODULES_usb_INCLUDES
  ${WORKSPACE_MODULES_PATH}/usb/include
  ${WORKSPACE_MODULES_PATH}/usb/include/usb
)
