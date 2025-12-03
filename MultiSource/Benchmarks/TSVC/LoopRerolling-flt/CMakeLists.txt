list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS 5260 5)
llvm_multisource(LoopRerolling-flt)
set_property(TARGET LoopRerolling-flt PROPERTY C_STANDARD 99)
