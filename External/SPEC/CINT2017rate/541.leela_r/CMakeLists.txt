# https://www.spec.org/cpu2017/Docs/benchmarks/541.leela_r.html
include(../../SpecCPU2017.cmake)
if (NOT TEST_SUITE_SPEC2017_ROOT)
  return ()
endif ()

speccpu2017_benchmark(RATE)

speccpu2017_add_include_dirs(.)

## test ########################################################################

speccpu2017_run_test(
  "${INPUT_test_DIR}/test.sgf"
  STDOUT test.out
  RUN_TYPE test
)

## train #######################################################################

speccpu2017_run_test(
  "${INPUT_train_DIR}/train.sgf"
  STDOUT train.out
  RUN_TYPE train
)

## ref #########################################################################

speccpu2017_run_test(
  "${INPUT_ref_DIR}/ref.sgf"
  STDOUT ref.out
  RUN_TYPE ref
)

################################################################################

speccpu2017_verify_output()
speccpu2017_add_executable()
