# Smoke
# https://github.com/ROCm-Developer-Tools/aomp.git

include(External)

option(TEST_SUITE_SMOKE_FORCE_ALL "Execute all Smoke tests, even those known to be unsupported by Clang" OFF)

set(TEST_SUITE_OFFLOADING_FLAGS --offload-arch=native CACHE STRING "Compiler arguments for OpenMP offloading")
set(TEST_SUITE_OFFLOADING_LDFLAGS --offload-arch=native CACHE STRING "Linker arguments for OpenMP offloading")

set(INTEL_TEST_SUITE_EXPECT_PASS)

set(AMD_TEST_SUITE_EXPECT_PASS
    alignedattribute
    already_locked
    ancestorC
    aomp-issue376
    assertok_error
    assume_no_openmp
    atomic
    atomic_double
    bugz-50967
    bugz-50967-c
    bugz-50968
    CanonNE
    clang-262701
    clang-273738
    clang-273739
    clang-274983
    clang-282491-1
    clang-282491-2
    clang-282491-3
    clang-296953-ornla-38
    clang-310869-scan
    clang-313307_simple_arr
    clang-313307_simple_spmd
    clang-325070
    clang-326105
    clang-337336
    clang-357649
    clang-358841
    clang-359947
    clang-373823
    clang-383246
    clang-388381
    clang-392854
    clang-alloc1
    clang-gfx1030
    clang-host-targ
    clang-ifaces
    clang-meta
    clang-meta2
    clang-meta3
    clang-meta4
    clang-meta5
    clang-nest-nothing
    clang-new-driver
    clang_private
    clang-red-DblComplex
    clang-red-SglComplex
    clang-reduction-and
    clang-tracekernel
    class
    closed_bug2
    collapse
    collapse1
    collapse-nonrectangle
    collapse_parallel_spmd
    complex
    complex2
    complex-debug
    complex_reduction
    const_global_ctor-308039
    d2h_slow_copy
    data_enter_issue01
    data_issue_59
    data_share1
    data_share2
    declare_target_pointer
    decl_map_targ
    devices
    devito_prob1
    double_complex_scalar
    extern_init
    famd-opt-279975
    firstprivate
    firstprivate2
    flags
    func-ptr
    function
    function_overload
    function_template
    gdb_teams
    gpus
    helloworld
    helloworld_cov4
    host_or_device
    host_targ
    host_teams_numa_affinity
    icvars-nest
    issue_001
    issue_002
    kokkos_log2
    launch_latency
    lds-prob1
    lds-prob2
    lds-prob3
    leopold-devicePtr
    libgomp-292348
    longDouble
    loop-dir-1
    loop-dir-2
    loop-dir-3
    loop-dir-4
    loop-dir-5
    loop-dir-6
    loop-dir-7
    loop-dir-9
    loop_order
    lto_teams
    Makefile
    Makefile.rules
    many_arrays
    ManyKernels
    map_to_from_prob
    map_zero_bug
    MasterBarrier
    math_exp
    math_modff
    math_pow
    matmul_fun
    matmul_parallel_spmd
    MaxNumThrds
    memcmp
    mem_foot_print
    memory_mgmt_routines
    modf_template
    multi-image
    multi-image3
    nativetests
    nested_loop
    nested_loop_trunk
    nested_loop_trunk1
    nested_targ
    noarg_target_function
    omp_get_device_num
    omp_get_initial
    omp_loop
    omp_num_teams_generic
    omp_num_teams_SPMD
    omp_places
    omp_targ_err1
    omp_target_is
    omp_wtime
    openmp-gpu-burn
    pfspecifier
    pfspecifier_str
    printf_parallel_for_target
    README
    red_bug_51
    reduce
    reduc_map_prob
    reduction
    reduction_array
    reduction_array_section
    reduction_issue_16
    reduction_shared_array
    reduction_team
    reduction_teams
    reduction_teams_distribute_parallel
    requires_usm
    schedule
    simd
    simple_ctor
    slices
    targ-273742
    targc-272328
    targc-274983
    targc-generic
    targc-spmd
    target_depend
    targetid_multi_image
    target_nowait
    target-shared-variables
    targets_in_loop
    task_detach
    task-helper
    taskwait_prob
    team_prob
    teams
    teams_nest
    teams_notarget
    teams_notarget_get_num_teams
    teams_notarget_get_team_num
    test
    thread_limit
    threads
    use_device_addr
    usm1
    usm-globals
    vasp1
    veccopy
    veccopy-kernels
    veccopy-ompt-target
    veccopy-ompt-target-disallow-both
    veccopy-ompt-target-emi
    veccopy-ompt-target-emi-map
    veccopy-ompt-target-emi-tracing
    veccopy-ompt-target-map
    veccopy-ompt-target-noinit
    veccopy-ompt-target-wrong-return
    virtual_functions
    vmuldemo
    wgs64
)

set(NVIDIA_TEST_SUITE_EXPECT_PASS
    alignedattribute
    already_locked
    ancestorC
    aomp-issue376
    assume_no_openmp
    atomic
    atomic_double
    bugz-50967
    bugz-50967-c
    bugz-50968
    CanonNE
    clang-262701
    clang-273738
    clang-273739
    clang-274983
    clang-282491-1
    clang-282491-2
    clang-282491-3
    clang-296953-ornla-38
    clang-310869-scan
    clang-313307_simple_arr
    clang-325070
    clang-326105
    clang-337336
    clang-357649
    clang-358841
    clang-359947
    clang-373823
    clang-383246
    clang-388381
    clang-392854
    clang-alloc1
    clang-gfx1030
    clang-host-targ
    clang-ifaces
    clang-meta
    clang-meta2
    clang-meta3
    clang-meta4
    clang-meta5
    clang-nest-nothing
    clang-new-driver
    clang_private
    clang-red-DblComplex
    clang-red-SglComplex
    clang-reduction-and
    clang-tracekernel
    class
    closed_bug2
    collapse
    collapse1
    collapse-nonrectangle
    collapse_parallel_spmd
    complex
    complex2
    complex-debug
    complex_reduction
    const_global_ctor-308039
    d2h_slow_copy
    data_enter_issue01
    data_issue_59
    data_share1
    data_share2
    declare_target_pointer
    decl_map_targ
    devices
    devito_prob1
    double_complex_scalar
    extern_init
    famd-opt-279975
    firstprivate
    firstprivate2
    flags
    function
    function_overload
    function_template
    gdb_teams
    gpus
    helloworld
    helloworld_cov4
    host_or_device
    host_targ
    host_teams_numa_affinity
    icvars-nest
    issue_001
    issue_002
    kokkos_log2
    launch_latency
    lds-prob1
    lds-prob2
    lds-prob3
    libgomp-292348
    loop-dir-1
    loop-dir-2
    loop-dir-3
    loop-dir-4
    loop-dir-5
    loop-dir-6
    loop-dir-7
    loop-dir-9
    loop_order
    lto_teams
    Makefile
    Makefile.rules
    many_arrays
    ManyKernels
    map_to_from_prob
    map_zero_bug
    MasterBarrier
    math_exp
    math_modff
    math_pow
    matmul_fun
    matmul_parallel_spmd
    MaxNumThrds
    memcmp
    mem_foot_print
    memory_mgmt_routines
    modf_template
    multi-image
    multi-image3
    nested_loop
    nested_loop_trunk
    nested_loop_trunk1
    nested_targ
    noarg_target_function
    omp_get_device_num
    omp_get_initial
    omp_loop
    omp_num_teams_generic
    omp_num_teams_SPMD
    omp_places
    omp_targ_err1
    omp_target_is
    openmp-gpu-burn
    pfspecifier
    pfspecifier_str
    printf_parallel_for_target
    README
    red_bug_51
    reduce
    reduc_map_prob
    reduction
    reduction_array
    reduction_array_section
    reduction_issue_16
    reduction_shared_array
    reduction_team
    reduction_teams
    reduction_teams_distribute_parallel
    schedule
    simd
    simple_ctor
    slices
    targ-273742
    targc-272328
    targc-274983
    targc-generic
    targc-spmd
    target_depend
    targetid_multi_image
    target_nowait
    target-shared-variables
    targets_in_loop
    task_detach
    task-helper
    taskwait_prob
    team_prob
    teams
    teams_nest
    teams_notarget
    teams_notarget_get_num_teams
    teams_notarget_get_team_num
    test
    thread_limit
    threads
    use_device_addr
    usm-globals
    vasp1
    veccopy
    veccopy-kernels
    veccopy-ompt-target
    veccopy-ompt-target-disallow-both
    veccopy-ompt-target-emi
    veccopy-ompt-target-emi-map
    veccopy-ompt-target-emi-tracing
    veccopy-ompt-target-map
    veccopy-ompt-target-noinit
    veccopy-ompt-target-wrong-return
    virtual_functions
    vmuldemo
    wgs64
)

function (add_smoke LANG WHITE_LIST_CHOOSEN)
  set(_includedir "${TEST_SUITE_SMOKE_ROOT}/ompvv" )

  if (NOT OPENMP_${LANG}_FOUND)
    message(FATAL_ERROR "OpenMP for ${LANG} not found")
    return ()
  endif ()

  if ("${LANG}" STREQUAL "C")
    set(_langext ".c")
  elseif ("${LANG}" STREQUAL "CXX")
    set(_langext ".cpp")
  else ()
    message(FATAL_ERROR "Unsupported languge ${LANG}")
  endif ()

  file(GLOB_RECURSE _tests_sources RELATIVE "${TEST_SUITE_SMOKE_ROOT}/test/smoke" "${TEST_SUITE_SMOKE_ROOT}/test/smoke/*/Makefile" )
  foreach (_makefile IN LISTS _tests_sources)
    get_filename_component(_directory "${_makefile}" DIRECTORY)
    set(_name "smoke-${_directory}")

    if (NOT TEST_SUITE_SMOKE_FORCE_ALL AND NOT "${_directory}" IN_LIST ${WHITE_LIST_CHOOSEN})
      message(STATUS "Skipping Smoke test ${_directory}")
      continue ()
    endif ()

    # Define the path to the benchmark directory
    set(BENCHMARK_DIR "${TEST_SUITE_SMOKE_ROOT}/test/smoke/${_directory}")

    # Find the Makefile in the benchmark directory
    file(GLOB_RECURSE MAKEFILE_PATH "${BENCHMARK_DIR}/Makefile")

    if(MAKEFILE_PATH)
      # Read the content of the Makefile into a variable
      file(READ "${MAKEFILE_PATH}" MAKEFILE_CONTENT)

      # Use regular expressions to find the names of the files to run
      string(REGEX MATCH "TESTSRC_MAIN[ \t]*=[ \t]*([^ \t]+)" TESTSRC_MAIN_MATCH "${MAKEFILE_CONTENT}")
      string(REGEX MATCH "TESTSRC_AUX[ \t]*=[ \t]*([^ \t]+)" TESTSRC_AUX_MATCH "${MAKEFILE_CONTENT}")

      # Check if the names were found in the Makefile
      if(TESTSRC_MAIN_MATCH)
        # Format the extracted files
        string(REPLACE "TESTSRC_AUX" "" TESTSRC_MAIN_MATCH "${TESTSRC_MAIN_MATCH}")
        string(REPLACE "\n" "" TESTSRC_MAIN_MATCH "${TESTSRC_MAIN_MATCH}")
        string(REGEX REPLACE ".*=" "" TESTSRC_MAIN_MATCH "${TESTSRC_MAIN_MATCH}")
        string(REPLACE " " "" TESTSRC_MAIN_MATCH "${TESTSRC_MAIN_MATCH}")

        set(_file "${TESTSRC_MAIN_MATCH}")

      else()
	      message(FATAL_ERROR "TESTSRC_MAIN not found in Makefile. ${_directory}")
      endif()
    else()
      message(STATUS "Makefile not found in ${_directory}")
    endif()

	message(STATUS "${_directory}")

    llvm_test_run()

    llvm_test_executable(${_name} "${TEST_SUITE_SMOKE_ROOT}/test/smoke/${_directory}/${_file}")
    target_include_directories(${_name} PRIVATE "${_includedir}")
    target_link_libraries(${_name} PUBLIC OpenMP::OpenMP_${_lang})

    # Add -fopenmp to linker command line; for some reason this is not done by target_link_libraries.
    target_link_options(${_name} PRIVATE ${OpenMP_${LANG}_FLAGS})

    # CMake's find_package(OpenMP) currently does not not introspect flags necessary for offloading.
    target_compile_options(${_name} PUBLIC ${TEST_SUITE_OFFLOADING_FLAGS})
    target_link_options(${_name} PUBLIC ${TEST_SUITE_OFFLOADING_LDFLAGS})
  endforeach ()
endfunction ()


llvm_externals_find(TEST_SUITE_SMOKE_ROOT "smoke" "Smoke")

if(TEST_SUITE_SMOKE_ROOT AND NOT TEST_SUITE_BENCHMARKING_ONLY)
  if(OPENMP_FOUND)
    message(STATUS "Adding Smoke")
  else()
    message(STATUS "NOT using Smoke because OpenMP was not found")
    return()
  endif()

  foreach (_lang in C)
    if(CMAKE_${_lang}_COMPILER)
	    if(SYSTEM_GPU)
	      if(SYSTEM_GPU STREQUAL "nvidia" OR SYSTEM_GPU STREQUAL "NVIDIA")
	        add_SMOKE(${_lang} NVIDIA_TEST_SUITE_EXPECT_PASS)
  	    elseif(SYSTEM_GPU STREQUAL "amd" OR SYSTEM_GPU STREQUAL "AMD")
		      add_SMOKE(${_lang} AMD_TEST_SUITE_EXPECT_PASS)
  	    elseif(SYSTEM_GPU STREQUAL "intel" OR SYSTEM_GPU STREQUAL "INTEL")
    		  add_SMOKE(${_lang} INTEL_TEST_SUITE_EXPECT_PASS)
  	    else()
		      message("Currently have whitelists for nvidia, amd intel gpus")
	      endif()
     	else()
	      message("Please declare what target gpu, AMD, NVIDIA, or INTEL")
    	endif()
    endif()
  endforeach ()
endif ()
