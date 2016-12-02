LIST( APPEND WORKSPACE_MODULES_MODULES proximity )
SET( WORKSPACE_MODULES_proximity_REQUIRED_PACKAGES
  led
  common_msgs
)
SET( WORKSPACE_MODULES_proximity_CHIBIOS_REQUIRED_COMPONENTS
  rt
  hal
  ext
  icu
  pal
  syscalls
)
SET( WORKSPACE_MODULES_proximity_SOURCES
  ${WORKSPACE_MODULES_PATH}/proximity/src/Module.cpp
  ${WORKSPACE_MODULES_PATH}/proximity/src/board.c
)
SET( WORKSPACE_MODULES_proximity_INCLUDES
  ${WORKSPACE_MODULES_PATH}/proximity/include
  ${WORKSPACE_MODULES_PATH}/proximity/include/proximity
)
