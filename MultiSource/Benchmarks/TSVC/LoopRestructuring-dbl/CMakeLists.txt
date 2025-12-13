list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS 4350 14)
llvm_multisource(LoopRestructuring-dbl)
set_property(TARGET LoopRestructuring-dbl PROPERTY C_STANDARD 99)
