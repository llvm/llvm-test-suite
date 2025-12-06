list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS 5260 14)
llvm_multisource(LoopRerolling-dbl)
set_property(TARGET LoopRerolling-dbl PROPERTY C_STANDARD 99)
