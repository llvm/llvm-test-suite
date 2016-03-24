list(APPEND CPPFLAGS -DSPEC_CPU95)

macro(cint95_subdir)
  foreach(BENCHMARK ${ARGN})
    set(BENCHMARK_DIR ${TEST_SUITE_SPEC95_ROOT}/benchspec/CINT95/${BENCHMARK})
    set(PROG ${BENCHMARK})
    file(GLOB Source ${BENCHMARK_DIR}/src/*.c ${BENCHMARK_DIR}/src/*.cpp)
    llvm_add_subdirectories(${BENCHMARK})
  endforeach()
endmacro()

cint95_subdir(
  099.go
  124.m88ksim
  #  126.gcc # uses nonstandard lvalue casts which clang doesn't support
  129.compress
  130.li
  132.ijpeg
  134.perl
  147.vortex
)
