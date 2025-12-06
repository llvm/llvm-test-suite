list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS 4160 14)
llvm_multisource(Expansion-dbl)
set_property(TARGET Expansion-dbl PROPERTY C_STANDARD 99)
