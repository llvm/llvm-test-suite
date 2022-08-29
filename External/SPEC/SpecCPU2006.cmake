include(External)
llvm_externals_find(TEST_SUITE_SPEC2006_ROOT "speccpu2006" "SPEC CPU2006")
if(TEST_SUITE_SPEC2006_ROOT)
  # SPEC supports three "run types": ref, train and test
  if(NOT TEST_SUITE_RUN_TYPE STREQUAL "train" AND
     NOT TEST_SUITE_RUN_TYPE STREQUAL "test" AND
     NOT TEST_SUITE_RUN_TYPE STREQUAL "ref")
    message(FATAL_ERROR
            "TEST_SUITE_RUN_TYPE must be 'train', 'test' or 'ref' for SPEC")
  endif()

  file(READ ${TEST_SUITE_SPEC2006_ROOT}/version.txt VERSION)
  if (VERSION VERSION_LESS 1.2)
    message(WARNING "
    Expected SPEC2006 version 1.2 or newer, found ${VERSION}
")
  endif()

  list(APPEND CPPFLAGS -DSPEC_CPU)

  if(TARGET_OS STREQUAL "Darwin")
    list(APPEND CPPFLAGS -DSPEC_CPU_MACOSX)
  elseif(TARGET_OS STREQUAL "Linux")
    list(APPEND CPPFLAGS -DSPEC_CPU_LINUX)
  elseif(TARGET_OS STREQUAL "FreeBSD")
    list(APPEND CPPFLAGS -DSPEC_CPU_BSD)
    # As support for SPEC_CPU_BSD is incomplete in SPEC2006, we also have to
    # pass -DSPEC_CPU_MACOSX to avoid the use of gcvt() in 400.perlbench as
    # this function is not available on FreeBSD. Additionally, this define
    # ensures that all required functions are compiled in 483.xalancbmk and
    # that complex.h is included in 462.libquantum.
    list(APPEND CPPFLAGS -DSPEC_CPU_MACOSX)
  else()
    message(WARNING "Unsupported SPEC2006 TARGET_OS: ${TARGET_OS}")
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
    list(APPEND CPPFLAGS -DSPEC_CPU_BIGENDIAN -DSPEC_CPU_BIG_ENDIAN)
  else()
    list(APPEND CPPFLAGS -DSPEC_CPU_LITTLEENDIAN -DSPEC_CPU_LITTLE_ENDIAN)
  endif()

  if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    list(APPEND CPPFLAGS -DSPEC_CPU_LP64)
  endif()

  list(APPEND CFLAGS -Wno-implicit-function-declaration)

  macro(cpu2006_subdir BENCHMARK)
    set(BENCHMARK_DIR ${TEST_SUITE_SPEC2006_ROOT}/benchspec/CPU2006/${BENCHMARK})
    file(GLOB Source ${BENCHMARK_DIR}/src/*.c ${BENCHMARK_DIR}/src/*.cpp ${BENCHMARK_DIR}/src/*.cc)
    add_subdirectory(${BENCHMARK})
  endmacro()

  function(llvm_test_data_spec target)
    llvm_test_data(${target} SOURCE_DIR ${BENCHMARK_DIR} ${ARGN})
  endfunction()

  function(llvm_test_data_spec_default target)
    llvm_test_data_spec(${target} data)
  endfunction()
endif()
