cmake_minimum_required(VERSION 3.28)

project("subnet-ipv4"
  VERSION "0.0.1"
  DESCRIPTION ""
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD            17)
set(CMAKE_CXX_STANDARD_REQUIRED   ON)
set(CMAKE_CXX_EXTENSIONS          OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON) #REM: Could help linting

set(CMAKE_INSTALL_PREFIX
  ${CMAKE_SOURCE_DIR}/install/${PROJECT_NAME}/${PROJECT_VERSION}
  CACHE PATH "CMake install prefix" FORCE)

set(FETCHCONTENT_BASE_DIR
  ${CMAKE_SOURCE_DIR}/.repo/fetchcontent/${CMAKE_GENERATOR})

set(__PROJECT_1ST_LVL_GROUP  learn-cpp)
set(__PROJECT_2ND_LVL_GROUP  poc)
string(REGEX REPLACE "[-.]" "_" __SANITIZE_PROJECT_1ST_LVL_GROUP ${__PROJECT_1ST_LVL_GROUP})
string(REGEX REPLACE "[-.]" "_" __SANITIZE_PROJECT_2ND_LVL_GROUP ${__PROJECT_2ND_LVL_GROUP})
string(REGEX REPLACE "[-.]" "_" __SANITIZE_PROJECT_NAME          ${PROJECT_NAME})
set(__PROJECT_PKG_DIR           ${__SANITIZE_PROJECT_1ST_LVL_GROUP}/${__SANITIZE_PROJECT_2ND_LVL_GROUP}/${__SANITIZE_PROJECT_NAME})
set(__PROJECT_ID                ${PROJECT_NAME}-${PROJECT_VERSION})
set(__TARGET_APP                ${__PROJECT_ID}-app)
set(__TARGET_CORE               ${__PROJECT_ID}-core) #REM: Lib
set(__TARGET_UNIT_TEST          ${__PROJECT_ID}-unit-test)
set(__TARGET_INTEGRATION_TEST   ${__PROJECT_ID}-integration-test)

if(CMAKE_CONFIGURATION_TYPES)
  message(STATUS "::: Multi-Config Generator: (${CMAKE_GENERATOR})")
  message(STATUS "::: CMake Configuration Types: [${CMAKE_CONFIGURATION_TYPES}]")
else()
  message(STATUS "::: Single-Config Generator: (${CMAKE_GENERATOR})")
  if(NOT CMAKE_BUILD_TYPE)
    message(WARNING "::: (CMAKE_BUILD_TYPE) not specified ---> defaulting to (Debug)")
    set(CMAKE_BUILD_TYPE "Debug"
      CACHE STRING "CMake Configuration Type (build-type)" FORCE)
  endif()
  message(STATUS "::: CMAKE_BUILD_TYPE: (${CMAKE_BUILD_TYPE})")
endif()

list(APPEND CMAKE_MODULE_PATH
  ${CMAKE_SOURCE_DIR}/script/cmake)
include(FetchContent)

# enable_testing()

add_subdirectory(src/main)
if(BUILD_TESTING)
  add_subdirectory(src/test)
endif()