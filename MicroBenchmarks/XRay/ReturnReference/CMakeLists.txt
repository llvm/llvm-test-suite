# ReturnReference is currently failing on Darwin.
#
# ld: in section __DATA,xray_instr_map reloc 0: X86_64_RELOC_SUBTRACTOR must
# have r_extern=1 file
# 'MicroBenchmarks/XRay/ReturnReference/CMakeFiles/retref-bench.dir/retref-bench.cc.o'
# for architecture x86_64

list(APPEND CPPFLAGS -std=c++11 -Wl,--gc-sections -fxray-instrument)
list(APPEND LDFLAGS -fxray-instrument)
llvm_test_run()
llvm_test_executable(retref-bench retref-bench.cc)
target_link_libraries(retref-bench benchmark)
