# https://www.spec.org/cpu2017/Docs/benchmarks/603.bwaves_s.html
include(../../SpecCPU2017.cmake)
if (NOT TEST_SUITE_SPEC2017_ROOT)
  return ()
endif ()

speccpu2017_benchmark(SPEED ORIGIN 503.bwaves_r)

speccpu2017_inherit(../../CFP2017rate/503.bwaves_r)
