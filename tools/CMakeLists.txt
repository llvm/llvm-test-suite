# Note that we have to compile fpcmp and timeit for the host machine even when
# cross compiling to a different target. We use custom rules doing "cc file.c"
# as an ad-hoc solution for now. A proper solution would probably be based on
# ExternalProject_Add(); See also http://reviews.llvm.org/D15004

include(Host)

llvm_add_host_executable(build-fpcmp fpcmp fpcmp.c)

option(TEST_SUITE_USE_PERF "Use perf (timeit.sh) instead of timeit.c" OFF)
if(TEST_SUITE_USE_PERF)
  add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/timeit
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/timeit.sh ${CMAKE_CURRENT_BINARY_DIR}/timeit
    COMMAND chmod +x ${CMAKE_CURRENT_BINARY_DIR}/timeit
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/timeit.sh)
  add_custom_target(build-timeit DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/timeit)

  add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/timeit-target
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/timeit.sh ${CMAKE_CURRENT_BINARY_DIR}/timeit-target
    COMMAND chmod +x ${CMAKE_CURRENT_BINARY_DIR}/timeit-target
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/timeit.sh)
  add_custom_target(build-timeit-target DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/timeit-target)
else()
  add_executable(timeit-target ${CMAKE_CURRENT_SOURCE_DIR}/timeit.c)
  add_executable(build-timeit-target ALIAS timeit-target)
  llvm_add_host_executable(build-timeit timeit timeit.c)
endif()
