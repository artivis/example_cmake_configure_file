CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

# The project name
PROJECT(testcmake)

set(MY_VAR true)

set(MY_VALUED_VAR 2)

option(MY_BIN_VAR "ON OR OFF" ON)

list(APPEND COMPILE_OPTIONS MY_VAR)

set(CONFIG_DIR "${PROJECT_BINARY_DIR}/internal")

# Create the specified output directory if it does not exist.
if (NOT EXISTS "${CONFIG_DIR}")
  message(STATUS "Creating config output directory: ${CONFIG_DIR}")
  file(MAKE_DIRECTORY "${CONFIG_DIR}")
endif()
if (EXISTS "${CONFIG_DIR}" AND NOT IS_DIRECTORY "${CONFIG_DIR}")
  message(FATAL_ERROR "Bug: Specified CONFIG_DIR: "
    "${CONFIG_DIR} exists, but is not a directory.")
endif()

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/internal/config.h.in "${CONFIG_DIR}/config.h")

include_directories("${PROJECT_BINARY_DIR}")

ADD_EXECUTABLE(testcmake testcmake.cpp)
