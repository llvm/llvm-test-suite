list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS 10000 5)
llvm_multisource(NodeSplitting-flt)
set_property(TARGET NodeSplitting-flt PROPERTY C_STANDARD 99)
