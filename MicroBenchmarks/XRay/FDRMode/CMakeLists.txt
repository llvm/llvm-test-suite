check_cxx_compiler_flag(-fxray-instrument COMPILER_HAS_FXRAY_INSTRUMENT)
if(ARCH STREQUAL "x86" AND COMPILER_HAS_FXRAY_INSTRUMENT)
  file(COPY lit.local.cfg DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

  list(APPEND CPPFLAGS -std=c++11 -Wl,--gc-sections -fxray-instrument)
  list(APPEND LDFLAGS -fxray-instrument)
  llvm_test_run(--benchmark_filter=dummy_skip_ignore)
  llvm_test_executable(fdrmode-bench fdrmode-bench.cc)
  target_link_libraries(fdrmode-bench benchmark)

  file(COPY fdrmode-bench_BM_XRayFDRMultiThreaded_1_thread.test
       DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
  file(COPY fdrmode-bench_BM_XRayFDRMultiThreaded_2_thread.test
       DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
  file(COPY fdrmode-bench_BM_XRayFDRMultiThreaded_4_thread.test
       DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
  file(COPY fdrmode-bench_BM_XRayFDRMultiThreaded_8_thread.test
       DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
  file(COPY fdrmode-bench_BM_XRayFDRMultiThreaded_16_thread.test
       DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
  file(COPY fdrmode-bench_BM_XRayFDRMultiThreaded_32_thread.test
       DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
endif()
