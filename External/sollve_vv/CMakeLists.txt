# SOLLVE OpenMP Offloading Validation & Verification Suite
# https://crpl.cis.udel.edu/ompvvsollve/

include(External)

option(TEST_SUITE_SOLLVEVV_FORCE_ALL "Execute all SOLLVE V&V tests, even those known to be unsupported by Clang" OFF)

set(TEST_SUITE_SOLLVEVV_OFFLOADING_CFLAGS "-fopenmp-targets=nvptx64-nvidia-cuda;-Xopenmp-target;-march=sm_70" CACHE STRING "Compiler arguments for OpenMP offloading")
set(TEST_SUITE_SOLLVEVV_OFFLOADING_LDFLAGS "-fopenmp-targets=nvptx64-nvidia-cuda;-Xopenmp-target;-march=sm_70;-lomptarget" CACHE STRING "Linker arguments for OpenMP offloading")

set(TEST_SUITE_SOLLVEVV_EXPECT_PASS
    4.5/offloading_success.cpp
    4.5/offloading_success.c
    4.5/application_kernels/alpaka_complex_template.cpp
    4.5/application_kernels/linked_list.c
    4.5/application_kernels/mmm_target.c
    4.5/application_kernels/mmm_target_parallel_for_simd.c
    4.5/application_kernels/omp_default_device.c
    4.5/application_kernels/qmcpack_target_math.c
    4.5/application_kernels/gemv_target.cpp
    4.5/application_kernels/gemv_target_many_matrices.cpp
    4.5/application_kernels/gemv_target_reduction.cpp
    4.5/application_kernels/gemv_target_teams_dist_par_for.cpp
    4.5/application_kernels/gridmini_map_struct_float_mul.cpp
    4.5/declare_target/test_declare_target_end_declare_target.c
    4.5/declare_target/test_declare_target_extended_list.c
    4.5/declare_target/test_declare_target_link_extended_list.c
    4.5/declare_target/test_declare_target_to_extended_list.c
    4.5/target/test_target_defaultmap.c
    4.5/target/test_target_firstprivate.c
    4.5/target/test_target_if.c
    4.5/target/test_target_map_global_arrays.c
    4.5/target/test_target_map_local_array.c
    4.5/target/test_target_map_pointer.c
    4.5/target/test_target_map_pointer_no_map_type_modifier.c
    4.5/target/test_target_map_scalar_no_map_type_modifier.c
    4.5/target/test_target_map_struct_default.c
    4.5/target/test_target_map_zero_length_pointer.c
    4.5/target/test_target_private.c
    4.5/target/test_target_device.c
    4.5/target_data/test_target_data_if.c
    4.5/target_data/test_target_data_map_alloc.c
    4.5/target_data/test_target_data_map_array_sections.c
    4.5/target_data/test_target_data_map_devices.c
    4.5/target_data/test_target_data_map_from.c
    4.5/target_data/test_target_data_map_to.c
    4.5/target_data/test_target_data_map_to_from.c
    4.5/target_data/test_target_data_pointer_swap.c
    4.5/target_data/test_target_data_use_device_ptr.c
    4.5/target_data/test_target_data_map_classes.cpp
    4.5/target_enter_data/test_target_enter_data_depend.c
    4.5/target_enter_data/test_target_enter_data_devices.c
    4.5/target_enter_data/test_target_enter_data_global_array.c
    4.5/target_enter_data/test_target_enter_data_if.c
    4.5/target_enter_data/test_target_enter_data_malloced_array.c
    4.5/target_enter_data/test_target_enter_data_struct.c
    4.5/target_enter_exit_data/test_target_enter_exit_data_depend.c
    4.5/target_enter_exit_data/test_target_enter_exit_data_devices.c
    4.5/target_enter_exit_data/test_target_enter_exit_data_if.c
    4.5/target_enter_exit_data/test_target_enter_exit_data_map_global_array.c
    4.5/target_enter_exit_data/test_target_enter_exit_data_map_malloced_array.c
    4.5/target_enter_exit_data/test_target_enter_exit_data_struct.c
    4.5/target_enter_exit_data/test_target_enter_exit_data_classes_simple.cpp
    4.5/target_parallel/test_target_parallel.c
    4.5/target_simd/test_target_simd.c
    4.5/target_simd/test_target_simd_collapse.c
    4.5/target_simd/test_target_simd_safelen.c
    4.5/target_simd/test_target_simd_simdlen.c
    4.5/target_teams_distribute/test_target_teams_distribute_collapse.c
    4.5/target_teams_distribute/test_target_teams_distribute_defaultmap.c
    4.5/target_teams_distribute/test_target_teams_distribute_depend_array_section.c
    4.5/target_teams_distribute/test_target_teams_distribute_depend_in_out.c
    4.5/target_teams_distribute/test_target_teams_distribute_depend_list.c
    4.5/target_teams_distribute/test_target_teams_distribute_depend_out_in.c
    4.5/target_teams_distribute/test_target_teams_distribute_depend_out_out.c
    4.5/target_teams_distribute/test_target_teams_distribute_depend_unused_data.c
    4.5/target_teams_distribute/test_target_teams_distribute_dist_schedule.c
    4.5/target_teams_distribute/test_target_teams_distribute_firstprivate.c
    4.5/target_teams_distribute/test_target_teams_distribute_if.c
    4.5/target_teams_distribute/test_target_teams_distribute_lastprivate.c
    4.5/target_teams_distribute/test_target_teams_distribute_num_teams.c
    4.5/target_teams_distribute/test_target_teams_distribute_private.c
    4.5/target_teams_distribute_parallel_for/test_target_teams_distribute_parallel_for.c
    4.5/target_teams_distribute_parallel_for/test_target_teams_distribute_parallel_for_defaultmap.c
    4.5/target_teams_distribute_parallel_for/test_target_teams_distribute_parallel_for_devices.c
    4.5/target_teams_distribute_parallel_for/test_target_teams_distribute_parallel_for_firstprivate.c
    4.5/target_teams_distribute_parallel_for/test_target_teams_distribute_parallel_for_if_no_modifier.c
    4.5/target_teams_distribute_parallel_for/test_target_teams_distribute_parallel_for_if_parallel_modifier.c
    4.5/target_teams_distribute_parallel_for/test_target_teams_distribute_parallel_for_if_target_modifier.c
    4.5/target_teams_distribute_parallel_for/test_target_teams_distribute_parallel_for_map_default.c
    4.5/target_teams_distribute_parallel_for/test_target_teams_distribute_parallel_for_map_from.c
    4.5/target_teams_distribute_parallel_for/test_target_teams_distribute_parallel_for_map_to.c
    4.5/target_teams_distribute_parallel_for/test_target_teams_distribute_parallel_for_map_tofrom.c
    4.5/target_teams_distribute_parallel_for/test_target_teams_distribute_parallel_for_num_teams.c
    4.5/target_teams_distribute_parallel_for/test_target_teams_distribute_parallel_for_num_threads.c
    4.5/target_teams_distribute_parallel_for/test_target_teams_distribute_parallel_for_private.c
    4.5/target_teams_distribute_parallel_for/test_target_teams_distribute_parallel_for_schedule_private.c
    4.5/target_update/test_target_update_depend.c
    4.5/target_update/test_target_update_devices.c
    4.5/target_update/test_target_update_from.c
    4.5/target_update/test_target_update_if.c
    4.5/target_update/test_target_update_to.c
    4.5/task/test_target_and_task_nowait.c
    4.5/task/test_task_target.c
    5.0/atomic/test_atomic_acquire_release.c
    5.0/atomic/test_atomic_hint.c
    5.0/atomic/test_atomic_num_hint.c
    5.0/atomic/test_atomic_num_hint_device.c
    5.0/declare_mapper/test_declare_mapper_target_struct.c
    5.0/declare_target/test_declare_target_device_type_host.c
    5.0/declare_target/test_declare_target_nested.c
    5.0/declare_target/test_declare_target_parallel_for.c
    5.0/declare_variant/test_declare_variant.c
    5.0/flush/test_flush_no_memory_order_clause.c
    5.0/master_taskloop/test_master_taskloop.c
    5.0/master_taskloop_simd/test_master_taskloop_simd.c
    5.0/parallel_for/test_parallel_for_notequals.c
    5.0/parallel_for/test_parallel_for_order_concurrent.c
    5.0/parallel_for_simd/test_parallel_for_simd_atomic.c
    5.0/parallel_master/test_parallel_master.c
    5.0/parallel_master_taskloop/test_parallel_master_taskloop.c
    5.0/parallel_master_taskloop_simd/test_parallel_master_taskloop_simd.c
    5.0/program_control/test_capture_omp_affinity.c
    5.0/program_control/test_omp_get_supported_active_levels.c
    5.0/program_control/test_omp_target_offload_env_DEFAULT.c
    5.0/program_control/test_omp_target_offload_env_DISABLED.c
    5.0/program_control/test_omp_target_offload_env_MANDATORY.c
    5.0/program_control/test_set_and_get_omp_affinity.c
    5.0/requires/test_requires_atomic_default_mem_order_acq_rel.c
    5.0/requires/test_requires_atomic_default_mem_order_relaxed.c
    5.0/requires/test_requires_atomic_default_mem_order_seq_cst.c
    5.0/scan/test_scan.c
    5.0/simd/test_simd_if.c
    5.0/simd/test_simd_nontemporal.c
    5.0/simd/test_simd_order_concurrent.c
    5.0/target/test_target_defaultmap_default.c
    5.0/target/test_target_defaultmap_firstprivate.c
    5.0/target/test_target_defaultmap_none.c
    5.0/target/test_target_defaultmap_to_from_tofrom.c
    5.0/target/test_target_imperfect_loop.c
    5.0/target/test_target_map_with_close_modifier.c
    5.0/target/test_target_mapping_before_alloc.c
    5.0/target/test_target_parallel_for_notequals.c
    5.0/target/test_target_uses_allocators_cgroup.c
    5.0/target/test_target_uses_allocators_default.c
    5.0/target/test_target_uses_allocators_high_bw.c
    5.0/target/test_target_uses_allocators_large_cap.c
    5.0/target/test_target_uses_allocators_low_lat.c
    5.0/target/test_target_uses_allocators_pteam.c
    5.0/target/test_target_uses_allocators_thread.c
    5.0/target_data/test_target_data_use_device_addr.c
    5.0/target_data/test_target_data_use_device_ptr.c
    5.0/target_simd/test_target_simd_if.c
    5.0/target_simd/test_target_simd_nontemporal.c
    5.0/target_simd/test_target_simd_order_concurrent.c
    5.0/target_teams_distribute_parallel_for/test_target_teams_distribute_parallel_for_collapse.c
    5.0/target_teams_distribute_parallel_for_simd/test_target_teams_distribute_parallel_for_simd_atomic.c
    5.0/target_update/test_target_update_mapper_to_discontiguous.c
    5.0/task/test_parallel_for_reduction_task.c
    5.0/task/test_parallel_for_reduction_task_device.c
    5.0/task/test_task_depend_mutexinoutset.c
    5.0/task/test_task_detach.c
    5.0/task/test_task_in_reduction.c
    5.0/task/test_task_in_reduction_dynamically_enclosed.c
    5.0/taskgroup/test_taskgroup_task_reduction.c
    5.0/taskloop/test_taskloop_in_reduction.c
    5.0/taskloop_simd/test_taskloop_simd_in_reduction.c
    5.0/teams/test_team_default_shared.c
    5.0/teams/test_teams.c
    5.0/application_kernels/gridmini_map_class.cpp
    5.0/application_kernels/gridmini_map_struct_array.cpp
    5.0/application_kernels/gridmini_map_struct_float_mul.cpp
    5.0/application_kernels/gridmini_map_template.cpp
    5.0/application_kernels/gridmini_map_template_array.cpp
    5.0/application_kernels/gridmini_ptr.cpp
    5.0/depobj/test_depobj_depend_update_destroy.cpp
    5.0/teams/test_teams_distribute_default_none.c
  )

function (add_sollvevv LANG)
  set(_includedir "${TEST_SUITE_SOLLVEVV_ROOT}/ompvv" )

  if (NOT OPENMP_${LANG}_FOUND)
    message(FATAL_ERROR "OpenMP for ${LANG} not found")
    return ()
  endif ()

  #if (OpenMP_${LANG}_VERSION VERSION_LESS "4.5")
  #  message(FATAL_ERROR "OpenMP version ${OpenMP_${LANG}_VERSION} too old")
  #endif ()

  if ("${LANG}" STREQUAL "C")
    set(_langext ".c")
  elseif ("${LANG}" STREQUAL "CXX")
    set(_langext ".cpp")
  else ()
    message(FATAL_ERROR "Unsupported languge ${LANG}")
  endif ()

  file(GLOB_RECURSE _tests_sources RELATIVE "${TEST_SUITE_SOLLVEVV_ROOT}/tests" "${TEST_SUITE_SOLLVEVV_ROOT}/tests/*${_langext}" )
  foreach (_file IN LISTS _tests_sources)
    get_filename_component(_ext "${_file}" EXT)
    get_filename_component(_basename "${_file}" NAME_WE)
    get_filename_component(_directory "${_file}" DIRECTORY)
    string(REPLACE "." "" _ext "${_ext}")
    string(REPLACE "/" "_" _directory "${_directory}")
    string(REPLACE "." "" _directory "${_directory}")
    set(_name "omptargetvv-${_basename}-${_directory}-${_ext}")

    if (NOT TEST_SUITE_SOLLVEVV_FORCE_ALL AND NOT "${_file}" IN_LIST TEST_SUITE_SOLLVEVV_EXPECT_PASS)
      message(STATUS "Skipping SOLLVE V&V test ${_file}")
      continue ()
    endif ()

    llvm_test_run()

    llvm_test_executable(${_name} "${TEST_SUITE_SOLLVEVV_ROOT}/tests/${_file}")
    target_include_directories(${_name} PRIVATE "${_includedir}")
    target_link_libraries(${_name} PUBLIC OpenMP::OpenMP_${_lang})

    # Add -fopenmp to linker command line; for some reason this is not done by target_link_libraries.
    target_link_options(${_name} PRIVATE ${OpenMP_${LANG}_FLAGS})

    # CMake's find_package(OpenMP) currently does not not introspect flags necessary for offloading.
    target_compile_options(${_name} PUBLIC ${TEST_SUITE_SOLLVEVV_OFFLOADING_CFLAGS})
    target_link_options(${_name} PUBLIC ${TEST_SUITE_SOLLVEVV_OFFLOADING_LDFLAGS})
  endforeach ()
endfunction ()


llvm_externals_find(TEST_SUITE_SOLLVEVV_ROOT "sollve_vv" "OpenMP Offloading Validation & Verification Suite")
if (TEST_SUITE_SOLLVEVV_ROOT AND NOT TEST_SUITE_BENCHMARKING_ONLY)
  if (OPENMP_FOUND)
    message(STATUS "Adding OpenMP Offloading Validiation & Verification")
  else ()
    message(STATUS "NOT using OpenMP Validiation & Verification because OpenMP was not found")
    return ()
  endif ()

  foreach (_lang in C CXX)
    if (CMAKE_${_lang}_COMPILER)
      add_sollvevv(${_lang})
    endif()
  endforeach ()
endif ()
