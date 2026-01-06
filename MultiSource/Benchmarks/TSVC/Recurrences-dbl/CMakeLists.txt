list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS 20000 14)
llvm_multisource(Recurrences-dbl)
set_property(TARGET Recurrences-dbl PROPERTY C_STANDARD 99)
