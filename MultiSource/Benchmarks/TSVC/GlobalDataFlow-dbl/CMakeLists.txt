list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS 3450 14)
llvm_multisource(GlobalDataFlow-dbl)
set_property(TARGET GlobalDataFlow-dbl PROPERTY C_STANDARD 99)
