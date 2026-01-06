list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS 50000 14)
llvm_multisource(Packing-dbl)
set_property(TARGET Packing-dbl PROPERTY C_STANDARD 99)
