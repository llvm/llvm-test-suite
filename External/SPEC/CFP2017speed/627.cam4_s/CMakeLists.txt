# https://www.spec.org/cpu2017/Docs/benchmarks/627.cam4_s.html
include(../../SpecCPU2017.cmake)
if (NOT TEST_SUITE_SPEC2017_ROOT)
  return ()
endif ()

speccpu2017_benchmark(SPEED ORIGIN 527.cam4_r)

speccpu2017_inherit(../../CFP2017rate/527.cam4_r)

add_definitions(-DUSE_COSP)
