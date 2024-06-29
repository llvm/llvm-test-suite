# SOLLVE OpenMP Offloading Validation & Verification Suite
# https://crpl.cis.udel.edu/ompvvsollve/

include(External)

remove_definitions(-w)
remove_definitions(-Werror=date-time)

option(TEST_SUITE_FORCE_ALL "Execute all SOLLVE V&V tests, even those known to be unsupported by Clang" OFF)

set(TEST_SUITE_OFFLOADING_C_FLAGS --offload-arch=native CACHE STRING "Compiler arguments for OpenMP offloading for C")
set(TEST_SUITE_OFFLOADING_CXX_FLAGS --offload-arch=native CACHE STRING "Compiler arguments for OpenMP offloading for CXX")
set(TEST_SUITE_OFFLOADING_Fortran_FLAGS --offload-arch=native CACHE STRING "Compiler arguments for OpenMP offloading for Fortran")
set(TEST_SUITE_OFFLOADING_C_LDFLAGS --offload-arch=native CACHE STRING "Linker arguments for OpenMP offloading")
set(TEST_SUITE_OFFLOADING_CXX_LDFLAGS --offload-arch=native CACHE STRING "Linker arguments for OpenMP offloading")
set(TEST_SUITE_OFFLOADING_Fortran_LDFLAGS --offload-arch=native CACHE STRING "Linker arguments for OpenMP offloading")

set(ALL_LIST_OPTIONS
  AMD
  INTEL
  NVIDIA
  REGRESSION
)

set(FORTRAN
  4.5/application_kernels/declare_target_module.F90
  4.5/application_kernels/declare_target_subroutine.F90
  4.5/offloading_success.F90
  4.5/target_data/test_target_data_if.F90
  4.5/target_data/test_target_data_map_components_default.F90
  4.5/target_data/test_target_data_map_components_from.F90
  4.5/target_data/test_target_data_map_components_to.F90
  4.5/target_data/test_target_data_map_components_tofrom.F90
  4.5/target_data/test_target_data_map_devices.F90
  4.5/target_data/test_target_data_map.F90
  4.5/target_data/test_target_data_map_from_array_sections.F90
  4.5/target_data/test_target_data_map_set_default_device.F90
  4.5/target_data/test_target_data_map_to_array_sections.F90
  4.5/target_enter_data/test_target_enter_data_allocate_array_alloc.F90
  4.5/target_enter_data/test_target_enter_data_allocate_array_to.F90
  4.5/target_enter_data/test_target_enter_data_components_alloc.F90
  4.5/target_enter_data/test_target_enter_data_components_to.F90
  4.5/target_enter_data/test_target_enter_data_devices.F90
  4.5/target_enter_data/test_target_enter_data_if.F90
  4.5/target_enter_data/test_target_enter_data_module_array.F90
  4.5/target_enter_data/test_target_enter_data_set_default_device.F90
  4.5/target_enter_exit_data/test_target_enter_exit_data_allocate_array_alloc_delete.F90
  4.5/target_enter_exit_data/test_target_enter_exit_data_depend.F90
  4.5/target_enter_exit_data/test_target_enter_exit_data_devices.F90
  4.5/target_enter_exit_data/test_target_enter_exit_data_if.F90
  4.5/target_enter_exit_data/test_target_enter_exit_data_module_array.F90
  4.5/target_enter_exit_data/test_target_enter_exit_data_set_default_device.F90
  4.5/target_parallel/test_target_parallel.F90
  4.5/target_simd/test_nested_target_simd.F90
  4.5/target_simd/test_target_simd.F90
  4.5/target_simd/test_target_simd_safelen.F90
  4.5/target_simd/test_target_simd_simdlen.F90
  4.5/target_teams_distribute_parallel_for/test_target_teams_distribute_parallel_for_defaultmap.F90
  4.5/target_teams_distribute_parallel_for/test_target_teams_distribute_parallel_for_devices.F90
  4.5/target_teams_distribute_parallel_for/test_target_teams_distribute_parallel_for.F90
  4.5/target_teams_distribute_parallel_for/test_target_teams_distribute_parallel_for_firstprivate.F90
  4.5/target_teams_distribute_parallel_for/test_target_teams_distribute_parallel_for_if_no_modifier.F90
  4.5/target_teams_distribute_parallel_for/test_target_teams_distribute_parallel_for_if_parallel_modifier.F90
  4.5/target_teams_distribute_parallel_for/test_target_teams_distribute_parallel_for_if_target_modifier.F90
  4.5/target_teams_distribute_parallel_for/test_target_teams_distribute_parallel_for_map_default.F90
  4.5/target_teams_distribute_parallel_for/test_target_teams_distribute_parallel_for_map_from.F90
  4.5/target_teams_distribute_parallel_for/test_target_teams_distribute_parallel_for_map_to.F90
  4.5/target_teams_distribute_parallel_for/test_target_teams_distribute_parallel_for_map_tofrom.F90
  4.5/target_teams_distribute_parallel_for/test_target_teams_distribute_parallel_for_num_teams.F90
  4.5/target_teams_distribute_parallel_for/test_target_teams_distribute_parallel_for_num_threads.F90
  4.5/target_teams_distribute_parallel_for/test_target_teams_distribute_parallel_for_private.F90
  4.5/target_teams_distribute_parallel_for/test_target_teams_distribute_parallel_for_thread_limit.F90
  4.5/target_teams_distribute/test_target_teams_distribute_collapse.F90
  4.5/target_teams_distribute/test_target_teams_distribute_default_firstprivate.F90
  4.5/target_teams_distribute/test_target_teams_distribute_defaultmap.F90
  4.5/target_teams_distribute/test_target_teams_distribute_default_none.F90
  4.5/target_teams_distribute/test_target_teams_distribute_default_private.F90
  4.5/target_teams_distribute/test_target_teams_distribute_default_shared.F90
  4.5/target_teams_distribute/test_target_teams_distribute_depend_array_section.F90
  4.5/target_teams_distribute/test_target_teams_distribute_depend_disjoint_section.F90
  4.5/target_teams_distribute/test_target_teams_distribute_depend_in_in.F90
  4.5/target_teams_distribute/test_target_teams_distribute_depend_in_out.F90
  4.5/target_teams_distribute/test_target_teams_distribute_depend_list.F90
  4.5/target_teams_distribute/test_target_teams_distribute_depend_out_in.F90
  4.5/target_teams_distribute/test_target_teams_distribute_depend_out_out.F90
  4.5/target_teams_distribute/test_target_teams_distribute_depend_unused_data.F90
  4.5/target_teams_distribute/test_target_teams_distribute_device.F90
  4.5/target_teams_distribute/test_target_teams_distribute_dist_schedule.F90
  4.5/target_teams_distribute/test_target_teams_distribute.F90
  4.5/target_teams_distribute/test_target_teams_distribute_firstprivate.F90
  4.5/target_teams_distribute/test_target_teams_distribute_if.F90
  4.5/target_teams_distribute/test_target_teams_distribute_lastprivate.F90
  4.5/target_teams_distribute/test_target_teams_distribute_map.F90
  4.5/target_teams_distribute/test_target_teams_distribute_nowait.F90
  4.5/target_teams_distribute/test_target_teams_distribute_num_teams.F90
  4.5/target_teams_distribute/test_target_teams_distribute_private.F90
  4.5/target_teams_distribute/test_target_teams_distribute_reduction_add.F90
  4.5/target_teams_distribute/test_target_teams_distribute_reduction_and.F90
  4.5/target_teams_distribute/test_target_teams_distribute_reduction_bitand.F90
  4.5/target_teams_distribute/test_target_teams_distribute_reduction_bitor.F90
  4.5/target_teams_distribute/test_target_teams_distribute_reduction_bitxor.F90
  4.5/target_teams_distribute/test_target_teams_distribute_reduction_eqv.F90
  4.5/target_teams_distribute/test_target_teams_distribute_reduction_max.F90
  4.5/target_teams_distribute/test_target_teams_distribute_reduction_min.F90
  4.5/target_teams_distribute/test_target_teams_distribute_reduction_multiply.F90
  4.5/target_teams_distribute/test_target_teams_distribute_reduction_neqv.F90
  4.5/target_teams_distribute/test_target_teams_distribute_reduction_or.F90
  4.5/target_teams_distribute/test_target_teams_distribute_reduction_sub.F90
  4.5/target_teams_distribute/test_target_teams_distribute_shared.F90
  4.5/target_teams_distribute/test_target_teams_distribute_thread_limit.F90
  4.5/target/test_target_defaultmap.F90
  4.5/target/test_target_depends.F90
  4.5/target/test_target_device.F90
  4.5/target/test_target_firstprivate.F90
  4.5/target/test_target_if.F90
  4.5/target/test_target_map_array_default.F90
  4.5/target/test_target_map_components_default.F90
  4.5/target/test_target_map_module_array.F90
  4.5/target/test_target_map_pointer_default.F90
  4.5/target/test_target_map_pointer.F90
  4.5/target/test_target_map_program_arrays.F90
  4.5/target/test_target_map_scalar_default.F90
  4.5/target/test_target_map_subroutines_arrays.F90
  4.5/target/test_target_private.F90
  4.5/target_update/test_target_update_devices.F90
  4.5/target_update/test_target_update_from.F90
  4.5/target_update/test_target_update_if.F90
  4.5/target_update/test_target_update_to.F90
  5.0/allocate/test_allocate_allocator.F90
  5.0/atomic/test_atomic_acquire_release.F90
  5.0/atomic/test_atomic_hint.F90
  5.0/atomic/test_atomic_num_hint_device.F90
  5.0/atomic/test_atomic_num_hint.F90
  5.0/declare_mapper/test_declare_mapper_target_struct.F90
  5.0/declare_target/test_declare_target_device_type_any.F90
  5.0/declare_target/test_declare_target_device_type_host.F90
  5.0/declare_target/test_declare_target_device_type_nohost.F90
  5.0/declare_target/test_declare_target_nested_functions.F90
  5.0/declare_target/test_declare_target_parallel_for.F90
  5.0/declare_variant/test_declare_variant.F90
  5.0/loop/test_loop_bind_device.F90
  5.0/loop/test_loop_bind.F90
  5.0/loop/test_loop_collapse_device.F90
  5.0/loop/test_loop_collapse.F90
  5.0/loop/test_loop_lastprivate_device.F90
  5.0/loop/test_loop_lastprivate.F90
  5.0/loop/test_loop_nested_device.F90
  5.0/loop/test_loop_nested.F90
  5.0/loop/test_loop_order_concurrent_device.F90
  5.0/loop/test_loop_order_concurrent.F90
  5.0/loop/test_loop_private_device.F90
  5.0/loop/test_loop_private.F90
  5.0/loop/test_loop_reduction_add_device.F90
  5.0/loop/test_loop_reduction_add.F90
  5.0/loop/test_loop_reduction_and_device.F90
  5.0/loop/test_loop_reduction_and.F90
  5.0/loop/test_loop_reduction_bitand_device.F90
  5.0/loop/test_loop_reduction_bitand.F90
  5.0/loop/test_loop_reduction_bitor_device.F90
  5.0/loop/test_loop_reduction_bitor.F90
  5.0/loop/test_loop_reduction_bitxor_device.F90
  5.0/loop/test_loop_reduction_bitxor.F90
  5.0/loop/test_loop_reduction_max_device.F90
  5.0/loop/test_loop_reduction_max.F90
  5.0/loop/test_loop_reduction_min_device.F90
  5.0/loop/test_loop_reduction_min.F90
  5.0/loop/test_loop_reduction_multiply_device.F90
  5.0/loop/test_loop_reduction_multiply.F90
  5.0/loop/test_loop_reduction_or_device.F90
  5.0/loop/test_loop_reduction_or.F90
  5.0/loop/test_loop_reduction_subtract_device.F90
  5.0/loop/test_loop_reduction_subtract.F90
  5.0/master_taskloop_simd/test_master_taskloop_simd_device.F90
  5.0/master_taskloop_simd/test_master_taskloop_simd.F90
  5.0/master_taskloop/test_master_taskloop_device.F90
  5.0/master_taskloop/test_master_taskloop.F90
  5.0/metadirective/test_metadirective_arch_is_nvidia.F90
  5.0/metadirective/test_metadirective_arch_nvidia_or_amd.F90
  5.0/parallel_for_simd/test_parallel_for_simd_atomic.F90
  5.0/parallel_for/test_parallel_for_allocate.F90
  5.0/parallel_for/test_parallel_for_order_concurrent.F90
  5.0/parallel_master_taskloop_simd/test_parallel_master_taskloop_simd_device.F90
  5.0/parallel_master_taskloop_simd/test_parallel_master_taskloop_simd.F90
  5.0/parallel_master_taskloop/test_parallel_master_taskloop_device.F90
  5.0/parallel_master_taskloop/test_parallel_master_taskloop.F90
  5.0/parallel_master/test_parallel_master_device.F90
  5.0/parallel_master/test_parallel_master.F90
  5.0/requires/test_requires_atomic_default_mem_order_acq_rel.F90
  5.0/requires/test_requires_atomic_default_mem_order_relaxed.F90
  5.0/requires/test_requires_atomic_default_mem_order_seq_cst.F90
  5.0/requires/test_requires_dynamic_allocators.F90
  5.0/requires/test_requires_reverse_offload.F90
  5.0/requires/test_requires_unified_shared_memory.F90
  5.0/requires/test_requires_unified_shared_memory_heap.F90
  5.0/requires/test_requires_unified_shared_memory_heap_is_device_ptr.F90
  5.0/requires/test_requires_unified_shared_memory_heap_map.F90
  5.0/requires/test_requires_unified_shared_memory_stack.F90
  5.0/requires/test_requires_unified_shared_memory_stack_is_device_ptr.F90
  5.0/requires/test_requires_unified_shared_memory_stack_map.F90
  5.0/requires/test_requires_unified_shared_memory_static.F90
  5.0/requires/test_requires_unified_shared_memory_static_is_device_ptr.F90
  5.0/requires/test_requires_unified_shared_memory_static_map.F90
  5.0/simd/test_simd_if.F90
  5.0/simd/test_simd_nontemporal.F90
  5.0/simd/test_simd_order_concurrent.F90
  5.0/target_data/test_target_data_use_device_addr.F90
  5.0/target_data/test_target_data_use_device_ptr.F90
  5.0/target_simd/test_target_simd_if.F90
  5.0/target_simd/test_target_simd_nontemporal.F90
  5.0/target_simd/test_target_simd_order_concurrent.F90
  5.0/target_teams_distribute_parallel_for_simd/test_target_teams_distribute_parallel_for_simd_atomic.F90
  5.0/target_teams_distribute_parallel_for/test_target_teams_distribute_parallel_for_collapse.F90
  5.0/target_teams_distribute/test_target_teams_distribute_reduction_add.F90
  5.0/target_teams_distribute/test_target_teams_distribute_reduction_and.F90
  5.0/target_teams_distribute/test_target_teams_distribute_reduction_bitand.F90
  5.0/target_teams_distribute/test_target_teams_distribute_reduction_bitor.F90
  5.0/target_teams_distribute/test_target_teams_distribute_reduction_bitxor.F90
  5.0/target_teams_distribute/test_target_teams_distribute_reduction_eqv.F90
  5.0/target_teams_distribute/test_target_teams_distribute_reduction_max.F90
  5.0/target_teams_distribute/test_target_teams_distribute_reduction_min.F90
  5.0/target_teams_distribute/test_target_teams_distribute_reduction_multiply.F90
  5.0/target_teams_distribute/test_target_teams_distribute_reduction_neqv.F90
  5.0/target_teams_distribute/test_target_teams_distribute_reduction_or.F90
  5.0/target_teams_distribute/test_target_teams_distribute_reduction_sub.F90
  5.0/target/test_target_allocate.F90
  5.0/target/test_target_defaultmap_default.F90
  5.0/target/test_target_defaultmap_firstprivate.F90
  5.0/target/test_target_defaultmap_none.F90
  5.0/target/test_target_defaultmap_to_from_tofrom.F90
  5.0/target/test_target_device.F90
  5.0/target/test_target_imperfect_loop.F90
  5.0/target/test_target_in_reduction.F90
  5.0/target/test_target_mapping_before_alloc.F90
  5.0/target/test_target_map_with_close_modifier.F90
  5.0/target/test_target_task_depend_mutexinoutset.F90
  5.0/target/test_target_uses_allocators_cgroup.F90
  5.0/target/test_target_uses_allocators_const.F90
  5.0/target/test_target_uses_allocators_default.F90
  5.0/target/test_target_uses_allocators_high_bw.F90
  5.0/target/test_target_uses_allocators_large_cap.F90
  5.0/target/test_target_uses_allocators_low_lat.F90
  5.0/target/test_target_uses_allocators_pteam.F90
  5.0/target/test_target_uses_allocators_thread.F90
  5.0/target_update/test_target_update_mapper_from_discontiguous.F90
  5.0/target_update/test_target_update_mapper_to_discontiguous.F90
  5.0/taskloop/test_taskloop_in_reduction_device.F90
  5.0/taskloop/test_taskloop_in_reduction.F90
  5.0/taskloop/test_taskloop_reduction.F90
  5.0/task/test_task_affinity_device.F90
  5.0/task/test_task_affinity.F90
  5.0/task/test_task_detach.F90
  5.0/teams/test_team_default_shared.F90
  5.0/teams/test_teams_distribute_default_none.F90
  5.0/teams/test_teams.F90
  5.1/atomic/test_atomic_compare_device.F90
  5.1/atomic/test_atomic_compare.F90
  5.1/atomic/test_atomic_fail_acquire.F90
  5.1/atomic/test_atomic_fail_relaxed.F90
  5.1/masked/test_masked.F90
  5.1/masked/test_masked_filter.F90
  5.1/requires/test_requires_unified_shared_memory_heap_is_device_ptr.F90
  5.1/requires/test_requires_unified_shared_memory_stack_is_device_ptr.F90
  5.1/requires/test_requires_unified_shared_memory_static_is_device_ptr.F90
  5.1/target/test_target_defaultmap_present_aggregate.F90
  5.1/target/test_target_defaultmap_present.F90
  5.1/target/test_target_defaultmap_present_scalar.F90
  5.1/target/test_target_has_device_addr.F90
  5.1/target/test_target_map_iterators.F90
  5.1/target/test_target_map_with_present_modifier.F90
  5.1/target/test_target_memcpy_rect_async_depobj.F90
  5.1/target/test_target_memcpy_rect_async_no_obj.F90
  5.1/target_update/test_target_update_iterator.F90
  5.1/teams/test_target_teams_default_firstprivate.F90
  5.2/implementation_defined/test_ompx_free.F90
  5.2/metadirective/test_fortran_pure_nothing.F90
  5.2/misc/test_print_in_target_region.F90
  5.2/target_enter_data/test_target_enter_data_map.F90
)

set(CHOOSEN_LISTS)

set(REGRESSION)
set(INTEL)

include(sollvevv_nvidia_tests.cmake)
include(sollvevv_amd_tests.cmake)

function (add_sollvevv LANG)
  set(_includedir "${TEST_SUITE_SOLLVEVV_ROOT}/ompvv" )

  if ("${LANG}" STREQUAL "Fortran" AND NOT TEST_SUITE_FORTRAN)
    return ()
  endif ()

  if (NOT OpenMP_${LANG}_FOUND)
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
  elseif ("${LANG}" STREQUAL "Fortran")
    set(_langext ".F90")
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

    if (NOT TEST_SUITE_FORCE_ALL AND NOT "${_file}" IN_LIST CHOOSEN_LISTS)
      message(STATUS "Skipping SOLLVE V&V test ${_file}")
      continue ()
    endif ()

    # Create a directory for the test
    set(test_dir "${CMAKE_BINARY_DIR}/${_name}")
    file(MAKE_DIRECTORY ${test_dir})

    llvm_test_run()

    llvm_test_executable(${_name} "${TEST_SUITE_SOLLVEVV_ROOT}/tests/${_file}")
    target_include_directories(${_name} PRIVATE "${_includedir}")
    target_link_libraries(${_name} PUBLIC OpenMP::OpenMP_${_lang} m)

    # Add -fopenmp to linker command line; for some reason this is not done by target_link_libraries.
    target_link_options(${_name} PRIVATE ${OpenMP_${LANG}_FLAGS})

    set_target_properties(${_name} PROPERTIES Fortran_MODULE_DIRECTORY ${test_dir})

    # CMake's find_package(OpenMP) currently does not not introspect flags necessary for offloading.
    target_compile_options(${_name} PUBLIC ${TEST_SUITE_OFFLOADING_${LANG}_FLAGS})

    target_link_options(${_name} PUBLIC ${TEST_SUITE_OFFLOADING_${LANG}_LDFLAGS})
  endforeach ()
endfunction ()


llvm_externals_find(TEST_SUITE_SOLLVEVV_ROOT "sollve_vv" "OpenMP Offloading Validation & Verification Suite")

if(TEST_SUITE_SOLLVEVV_ROOT AND NOT TEST_SUITE_BENCHMARKING_ONLY)
  if(OpenMP_FOUND)
    message(STATUS "Adding OpenMP Offloading Validiation & Verification")
  else()
    message(STATUS "NOT using OpenMP Validiation & Verification because OpenMP was not found")
    return()
  endif()

  if(TEST_SUITE_FORCE_ALL AND TEST_SUITE_FORTRAN)
    list(APPEND CHOOSEN_LISTS ${FORTRAN})
    message(STATUS "adding FORTRAN")
  endif()

  list(REMOVE_DUPLICATES SYSTEM_GPU)
  foreach(list_option ${SYSTEM_GPU})
    string(TOUPPER ${list_option} list_option)
    if(list_option IN_LIST ALL_LIST_OPTIONS)
      if(list_option STREQUAL "AMD")
        list(APPEND CHOOSEN_LISTS ${AMD})
        message(STATUS "adding AMD")
      endif()
      if(list_option STREQUAL "NVIDIA")
        list(APPEND CHOOSEN_LISTS ${NVIDIA})
        message(STATUS "adding NVIDIA")
      endif()
      if(list_option STREQUAL "INTEL")
        list(APPEND CHOOSEN_LISTS ${INTEL})
        message(STATUS "adding INTEL")
      endif()
      if(list_option STREQUAL "REGRESSION")
        list(APPEND CHOOSEN_LISTS ${REGRESSION})
        message(STATUS "adding REGRESSION")
      endif()
    else()
      message(STATUS "Option is unrecognized (${list_option})")
    endif()
  endforeach()
  list(REMOVE_DUPLICATES CHOOSEN_LISTS)

  foreach (_lang in C CXX Fortran)
    if(CMAKE_${_lang}_COMPILER)
      add_sollvevv(${_lang})
    endif()
  endforeach ()
endif ()
