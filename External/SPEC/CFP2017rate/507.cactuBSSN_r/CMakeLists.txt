# https://www.spec.org/cpu2017/Docs/benchmarks/507.cactuBSSN_r.html
include(../../SpecCPU2017.cmake)
if (NOT TEST_SUITE_SPEC2017_ROOT)
  return ()
endif ()

speccpu2017_benchmark(RATE)

speccpu2017_add_include_dirs(
  include
)

## test ########################################################################

speccpu2017_run_test(
  spec_test.par
  STDOUT spec_test.out
  RUN_TYPE test
)


## train #######################################################################

speccpu2017_run_test(
  spec_train.par
  STDOUT spec_train.out
  RUN_TYPE train
)

## ref #########################################################################

speccpu2017_run_test(
  spec_ref.par
  STDOUT spec_ref.out
  RUN_TYPE ref
)

################################################################################

speccpu2017_verify_output(ABSOLUTE_TOLERANCE 0.0000000000005)
speccpu2017_add_executable()

# must come after speccpu2017_add_executable() which defines ${PROG} as a TARGET
set_property(TARGET ${PROG} PROPERTY C_STANDARD 99)

# Preprocessing and compiler flags depend on programming language type.
target_compile_definitions(${PROG} PRIVATE $<$<COMPILE_LANGUAGE:Fortran>:FCODE>)
target_compile_definitions(${PROG} PRIVATE $<$<COMPILE_LANGUAGE:C>:CCODE>)
target_compile_definitions(${PROG} PRIVATE $<$<COMPILE_LANGUAGE:CXX>:CCODE CCTK_DISABLE_RESTRICT=1>)

# Copy the input data to the rundir
speccpu2017_prepare_rundir()
