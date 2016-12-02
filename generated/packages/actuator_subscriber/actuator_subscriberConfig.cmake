LIST( APPEND WORKSPACE_PACKAGES_MODULES actuator_subscriber )
SET( WORKSPACE_PACKAGES_actuator_subscriber_SOURCES
  ${WORKSPACE_PACKAGES_PATH}/actuator_subscriber/src/Configuration.cpp
  ${WORKSPACE_PACKAGES_PATH}/actuator_subscriber/src/SpeedConfiguration.cpp
)
SET( WORKSPACE_PACKAGES_actuator_subscriber_INCLUDES
  ${WORKSPACE_PACKAGES_PATH}/actuator_subscriber/include
)
