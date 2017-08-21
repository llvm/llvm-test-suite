# https://www.spec.org/cpu2017/Docs/benchmarks/998.specrand_is.html
include(../../SpecCPU2017.cmake)
if (NOT TEST_SUITE_SPEC2017_ROOT)
  return ()
endif ()

speccpu2017_benchmark(SPEED ORIGIN 999.specrand_ir)
speccpu2017_inherit(../../CINT2017rate/999.specrand_ir)
