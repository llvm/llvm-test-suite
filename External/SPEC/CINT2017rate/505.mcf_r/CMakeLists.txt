# https://www.spec.org/cpu2017/Docs/benchmarks/505.mcf_r.html
include(../../SpecCPU2017.cmake)
if (NOT TEST_SUITE_SPEC2017_ROOT)
  return ()
endif ()

speccpu2017_benchmark(RATE)

speccpu2017_add_include_dirs(spec_qsort)

## test ########################################################################

speccpu2017_run_test(
  "${RUN_test_DIR_REL}/inp.in"
  STDOUT inp.out
  RUN_TYPE test
)

## train #######################################################################

speccpu2017_run_test(
  "${RUN_train_DIR_REL}/inp.in"
  STDOUT inp.out
  RUN_TYPE train
)

## ref #########################################################################

speccpu2017_run_test(
  "${RUN_ref_DIR_REL}/inp.in"
  STDOUT inp.out
  RUN_TYPE ref
)

################################################################################

speccpu2017_verify_output()
speccpu2017_add_executable()
speccpu2017_prepare_rundir()
