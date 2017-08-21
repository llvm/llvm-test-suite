# https://www.spec.org/cpu2017/Docs/benchmarks/641.leela_s.html
include(../../SpecCPU2017.cmake)
if (NOT TEST_SUITE_SPEC2017_ROOT)
  return ()
endif ()

speccpu2017_benchmark(SPEED ORIGIN 541.leela_r)
speccpu2017_inherit(../../CINT2017rate/541.leela_r)
