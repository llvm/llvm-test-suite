list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS 10000 14)
llvm_multisource(NodeSplitting-dbl)
set_property(TARGET NodeSplitting-dbl PROPERTY C_STANDARD 99)
