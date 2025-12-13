list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS 9090 14)
llvm_multisource(Symbolics-dbl)
set_property(TARGET Symbolics-dbl PROPERTY C_STANDARD 99)
