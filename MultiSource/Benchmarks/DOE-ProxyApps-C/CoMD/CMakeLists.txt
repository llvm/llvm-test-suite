list(APPEND CFLAGS -DDOUBLE)
list(APPEND LDFLAGS -lm)

set(RUN_OPTIONS -e -x 10 -y 10 -z 10 --potDir .)
llvm_multisource(CoMD)
set_property(TARGET CoMD PROPERTY C_STANDARD 99)
llvm_test_data(CoMD Cu_u6.eam) 
