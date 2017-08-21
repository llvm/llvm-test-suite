# https://www.spec.org/cpu2017/Docs/benchmarks/644.nab_s.html
include(../../SpecCPU2017.cmake)
if (NOT TEST_SUITE_SPEC2017_ROOT)
  return ()
endif ()

speccpu2017_benchmark(SPEED ORIGIN 544.nab_r)

## ref #########################################################################

speccpu2017_run_test(
  3j1n 20140317 220
  WORKDIR input
  STDOUT 3j1n.out
  RUN_TYPE ref
  SUITE_TYPE speed
)

################################################################################

speccpu2017_inherit(../../CFP2017rate/544.nab_r)
