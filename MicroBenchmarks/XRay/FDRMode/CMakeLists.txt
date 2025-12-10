# FDRMode test is failing on Darwin because
# `__xray_log_select_mode("xray-fdr")` returns `XRAY_MODE_NOT_FOUND`.

list(APPEND CPPFLAGS -std=c++11 -Wl,--gc-sections -fxray-instrument)
list(APPEND LDFLAGS -fxray-instrument)
llvm_test_run()
llvm_test_executable(fdrmode-bench fdrmode-bench.cc)
target_link_libraries(fdrmode-bench benchmark)
