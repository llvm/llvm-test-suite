list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS 9090 5)
llvm_multisource(Symbolics-flt)
set_property(TARGET Symbolics-flt PROPERTY C_STANDARD 99)
