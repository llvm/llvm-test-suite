# https://www.spec.org/cpu2017/Docs/benchmarks/503.bwaves_r.html
include(../../SpecCPU2017.cmake)
if (NOT TEST_SUITE_SPEC2017_ROOT)
  return ()
endif ()

speccpu2017_benchmark(RATE)

## test ########################################################################

speccpu2017_run_test(
  < "${RUN_test_DIR_REL}/bwaves_1.in"
  STDOUT bwaves_1.out
  RUN_TYPE test
)

speccpu2017_run_test(
  < "${RUN_test_DIR_REL}/bwaves_2.in"
  STDOUT bwaves_2.out
  RUN_TYPE test
)

## train #######################################################################

speccpu2017_run_test(
  < "${RUN_train_DIR_REL}/bwaves_1.in"
  STDOUT bwaves_1.out
  RUN_TYPE train
)

speccpu2017_run_test(
  < "${RUN_train_DIR_REL}/bwaves_2.in"
  STDOUT bwaves_2.out
  RUN_TYPE train
)

## ref #########################################################################

speccpu2017_run_test(
  < "${RUN_ref_DIR_REL}/bwaves_1.in"
  STDOUT bwaves_1.out
  RUN_TYPE ref
)

speccpu2017_run_test(
  < "${RUN_ref_DIR_REL}/bwaves_2.in"
  STDOUT bwaves_2.out
  RUN_TYPE ref
)

speccpu2017_run_test(
  < "${RUN_ref_DIR_REL}/bwaves_3.in"
  STDOUT bwaves_3.out
  RUN_TYPE ref
)

speccpu2017_run_test(
  < "${RUN_ref_DIR}/bwaves_4.in"
  STDOUT bwaves_4.out
  RUN_TYPE ref
)


################################################################################

speccpu2017_verify_output()
speccpu2017_add_executable()
speccpu2017_prepare_rundir()
