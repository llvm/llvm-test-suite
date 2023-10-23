# HeCBench
# https://github.com/zjin-lcf/HeCBench

include(External)

option(TEST_SUITE_HECBENCH_FORCE_ALL "Execute all HeCBench tests, even those known to be unsupported by Clang" OFF)

set(TEST_SUITE_OFFLOADING_FLAGS --offload-arch=native CACHE STRING "Compiler arguments for OpenMP offloading")
set(TEST_SUITE_OFFLOADING_LDFLAGS --offload-arch=native CACHE STRING "Linker arguments for OpenMP offloading")

set(TEST_SUITE_HECBENCH_EXPECT_PASS
    ace-omp/main.cpp
    1
    
    adam-omp/main.cpp
    1
    1
    1

    aidw-omp/main.cpp 
    1
    1 
    1

    aobench-omp/ao.cpp
    1

    atan2-omp/main.cpp
    1
    1
)

function (add_hecbench LANG)
  if (NOT OpenMP_${LANG}_FOUND)
    message(FATAL_ERROR "OpenMP for ${LANG} not found")
    return ()
  endif ()

  file(GLOB_RECURSE _tests_sources RELATIVE "${TEST_SUITE_HECBENCH_ROOT}/src" "${TEST_SUITE_HECBENCH_ROOT}/src/*/*.cpp" )
  foreach (_file IN LISTS _tests_sources)
    get_filename_component(_directory "${_file}" DIRECTORY)
    set(_name "hecbench-${_directory}")

    if (NOT TEST_SUITE_HECBENCH_FORCE_ALL AND NOT "${_file}" IN_LIST TEST_SUITE_HECBENCH_EXPECT_PASS)
      message(STATUS "Skipping HeCBench Benchmark ${_file}")
      continue ()
    endif ()

    list(FIND TEST_SUITE_HECBENCH_EXPECT_PASS "${_file}" _index)
    if (${_index} EQUAL -1)
      message(STATUS "Skipping HeCBench Benchmark ${_file}")
      continue ()
    endif ()

    set(_args_for_benchmark "")
    set(IN_DIRECTORY FALSE)

    foreach(item IN LISTS TEST_SUITE_HECBENCH_EXPECT_PASS)
      if(item MATCHES ".*-omp.*")
        
        if(IN_DIRECTORY)
          break()
        endif()
        
        if(item MATCHES ${_directory})
          set(IN_DIRECTORY TRUE)
        endif()
      else()
        if(IN_DIRECTORY)
          list(APPEND _args_for_benchmark "${item}")
        endif()
      endif()
    endforeach()

    llvm_test_run(
      ${_args_for_benchmark}
    )

    # Define the path to the benchmark directory
    set(BENCHMARK_DIR "${TEST_SUITE_HECBENCH_ROOT}/src/${_directory}")

    # Find the Makefile in the benchmark directory
    file(GLOB MAKEFILE_PATH "${BENCHMARK_DIR}/Makefile")

    if(MAKEFILE_PATH)
      # Read the content of the Makefile into a variable
      file(READ "${MAKEFILE_PATH}" MAKEFILE_CONTENT)

      # Use regular expressions to find the -I flag in CFLAGS
      string(REGEX MATCH ".*-I([^ \t]+)" CFLAGS_MATCH "${MAKEFILE_CONTENT}")

      # Check if CFLAGS were found in the Makefile
      if(CFLAGS_MATCH)
        # Extract the part after the last '-I' and trim spaces
        set(CFLAGS_INCLUDE "${CMAKE_MATCH_1}")

        # Remove the '../' prefix if it exists
        string(REPLACE "../" "" CFLAGS_INCLUDE "${CFLAGS_INCLUDE}")

        string(REGEX REPLACE "[^a-zA-Z-]+" "" CFLAGS_INCLUDE "${CFLAGS_INCLUDE}")
        string(REPLACE "\n" "" CFLAGS_INCLUDE "${CFLAGS_INCLUDE}")

        # Format the extracted CFLAGS include part as -I<directory>
        set(CFLAGS_INCLUDE "/${CFLAGS_INCLUDE}")

      else()
        message(STATUS "CFLAGS not found in Makefile.")
      endif()
    else()
      message(STATUS "Makefile not found in ${BENCHMARK_DIR}.")
    endif()


    set(_includedir "${TEST_SUITE_HECBENCH_ROOT}/src/${CFLAGS_INCLUDE}" )

    llvm_test_executable(${_name} "${TEST_SUITE_HECBENCH_ROOT}/src/${_file}")
    target_include_directories(${_name} PRIVATE ${_includedir})
    target_link_libraries(${_name} PUBLIC OpenMP::OpenMP_${_lang})


    # Add -fopenmp to linker command line; for some reason this is not done by target_link_libraries.
    target_link_options(${_name} PRIVATE ${OpenMP_${LANG}_FLAGS})

    # CMake's find_package(OpenMP) currently does not not introspect flags necessary for offloading.
    target_compile_options(${_name} PUBLIC ${TEST_SUITE_OFFLOADING_FLAGS})
    target_link_options(${_name} PUBLIC ${TEST_SUITE_OFFLOADING_LDFLAGS})

  endforeach ()
endfunction ()


llvm_externals_find(TEST_SUITE_HECBENCH_ROOT "hecbench" "HeCBench")
if (TEST_SUITE_HECBENCH_ROOT AND NOT TEST_SUITE_BENCHMARKING_ONLY)
  if (OpenMP_FOUND)
    message(STATUS "Adding HeCBench")
  else ()
    message(STATUS "NOT using HeCBench because OpenMP was not found")
    return ()
  endif ()

  foreach (_lang in CXX)
    if (CMAKE_${_lang}_COMPILER)
      add_hecbench(${_lang})
    endif()
  endforeach ()
endif ()
