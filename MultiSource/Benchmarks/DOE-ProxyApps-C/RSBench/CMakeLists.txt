list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS -s small -l 100000 -p 1000 -w 1000)
llvm_multisource(rsbench)
set_property(TARGET rsbench PROPERTY C_STANDARD 99)
