# https://www.spec.org/cpu2017/Docs/benchmarks/619.lbm_s.html
include(../../SpecCPU2017.cmake)
if (NOT TEST_SUITE_SPEC2017_ROOT)
  return ()
endif ()

speccpu2017_benchmark(SPEED ORIGIN 519.lbm_r)

add_definitions(-DLARGE_WORKLOAD)

## test ########################################################################

speccpu2017_run_test(
  20 reference.dat 0 1 200_200_260_ldc.of
  STDOUT lbm.out
  WORKDIR input
  RUN_TYPE test
  SUITE_TYPE speed
)

## train #######################################################################

speccpu2017_run_test(
  300 reference.dat 0 1 200_200_260_ldc.of
  STDOUT lbm.out
  WORKDIR input
  RUN_TYPE train
  SUITE_TYPE speed
)

## ref #########################################################################

speccpu2017_run_test(
  2000 reference.dat 0 0 200_200_260_ldc.of
  STDOUT lbm.out
  WORKDIR input
  RUN_TYPE ref
  SUITE_TYPE speed
)

################################################################################

speccpu2017_inherit(../../CFP2017rate/519.lbm_r)
