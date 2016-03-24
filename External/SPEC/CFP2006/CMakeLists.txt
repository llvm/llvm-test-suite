list(APPEND CPPFLAGS -DSPEC_CPU)

if(TARGET_OS STREQUAL "Darwin")
  list(APPEND CPPFLAGS -DSPEC_CPU_MACOSX)
elseif(TARGET_OS STREQUAL "Linux")
  list(APPEND CPPFLAGS -DSPEC_CPU_LINUX)
endif()

if(ARCH STREQUAL "x86")
  if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    list(APPEND CPPFLAGS -DSPEC_CPU_X64)
  else()
    list(APPEND CPPFLAGS -DSPEC_CPU_IA32)
  endif()
endif()

include(TestBigEndian)
test_big_endian(IS_BIGENDIAN)
if(IS_BIGENDIAN)
  list(APPEND CPPFLAGS -DSPEC_CPU_BIGENDIAN)
else()
  list(APPEND CPPFLAGS -DSPEC_CPU_LITTLEENDIAN)
endif()

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
  list(APPEND CPPFLAGS -DSPEC_CPU_LP64)
endif()

macro(cpu2006_subdir)
  foreach(BENCHMARK ${ARGN})
    set(BENCHMARK_DIR ${TEST_SUITE_SPEC2006_ROOT}/benchspec/CPU2006/${BENCHMARK})
    set(PROG ${BENCHMARK})
    file(GLOB Source ${BENCHMARK_DIR}/src/*.c ${BENCHMARK_DIR}/src/*.cpp ${BENCHMARK_DIR}/src/*.cc)
    llvm_add_subdirectories(${BENCHMARK})
  endforeach()
endmacro()

cpu2006_subdir(
  433.milc
  444.namd
  447.dealII
  450.soplex
  453.povray
  470.lbm
  482.sphinx3
)
