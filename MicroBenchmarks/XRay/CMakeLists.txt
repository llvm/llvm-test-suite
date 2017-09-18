check_cxx_compiler_flag(-fxray-instrument COMPILER_HAS_FXRAY_INSTRUMENT)
if(ARCH STREQUAL "x86" AND COMPILER_HAS_FXRAY_INSTRUMENT)
  file(COPY lit.local.cfg DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

  list(APPEND CPPFLAGS -std=c++11 -Wl,--gc-sections -fxray-instrument)
  list(APPEND LDFLAGS -fxray-instrument)
  llvm_test_run(--benchmark_filter=dummy_skip_ignore)
  llvm_test_executable(retref-bench retref-bench.cc)
  target_link_libraries(retref-bench benchmark)

  file(COPY retref-bench_BM_ReturnNeverInstrumented.test
       DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
  file(COPY retref-bench_BM_ReturnInstrumentedUnPatched.test
       DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
  file(COPY retref-bench_BM_ReturnInstrumentedPatchedThenUnpatched.test
       DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
  file(COPY retref-bench_BM_ReturnInstrumentedPatched.test
       DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
  file(COPY retref-bench_BM_RDTSCP_Cost.test
       DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
  file(COPY retref-bench_BM_ReturnInstrumentedPatchedWithLogHandler.test
       DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
endif()
