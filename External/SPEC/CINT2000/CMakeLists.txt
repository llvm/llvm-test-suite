list(APPEND CPPFLAGS -DSPEC_CPU2000)
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
  list(APPEND CPPFLAGS -DSPEC_CPU2000_LP64)
endif()

macro(cint2000_subdir)
  foreach(BENCHMARK ${ARGN})
    set(BENCHMARK_DIR ${TEST_SUITE_SPEC2000_ROOT}/benchspec/CINT2000/${BENCHMARK})
    set(PROG ${BENCHMARK})
    file(GLOB Source ${BENCHMARK_DIR}/src/*.c ${BENCHMARK_DIR}/src/*.cpp)
    llvm_add_subdirectories(${BENCHMARK})
  endforeach()
endmacro()

cint2000_subdir(
  164.gzip
  175.vpr
  176.gcc
  181.mcf
  186.crafty
  197.parser
  252.eon
  253.perlbmk
  254.gap
  255.vortex
  256.bzip2
  300.twolf
)
