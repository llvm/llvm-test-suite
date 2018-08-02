set(RUN_OPTIONS 10000000 ADC.par)
if(SMALL_PROBLEM_SIZE)
  list(APPEND CPPFLAGS -DSMALL_PROBLEM_SIZE)
endif()
llvm_multisource(dc
  adc.c
  dc.c
  jobcntl.c
  c_print_results.c
  extbuild.c
  rbt.c
)
