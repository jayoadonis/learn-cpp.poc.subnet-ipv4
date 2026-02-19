add_executable(${__TARGET_UNIT_TEST})

add_dependencies(${__TARGET_UNIT_TEST} ${__TARGET_CORE})

target_compile_features(${__TARGET_UNIT_TEST}
  PUBLIC cxx_std_17)

target_compile_options(${__TARGET_UNIT_TEST}
  PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>>:
      -Wall;-Wextra;-Wpedantic>
    $<$<CXX_COMPILER_ID:MSVC>:
      /Wall;/W3;/W4;/permissive->)

file(GLOB_RECURSE __target_unit_test_src_cxx CONFIGURE_DEPENDS
  ${CMAKE_CURRENT_SOURCE_DIR}/cpp/${__PROJECT_PKG_DIR}/unit_test/*.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/cpp/${__PROJECT_PKG_DIR}/unit_test/*.cxx
  ${CMAKE_CURRENT_SOURCE_DIR}/cpp/${__PROJECT_PKG_DIR}/unit_test/*.cc)

target_sources(${__TARGET_UNIT_TEST} PRIVATE ${__target_unit_test_src_cxx})

target_include_directories(${__TARGET_UNIT_TEST}
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/private)

target_link_libraries(${__TARGET_UNIT_TEST}
  PRIVATE ${__TARGET_CORE})

add_custom_command(TARGET ${__TARGET_UNIT_TEST}
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
          $<TARGET_FILE:${__TARGET_CORE}>
          $<TARGET_FILE_DIR:${__TARGET_UNIT_TEST}>
  COMMENT "Copy (${__TARGET_CORE}) runtime next to unit test")

add_test(NAME "compact" COMMAND ${__TARGET_UNIT_TEST} "--compact")
add_test(NAME "ipv4-test-i" COMMAND ${__TARGET_UNIT_TEST} "--ipv4-test-i")
add_test(NAME "ipv4-test-ii" COMMAND ${__TARGET_UNIT_TEST} "--ipv4-test-ii")

set_tests_properties("compact" PROPERTIES LABELS "unit-test-compact")
set_tests_properties("ipv4-test-i" PROPERTIES LABELS "unit-test-ipv4-test-i")
set_tests_properties("ipv4-test-ii" PROPERTIES LABELS "unit-test-ipv4-test-ii")

string(TOLOWER ${CMAKE_CXX_COMPILER_ID} __cmake_cxx_compiler_id_tolower)
string(TOLOWER ${CMAKE_SYSTEM_NAME} __cmake_system_name_tolower)
set_target_properties(${__TARGET_UNIT_TEST}
  PROPERTIES
    RUNTIME_OUTPUT_NAME 
      ${__TARGET_UNIT_TEST}-$<LOWER_CASE:$<CONFIG>>-${__cmake_cxx_compiler_id_tolower}-${__cmake_system_name_tolower})

add_custom_target("unit-test"
  COMMAND ${CMAKE_CTEST_COMMAND} 
    --test-dir ${CMAKE_BINARY_DIR}
    -C $<CONFIG>
    -L "unit-test.*"
    -VV
  DEPENDS ${__TARGET_CORE} ${__TARGET_UNIT_TEST})

