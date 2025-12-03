list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS 3450 5)
llvm_multisource(GlobalDataFlow-flt)
set_property(TARGET GlobalDataFlow-flt PROPERTY C_STANDARD 99)
