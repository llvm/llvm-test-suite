list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS 1670 5)
llvm_multisource(Reductions-flt)
set_property(TARGET Reductions-flt PROPERTY C_STANDARD 99)
