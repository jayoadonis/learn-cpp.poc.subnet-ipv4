add_library(${__TARGET_CORE} SHARED)

target_compile_features(${__TARGET_CORE}
  PUBLIC cxx_std_17)

target_compile_options(${__TARGET_CORE}
  PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>>:
      -Wall;-Wextra;-Wpedantic>
    $<$<CXX_COMPILER_ID:MSVC>:
      /Wall;/W3;/W4;/permissive->)

file(GLOB_RECURSE __target_core_src_cxx CONFIGURE_DEPENDS
  ${CMAKE_CURRENT_SOURCE_DIR}/cpp/${__PROJECT_PKG_DIR}/core/*.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/cpp/${__PROJECT_PKG_DIR}/core/*.cxx
  ${CMAKE_CURRENT_SOURCE_DIR}/cpp/${__PROJECT_PKG_DIR}/core/*.cc)

list(FILTER ${__target_core_src_cxx}
  EXCLUDE REGEX "main\\.(cpp|cxx)$")

target_sources(${__TARGET_CORE} PRIVATE ${__target_core_src_cxx})

target_include_directories(${__TARGET_CORE}
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/private
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/public>
    $<INSTALL_INTERFACE:include>)

string(TOLOWER ${CMAKE_CXX_COMPILER_ID} __cmake_cxx_compiler_id_tolower)
string(TOLOWER ${CMAKE_SYSTEM_NAME} __cmake_system_name)
set_target_properties(${__TARGET_CORE}
  PROPERTIES
    OUTPUT_NAME ${__TARGET_CORE}-$<LOWER_CASE:$<CONFIG>>-${__cmake_cxx_compiler_id_tolower}-${__cmake_system_name})

install(
  DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/public/${__SANITIZE_PROJECT_1ST_LVL_GROUP}
  DESTINATION include
  COMPONENT core)

# #REM: Should be static (at configure time)
# get_target_property(__OUTPUT_NAME ${__TARGET_CORE} OUTPUT_NAME)
# if(NOT __OUTPUT_NAME)
#   set(__OUTPUT_NAME ${__TARGET_CORE}) #REM: Fallback
# endif()
install(
  TARGETS ${__TARGET_CORE}
  EXPORT ${__TARGET_CORE}-targets
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include
  COMPONENT core)

install(
  EXPORT ${__TARGET_CORE}-targets
  FILE ${__TARGET_CORE}-targets.cmake
  NAMESPACE ${__SANITIZE_PROJECT_1ST_LVL_GROUP}::${__SANITIZE_PROJECT_2ND_LVL_GROUP}::
  DESTINATION lib/cmake
  COMPONENT core)

add_custom_target(build-target-core
  COMMENT "::: Build: (${__TARGET_CORE})"
  DEPENDS ${__TARGET_CORE})