# SPEC CPU 2017
# https://www.spec.org/cpu2017/Docs/

include(External)
include(CopyDir)
include(Host)
include(Fortran)

# Search for SPEC CPU 2017 root directory.
llvm_externals_find(TEST_SUITE_SPEC2017_ROOT "speccpu2017" "SPEC CPU2017")
if (NOT TEST_SUITE_SPEC2017_ROOT)
  return ()
endif ()

# Print warnings once only, even if included multiple times.
if (NOT TARGET speccpu2017_dummy)

  file(READ ${TEST_SUITE_SPEC2017_ROOT}/version.txt VERSION)
  if (VERSION VERSION_LESS 1.0.1)
    message(WARNING
      "Expected SPEC2017 version 1.0.1 or newer, found ${VERSION}")
  endif ()

  # SPEC supports three "run types": ref, train and test.
  set(_available_run_types test train ref)
  if (NOT TEST_SUITE_RUN_TYPE IN_LIST _available_run_types)
    message(FATAL_ERROR
      "TEST_SUITE_RUN_TYPE must be 'train', 'test' or 'ref' for SPEC")
  endif()

  add_custom_target(speccpu2017_dummy)
endif ()


# Set the variables an common compile flags for a SPEC CPU 2017 benchmark.
#
# SPEED/RATE Kind of benchmark suite
#
# ORIGIN     Allows the reuse of sourec files, input data, and reference
#            output from another benchmark.
macro (speccpu2017_benchmark)
  cmake_parse_arguments(_arg "SPEED;RATE" "ORIGIN" "" ${ARGN})

  # If BENCHMARK is set, another benchmark inherits from this benchark.
  # The relevant variables are already set in this case.
  if (NOT DEFINED BENCHMARK)

    get_filename_component(BENCHMARK "${CMAKE_CURRENT_SOURCE_DIR}" NAME)
    string(SUBSTRING ${BENCHMARK} 0 3 BENCHMARK_NO)
    set(PROG ${BENCHMARK})

    if (_arg_SPEED)
      set(BENCHMARK_SUITE_TYPE speed)
      set(SPEED ON)
      set(SUFFIX s)
    elseif (_arg_RATE)
      set(BENCHMARK_SUITE_TYPE rate)
      set(RATE ON)
      set(SUFFIX r)
    else ()
      message(FATAL_ERROR "Must define the benchmark type (RATE or SPEED)")
    endif ()

    if (DEFINED _arg_ORIGIN)
      set(ORIGIN ${_arg_ORIGIN})
    else ()
      set(ORIGIN ${BENCHMARK})
    endif ()

    set(BENCHMARK_DIR "${TEST_SUITE_SPEC2017_ROOT}/benchspec/CPU/${BENCHMARK}")
    set(ORIGIN_DIR "${TEST_SUITE_SPEC2017_ROOT}/benchspec/CPU/${ORIGIN}")


    set(SRC_DIR "${ORIGIN_DIR}/src")

    set(DATA_DIR "${BENCHMARK_DIR}/data")
    if (NOT EXISTS "${DATA_DIR}")
      set(DATA_DIR "${ORIGIN_DIR}/data")
    endif ()

    set(DATA_all_DIR "${DATA_DIR}/all")
    set(DATA_test_DIR "${DATA_DIR}/test")
    set(DATA_train_DIR "${DATA_DIR}/train")

    set(DATA_ref_DIR "${DATA_DIR}/refrate")
    if (SPEED AND EXISTS "${DATA_DIR}/refspeed")
      set(DATA_ref_DIR "${DATA_DIR}/refspeed")
    endif ()

    set(INPUT_all_DIR "${DATA_all_DIR}/input")
    set(OUTPUT_all_DIR "${DATA_all_DIR}/output")

    set(INPUT_test_DIR "${DATA_test_DIR}/input")
    set(OUTPUT_test_DIR "${DATA_test_DIR}/output")

    set(INPUT_train_DIR "${DATA_train_DIR}/input")
    set(OUTPUT_train_DIR "${DATA_train_DIR}/output")

    set(INPUT_ref_DIR "${DATA_ref_DIR}/input")
    set(OUTPUT_ref_DIR "${DATA_ref_DIR}/output")

    # Create benchmark working directories.
    foreach (_run_type IN LISTS TEST_SUITE_RUN_TYPE)
      set(RUN_${_run_type}_DIR "${CMAKE_CURRENT_BINARY_DIR}/run_${_run_type}")
      set(RUN_${_run_type}_DIR_REL "%S/run_${_run_type}")
      file(MAKE_DIRECTORY ${RUN_${_run_type}_DIR})
    endforeach ()


    # Mandatory SPEC definitions
    set(SPEC_COMMON_DEFS)
    list(APPEND SPEC_COMMON_DEFS "-DSPEC;-DSPEC_CPU;-DNDEBUG")

    if (RATE)
      # rate benchmarks never use parallelism
      list(APPEND SPEC_COMMON_DEFS "-DSPEC_AUTO_SUPPRESS_OPENMP")
    endif ()

    # Portability flags
    # SPEC_AUTO_BYTEORDER_value variable is used for Fortran tests that use specpp
    if (ENDIAN STREQUAL "little")
      list(APPEND SPEC_COMMON_DEFS "-DSPEC_AUTO_BYTEORDER=0x12345678")
    elseif (ENDIAN STREQUAL "big")
      list(APPEND SPEC_COMMON_DEFS "-DSPEC_AUTO_BYTEORDER=0x87654321")
    endif ()

    check_type_size("long long" SIZEOF_LONG_LONG)
    check_type_size("long" SIZEOF_LONG)
    check_type_size("int" SIZEOF_INT)
    # SPEC_PTR_TYPE variable is used for Fortran tests that use specpp
    if (CMAKE_SIZEOF_VOID_P EQUAL 4 AND SIZEOF_LONG_LONG EQUAL 8 AND SIZEOF_LONG EQUAL 4 AND SIZEOF_INT EQUAL 4)
      list(APPEND SPEC_COMMON_DEFS "-DSPEC_ILP32")
    elseif (CMAKE_SIZEOF_VOID_P EQUAL 8 AND SIZEOF_LONG_LONG EQUAL 8 AND SIZEOF_LONG EQUAL 4 AND SIZEOF_INT EQUAL 4)
      list(APPEND SPEC_COMMON_DEFS "-DSPEC_P64")
    elseif (CMAKE_SIZEOF_VOID_P EQUAL 8 AND SIZEOF_LONG_LONG EQUAL 8 AND SIZEOF_LONG EQUAL 8 AND SIZEOF_INT EQUAL 4)
      list(APPEND SPEC_COMMON_DEFS "-DSPEC_LP64")
    elseif (CMAKE_SIZEOF_VOID_P EQUAL 8 AND SIZEOF_LONG_LONG EQUAL 8 AND SIZEOF_LONG EQUAL 8 AND SIZEOF_INT EQUAL 8)
      list(APPEND "-DSPEC_ILP64")
    else ()
      message(FATAL_ERROR "SPEC CPU 2017 unsupported data model (supported: ILP32/LLP64/LP64/ILP64)")
    endif ()

    if (TARGET_OS STREQUAL "Linux")
      list(APPEND SPEC_COMMON_DEFS "-DSPEC_LINUX") # 526.blender_r
    endif ()

    if(ARCH STREQUAL "x86" AND TARGET_OS STREQUAL "Linux")
      if (CMAKE_SIZEOF_VOID_P EQUAL 8)
        # Linux x86_64
	list(APPEND SPEC_COMMON_DEFS "-DSPEC_LINUX_X64") # perlbench
      elseif (CMAKE_SIZEOF_VOID_P EQUAL 4)
        # Linux x86
	list(APPEND SPEC_COMMON_DEFS "-DSPEC_ILP32")
	list(APPEND SPEC_COMMON_DEFS "-D_FILE_OFFSET_BITS=64")
	list(APPEND SPEC_COMMON_DEFS "-DSPEC_LINUX_I32") # perlbench
      endif ()
    elseif (ARCH STREQUAL "AArch64" AND TARGET_OS STREQUAL "Linux" AND CMAKE_SIZEOF_VOID_P EQUAL 8)
      # Linux ARM
      list(APPEND SPEC_COMMON_DEFS "-DSPEC_LINUX_AARCH64")
    elseif (ARCH STREQUAL "x86" AND TARGET_OS STREQUAL "Windows")
      # Windows x86/x64
    elseif (TARGET_OS STREQUAL "Darwin")
      add_definitions(-DSPEC_MACOSX)
    else ()
      message("ARCH: ${ARCH}")
      message("TARGET_OS: ${TARGET_OS}")
      message("CMAKE_SIZEOF_VOID_P: ${CMAKE_SIZEOF_VOID_P}")
      message(FATAL_ERROR
        "Don't know portability flags for SPEC CPU 2017 on this platform")
    endif ()

    # No OpenMP for the moment, even for the _s suites.
    list(APPEND SPEC_COMMON_DEFS "-DSPEC_SUPPRESS_OPENMP")

    # Add SPEC_COMMON_DEFS
    add_definitions(${SPEC_COMMON_DEFS})

    if (TEST_SUITE_FORTRAN)
      # Used by cam4, pop2, and wrf tests for portability
      # https://gcc.gnu.org/gcc-10/porting_to.html
      check_fortran_compiler_flag("-fallow-argument-mismatch" SUPPORTS_FALLOW_ARGUMENT_MISMATCH)
    endif ()

  endif ()
endmacro()


# Reuse the CMakeLists.txt of another benchmark.
macro(speccpu2017_inherit _origin_path)
  include("${_origin_path}/CMakeLists.txt")
endmacro ()


# Add include directories relative to SRC_DIR.
macro (speccpu2017_add_include_dirs)
  foreach(_dirname ${ARGN})
    get_filename_component(_absdirname "${_dirname}" ABSOLUTE BASE_DIR ${SRC_DIR})
    include_directories("${_absdirname}")
  endforeach()
endmacro ()


# Add a "RUN:" line.
#
# RUN_TYPE   (test,train or ref)
#            Only run if this TEST_SUITE_RUN_TYPE is is selected.
#
# SUITE_TYPE (rate or speed)
#            Only run in the _r or _s benchmark suites.
#
# STDOUT     Write the benchmark's stdout into this file in the rundir.
#
# STDERR     Write the benchmark's stderr into this file in the rundir.
#
# ARGN       Benchmark's command line arguments
macro (speccpu2017_run_test)
  cmake_parse_arguments(_arg
    "" "RUN_TYPE;SUITE_TYPE;STDOUT;STDERR" "" ${ARGN})

  if ((NOT DEFINED _arg_SUITE_TYPE) OR
      (BENCHMARK_SUITE_TYPE IN_LIST _arg_SUITE_TYPE))
    if ((NOT DEFINED _arg_RUN_TYPE) OR
        (_arg_RUN_TYPE IN_LIST TEST_SUITE_RUN_TYPE))

      set(_stdout)
      if (DEFINED _arg_STDOUT)
        set(_stdout > "${RUN_${_arg_RUN_TYPE}_DIR_REL}/${_arg_STDOUT}")
      endif ()

      set(_stderr)
      if (DEFINED _arg_STDERR)
        set(_stderr 2> "${RUN_${_arg_RUN_TYPE}_DIR_REL}/${_arg_STDERR}")
      endif ()

      # perlbench, xalancbmk need to be invoked with relative paths
      # (SPEC made modifications that prepend another path to find the rundir)
      file(RELATIVE_PATH _executable
          "${RUN_${_arg_RUN_TYPE}_DIR}" "${CMAKE_CURRENT_BINARY_DIR}/${PROG}")
      set (_executable EXECUTABLE "${_executable}")

      llvm_test_run(
        ${_arg_UNPARSED_ARGUMENTS} ${_stdout} ${_stderr}
        RUN_TYPE ${_arg_RUN_TYPE}
        WORKDIR "${RUN_${_arg_RUN_TYPE}_DIR_REL}"
        ${_executable}
      )
    endif ()
  endif ()
endmacro ()


# Compare an image file to a reference image.
macro(speccpu2017_validate_image _imgfile _cmpfile _outfile)
  cmake_parse_arguments(_carg "" "RUN_TYPE" "SUITE_TYPE" ${ARGN})

  set(VALIDATOR imagevalidate_${BENCHMARK_NO}-target)
  if (NOT TARGET ${VALIDATOR})
    file(GLOB_RECURSE _validator_sources "${SRC_DIR}/image_validator/*.c")

    add_executable(${VALIDATOR} ${_validator_sources})
    target_link_libraries(${VALIDATOR} m)
    set_target_properties(${VALIDATOR} PROPERTIES COMPILE_FLAGS "-DSPEC")
    add_dependencies(${VALIDATOR} build-timeit)
    add_dependencies(${VALIDATOR} build-timeit-target)
  endif ()

  if ((NOT DEFINED _carg_SUITE_TYPE) OR (${BENCHMARK_SUITE_TYPE} IN_LIST _carg_SUITE_TYPE))
    get_filename_component(_basename "${_imgfile}" NAME_WE)
    get_filename_component(_ext "${_imgfile}" EXT)
    llvm_test_verify(
      cd "${RUN_${_carg_RUN_TYPE}_DIR_REL}" &&
      "%S/${VALIDATOR}" ${_carg_UNPARSED_ARGUMENTS}
        "${_imgfile}" "${RUN_${_carg_RUN_TYPE}_DIR_REL}/compare/${_cmpfile}"
        > ${RUN_${_carg_RUN_TYPE}_DIR_REL}/${_outfile}
      RUN_TYPE ${_carg_RUN_TYPE}
    )
  endif ()
endmacro ()

# Add a "VERIFY:" line that compares all of the benchmark's reference outputs
# with files in the rundir.
macro(speccpu2017_verify_output)
  cmake_parse_arguments(_arg
    "IGNORE_WHITESPACE" "ABSOLUTE_TOLERANCE;RELATIVE_TOLERANCE" "" ${ARGN})

  set(_abstol)
  if (DEFINED _arg_ABSOLUTE_TOLERANCE)
    set(_abstol -a "${_arg_ABSOLUTE_TOLERANCE}")
  endif ()

  set(_reltol)
  if (DEFINED _arg_RELATIVE_TOLERANCE)
    set(_reltol -r "${_arg_RELATIVE_TOLERANCE}")
  endif ()

  set(_ignorewhitespace)
  if (DEFINED _arg_IGNORE_WHITESPACE)
    set(_ignorewhitespace "-i")
  endif ()

  foreach (_runtype IN LISTS TEST_SUITE_RUN_TYPE ITEMS all)
    file(GLOB_RECURSE _reffiles "${OUTPUT_${_runtype}_DIR}/*")
    foreach (_reffile IN LISTS _reffiles)
      file(RELATIVE_PATH _filename "${OUTPUT_${_runtype}_DIR}" "${_reffile}")
      set(_outfile "${RUN_${_runtype}_DIR_REL}/${_filename}")
      set(_comparefile "${RUN_${_runtype}_DIR_REL}/compare/${_filename}")
      llvm_test_verify(RUN_TYPE ${_runtype}
        "%b/${FPCMP}" ${_abstol} ${_reltol} ${_ignorewhitespace}
          "${_comparefile}" "${_outfile}"
      )
    endforeach ()
  endforeach ()
endmacro()


# Add a SPEC CPU 2017 benchmark.
#
# Must be used after speccpu2017_run_test, speccpu2017_validate_image
# and speccpu2017_verify_output because those add lines to the
# ${BENCHMARK}.test file that is written here.
macro(speccpu2017_add_executable)
  set(_sources ${ARGN})
  if (_sources)
    set(_sources)
    foreach(_filename ${ARGN})
      get_filename_component(_absfilename "${_filename}"
        ABSOLUTE BASE_DIR ${SRC_DIR})
      list(APPEND _sources "${_absfilename}")
    endforeach()
  else ()
    file(GLOB_RECURSE _sources
      ${SRC_DIR}/*.c ${SRC_DIR}/*.cpp ${SRC_DIR}/*.cc ${SRC_DIR}/*.C ${SRC_DIR}/*.f ${SRC_DIR}/*.F ${SRC_DIR}/*.f90 ${SRC_DIR}/*.F90)
  endif ()

  llvm_test_executable(${PROG} ${_sources})

  if (TARGET ${VALIDATOR})
    add_dependencies(${PROG} ${VALIDATOR})
  endif ()
endmacro()


# Copy the input and comparison data to the rundir.
#
# Can often be avoided by either passing an absolute path to the file in the
# input dir, or using the input dir as working directory and specify the output
# file as an absolute path to the rundir.
macro(speccpu2017_prepare_rundir)
  foreach (_runtype IN LISTS TEST_SUITE_RUN_TYPE)
    if (EXISTS "${INPUT_all_DIR}")
      llvm_copy_dir(${PROG} "${RUN_${_runtype}_DIR}" "${INPUT_all_DIR}")
    endif ()
    llvm_copy_dir(${PROG} "${RUN_${_runtype}_DIR}" "${INPUT_${_runtype}_DIR}")

    file(MAKE_DIRECTORY "${RUN_${_runtype}_DIR}/compare")
    llvm_copy_dir(${PROG}
      "${RUN_${_runtype}_DIR}/compare" "${OUTPUT_${_runtype}_DIR}")
    if (EXISTS "${OUTPUT_${_runtype}_DIR}/../compare")
        llvm_copy_dir(${PROG}
          "${RUN_${_runtype}_DIR}/compare" "${OUTPUT_${_runtype}_DIR}/../compare")
    endif ()
  endforeach ()
endmacro()

# Run specpp on a list of SRCS provided and add them to the TARGET.
# Three arguments are required:
# TARGET must be already be defined prior to calling this command.
# SRCS is provided usually via a GLOB command external to this macro.
# DEFS are the arguments that would normally be passed to specpp.
# https://www.spec.org/cpu2017/Docs/specpp.html
# specpp is needed due to legacy use of filepp by a number of
# climate/weather codes.
macro(speccpu2017_run_specpp)
  cmake_parse_arguments(_arg "" "TARGET" "SRCS;DEFS" ${ARGN})
  set(_specpp_bin ${TEST_SUITE_SPEC2017_ROOT}/bin/specpp)
  # Add common specpp arguments used by all SPEC CPU 2017 tests.
  # -U__FILE__ is included as a work around. Source files uses _FILE_
  # as the filename without the path, but a few source files have a
  # typo and use __FILE__ instead which is an absolute path. So specpp
  # fails to do a replacement with just the filename (i.e. without the
  # path as intended). This is usually a benign error, but __FILE__
  # can lead to a deeply nested directory due CMake's build
  # directories. As a result, the source file line length becomes
  # incredibly long, so you end up with a ridiculously long line that
  # some compilers, like GCC, are unable to compile.
  set(ARG_COMMON -w -U__FILE__ ${SPEC_COMMON_DEFS} -DSPEC_CASE_FLAG -I${SRC_DIR})

  foreach(_absfilename ${_arg_SRCS})
    # message("Adding to source ${_absfilename} to target ${PROG}")
    get_filename_component(_filename ${_absfilename} NAME)
    add_custom_command(
      OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/${_filename}"
      COMMAND "${_specpp_bin}" ${ARG_COMMON} ${_arg_DEFS} "${_absfilename}" > "${CMAKE_CURRENT_BINARY_DIR}/${_filename}"
      DEPENDS "${_absfilename}"
      VERBATIM
      )
    target_sources(${_arg_TARGET} PRIVATE "${CMAKE_CURRENT_BINARY_DIR}/${_filename}")
  endforeach ()
endmacro()


# Check if compiler can support big-endian IO format, if true proceed
# otherwise, return immediately. This is due to some binary input
# files stored in big-endian format that are required by the SPEC tests
macro(speccpu2017_convert_bigendian_required)
  if (ENDIAN STREQUAL "little")
    # GCC
    check_fortran_compiler_flag("-fconvert=big-endian" SUPPORTS_FCONVERT_BIG_ENDIAN)
    # Intel
    check_fortran_compiler_flag("-convert big_endian" SUPPORTS_CONVERT_BIG_ENDIAN)
    # Flang
    # TBD
    if (NOT SUPPORTS_FCONVERT_BIG_ENDIAN)
    elseif (NOT SUPPORTS_CONVERT_BIG_ENDIAN)
    else ()
      message(WARN "Test not supported. No way to read big-endian binary IO on little-endian architecture.")
      return ()
    endif ()
  endif ()
endmacro ()
