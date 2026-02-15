add_executable(${__TARGET_APP})

target_compile_features(${__TARGET_APP} PUBLIC cxx_std_17)

target_compile_options(${__TARGET_APP}
  PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>>:
      -Wall;-Wextra;-Wpedantic>
    $<$<CXX_COMPILER_ID:MSVC>:
      /Wall;/W3;/W4;/permissive->
)

file(GLOB_RECURSE __target_app_src_cxx CONFIGURE_DEPENDS
  ${CMAKE_CURRENT_SOURCE_DIR}/cpp/${__PROJECT_PKG_DIR}/app/*.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/cpp/${__PROJECT_PKG_DIR}/app/*.cxx
  ${CMAKE_CURRENT_SOURCE_DIR}/cpp/${__PROJECT_PKG_DIR}/app/*.cc)

target_sources(${__TARGET_APP} PRIVATE ${__target_app_src_cxx})

target_include_directories(${__TARGET_APP}
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/private)

target_link_libraries(${__TARGET_APP}
  PRIVATE ${__TARGET_CORE})

string(TOLOWER "${CMAKE_CXX_COMPILER_ID}" __cxx_compiler_id_tolower)
string(TOLOWER "${CMAKE_SYSTEM_NAME}" __cmake_system_name_tolower)
set_target_properties(${__TARGET_APP}
  PROPERTIES
    OUTPUT_NAME ${__TARGET_APP}-$<LOWER_CASE:$<CONFIG>>-${__cxx_compiler_id_tolower}-${__cmake_system_name_tolower})

install(
  TARGETS ${__TARGET_APP}
  EXPORT ${__TARGET_APP}-targets
  RUNTIME DESTINATION bin
  COMPONENT app)

add_custom_target(build-target-app
  COMMENT "::: build: (${__TARGET_APP})"
  DEPENDS ${__TARGET_APP})