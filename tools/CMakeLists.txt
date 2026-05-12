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

add_executable(not ${CMAKE_CURRENT_SOURCE_DIR}/not.cpp)

if(APPLE)
  add_executable(macho_arch-target ${CMAKE_CURRENT_SOURCE_DIR}/macho_arch.c)
  # Avoid a problem with old host tools on Green Dragon, where the Xcode 16.2
  # lipo doesn't know how to read the bitcode from the just-built llvm23.0-based
  # clang, by turning off LTO.
  target_compile_options(macho_arch-target PRIVATE -fno-lto)
  target_link_options(macho_arch-target PRIVATE -fno-lto)
  llvm_codesign(macho_arch-target)
  add_executable(build-macho_arch-target ALIAS macho_arch-target)
  # Ensure that macho_arch is built with at least arm64;arm64e, plus whatever
  # was already in CMAKE_OSX_ARCHITECTURES.
  set(_macho_arch_archs ${CMAKE_OSX_ARCHITECTURES} arm64 arm64e)
  list(REMOVE_DUPLICATES _macho_arch_archs)
  set_target_properties(macho_arch-target PROPERTIES OSX_ARCHITECTURES "${_macho_arch_archs}")
  set(_macho_arch_arch_flags)
  foreach(_arch IN LISTS _macho_arch_archs)
    list(APPEND _macho_arch_arch_flags -arch ${_arch})
  endforeach()
  llvm_add_host_executable(build-macho_arch macho_arch macho_arch.c
    CPPFLAGS ${_macho_arch_arch_flags}
    LDFLAGS ${_macho_arch_arch_flags})
endif()
