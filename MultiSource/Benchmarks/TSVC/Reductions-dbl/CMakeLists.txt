list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS 1670 14)
llvm_multisource(Reductions-dbl)
set_property(TARGET Reductions-dbl PROPERTY C_STANDARD 99)
