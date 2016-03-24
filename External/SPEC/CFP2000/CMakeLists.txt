list(APPEND LDFLAGS -lm)
list(APPEND CPPFLAGS -DSPEC_CPU2000)
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
  list(APPEND CPPFLAGS -DSPEC_CPU2000_LP64)
endif()

macro(cfp2000_subdir)
  foreach(BENCHMARK ${ARGN})
    set(BENCHMARK_DIR ${TEST_SUITE_SPEC2000_ROOT}/benchspec/CFP2000/${BENCHMARK})
    set(PROG ${BENCHMARK})
    file(GLOB Source ${BENCHMARK_DIR}/src/*.c ${BENCHMARK_DIR}/src/*.cpp)
    llvm_add_subdirectories(${BENCHMARK})
  endforeach()
endmacro()

cfp2000_subdir(
  177.mesa
  179.art
  183.equake
  188.ammp
)
