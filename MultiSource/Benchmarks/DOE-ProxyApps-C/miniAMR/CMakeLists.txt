list(APPEND CPPFLAGS -I.)
list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS --nx 8 --ny 8 --nz 8 --num_tsteps 100)
llvm_multisource(miniAMR)
 
