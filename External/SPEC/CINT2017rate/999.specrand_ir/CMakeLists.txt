# https://www.spec.org/cpu2017/Docs/benchmarks/999.specrand_ir.html
include(../../SpecCPU2017.cmake)
if (NOT TEST_SUITE_SPEC2017_ROOT)
  return ()
endif ()

speccpu2017_benchmark(RATE)

speccpu2017_add_include_dirs(specrand-common)

## test ########################################################################

speccpu2017_run_test(
  324342 24239
  STDOUT rand.24239.out
  RUN_TYPE test
)

## train #######################################################################

speccpu2017_run_test(
  1 11
  STDOUT rand.11.out
  RUN_TYPE train
)

## ref #########################################################################

speccpu2017_run_test(
  1255432124 234923
  STDOUT rand.234923.out
  RUN_TYPE ref
)

################################################################################

speccpu2017_verify_output()
speccpu2017_add_executable()
speccpu2017_prepare_rundir()
