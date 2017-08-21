# https://www.spec.org/cpu2017/Docs/benchmarks/508.namd_r.html
include(../../SpecCPU2017.cmake)
if (NOT TEST_SUITE_SPEC2017_ROOT)
  return ()
endif ()

speccpu2017_benchmark(RATE)

add_definitions(-DNAMD_DISABLE_SSE)

## test ########################################################################

speccpu2017_run_test(
  --input "${INPUT_all_DIR}/apoa1.input"
  --iterations 1 --output apoa1.test.output
  RUN_TYPE test
)

## train #######################################################################

speccpu2017_run_test(
  --input "${INPUT_all_DIR}/apoa1.input"
  --iterations 7 --output apoa1.train.output
  RUN_TYPE train
)

## ref #########################################################################

speccpu2017_run_test(
  --input "${INPUT_all_DIR}/apoa1.input"
  --output apoa1.ref.output --iterations 65
  RUN_TYPE ref
)

################################################################################

speccpu2017_verify_output(ABSOLUTE_TOLERANCE 0.00005)
speccpu2017_add_executable()
