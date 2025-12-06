# FDRMode test is failing on Darwin because
# `__xray_log_select_mode("xray-fdr")` returns `XRAY_MODE_NOT_FOUND`.

list(APPEND CPPFLAGS -Wl,--gc-sections -fxray-instrument)
list(APPEND LDFLAGS -fxray-instrument)
llvm_test_run()
llvm_test_executable(fdrmode-bench fdrmode-bench.cc)
set_property(TARGET fdrmode-bench PROPERTY CXX_STANDARD 11)
target_link_libraries(fdrmode-bench benchmark)
