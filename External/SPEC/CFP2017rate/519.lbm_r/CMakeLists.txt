# https://www.spec.org/cpu2017/Docs/benchmarks/519.lbm_r.html
include(../../SpecCPU2017.cmake)
if (NOT TEST_SUITE_SPEC2017_ROOT)
  return ()
endif ()

speccpu2017_benchmark(RATE)

link_libraries(-lm)

## test ########################################################################

speccpu2017_run_test(
  20 reference.dat 0 1 100_100_130_cf_a.of
  STDOUT lbm.out
  RUN_TYPE test
  SUITE_TYPE rate
)

## train #######################################################################

speccpu2017_run_test(
  300 reference.dat 0 1 100_100_130_cf_b.of
  STDOUT lbm.out
  RUN_TYPE train
  SUITE_TYPE rate
)

## ref #########################################################################

speccpu2017_run_test(
  3000 reference.dat 0 0 100_100_130_ldc.of
  STDOUT lbm.out
  RUN_TYPE ref
  SUITE_TYPE rate
)

################################################################################

# Using IGNORE_WHITESPACE because the reference output consistently uses tabs
# while the program output also uses spaces for indention.
speccpu2017_verify_output(ABSOLUTE_TOLERANCE 0.0000001 IGNORE_WHITESPACE)
speccpu2017_add_executable()
speccpu2017_prepare_rundir()
