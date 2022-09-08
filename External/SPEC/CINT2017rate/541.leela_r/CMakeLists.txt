# https://www.spec.org/cpu2017/Docs/benchmarks/541.leela_r.html
include(../../SpecCPU2017.cmake)
if (NOT TEST_SUITE_SPEC2017_ROOT)
  return ()
endif ()

speccpu2017_benchmark(RATE)

speccpu2017_add_include_dirs(.)

## test ########################################################################

speccpu2017_run_test(
  "${RUN_test_DIR_REL}/test.sgf"
  STDOUT test.out
  RUN_TYPE test
)

## train #######################################################################

speccpu2017_run_test(
  "${RUN_train_DIR_REL}/train.sgf"
  STDOUT train.out
  RUN_TYPE train
)

## ref #########################################################################

speccpu2017_run_test(
  "${RUN_ref_DIR_REL}/ref.sgf"
  STDOUT ref.out
  RUN_TYPE ref
)

################################################################################

speccpu2017_verify_output()
speccpu2017_add_executable()
set_property(TARGET ${PROG} PROPERTY CXX_STANDARD 14)
speccpu2017_prepare_rundir()
