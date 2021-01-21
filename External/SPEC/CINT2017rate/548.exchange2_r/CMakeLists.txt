# https://www.spec.org/cpu2017/Docs/benchmarks/548.exchange2_r.html
include(../../SpecCPU2017.cmake)
if (NOT TEST_SUITE_SPEC2017_ROOT)
  return ()
endif ()

speccpu2017_benchmark(RATE)

## test ########################################################################

speccpu2017_run_test(
  0
  RUN_TYPE test
)

## train #######################################################################

speccpu2017_run_test(
  1
  RUN_TYPE train
)

## ref #########################################################################

speccpu2017_run_test(
  6
  RUN_TYPE ref
)

################################################################################

speccpu2017_verify_output()
speccpu2017_add_executable()
speccpu2017_prepare_rundir()
