# Tools for compiling and running the benchmarks.
#
# Note: Tools used while running the benchmark should be (cross-)compiled
# normally while tools used for building the benchmark need to be built for
# the host system (even when cross-compiling the benchmark) with
# `llvm_add_host_executable`.

include(Host)

add_executable(fpcmp-target ${CMAKE_CURRENT_SOURCE_DIR}/fpcmp.c)
llvm_codesign(fpcmp-target)
add_executable(build-fpcmp-target ALIAS fpcmp-target)
llvm_add_host_executable(build-fpcmp fpcmp fpcmp.c)

add_custom_command(
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/HashProgramOutput.sh
  COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/../HashProgramOutput.sh ${CMAKE_CURRENT_BINARY_DIR}/HashProgramOutput.sh
  COMMAND chmod +x ${CMAKE_CURRENT_BINARY_DIR}/HashProgramOutput.sh
  DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/../HashProgramOutput.sh
)
add_custom_target(build-HashProgramOutput.sh DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/HashProgramOutput.sh)

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
  llvm_codesign(timeit-target)
  add_executable(build-timeit-target ALIAS timeit-target)
  llvm_add_host_executable(build-timeit timeit timeit.c)
endif()

# FIXME: the iOS buildbots can't build this since it uses `std::system`, but
# since we don't support Fortram on the iOS bots and this utility is only used
# by Fortran tests, it effectively "reverts to green", without entirely
# reverting the patch.
#
# See: https://github.com/llvm/llvm-project/issues/77137
if(TEST_SUITE_FORTRAN)
  add_executable(not ${CMAKE_CURRENT_SOURCE_DIR}/not.cpp)
endif()