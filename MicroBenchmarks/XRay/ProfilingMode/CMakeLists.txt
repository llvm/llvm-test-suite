check_cxx_compiler_flag(-fxray-instrument COMPILER_HAS_FXRAY_INSTRUMENT)
check_cxx_compiler_flag(-fxray-modes=xray-profiling
	COMPILER_HAS_FXRAY_PROFILING)
if(ARCH STREQUAL "x86"
		AND COMPILER_HAS_FXRAY_INSTRUMENT
		AND COMPILER_HAS_FXRAY_PROFILING)
  list(APPEND CPPFLAGS
		-std=c++11 -Wl,--gc-sections
		-fxray-instrument -fxray-modes=xray-profiling)
  list(APPEND LDFLAGS
		-fxray-instrument -fxray-modes=xray-profiling)
  llvm_test_run()
  llvm_test_executable(deep-call-bench deep-call-bench.cc)
  target_link_libraries(deep-call-bench benchmark)
  llvm_test_executable(shallow-call-bench shallow-call-bench.cc)
  target_link_libraries(shallow-call-bench benchmark)
  llvm_test_executable(wide-call-bench wide-call-bench.cc)
  target_link_libraries(wide-call-bench benchmark)
endif()

