# https://www.spec.org/cpu2017/Docs/benchmarks/621.wrf_s.html
include(../../SpecCPU2017.cmake)
if (NOT TEST_SUITE_SPEC2017_ROOT)
  return ()
endif ()

speccpu2017_benchmark(SPEED ORIGIN 521.wrf_r)

speccpu2017_inherit(../../CFP2017rate/521.wrf_r)
