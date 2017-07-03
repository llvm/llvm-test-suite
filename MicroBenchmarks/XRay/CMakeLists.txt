check_cxx_compiler_flag(-fxray-instrument COMPILER_HAS_FXRAY_INSTRUMENT)
if("${ARCH}" STREQUAL "x86" AND ${COMPILER_HAS_FXRAY_INSTRUMENT})
  file(COPY lit.local.cfg DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")

  list(APPEND CPPFLAGS -std=c++11 -Wl,--gc-sections -fxray-instrument)
  set(Source retref-bench.cc)
  list(APPEND LDFLAGS -fxray-instrument)
  set(RUN_OPTIONS --benchmark_repetitions=10 --benchmark_report_aggregates_only=true)

  set(PROG retref-bench)
  llvm_multisource()
  target_link_libraries(retref-bench benchmark)
endif()
