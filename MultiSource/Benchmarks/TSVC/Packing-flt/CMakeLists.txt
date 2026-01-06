list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS 50000 5)
llvm_multisource(Packing-flt)
set_property(TARGET Packing-flt PROPERTY C_STANDARD 99)
