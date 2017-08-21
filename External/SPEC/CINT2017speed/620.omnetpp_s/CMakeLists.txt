# https://www.spec.org/cpu2017/Docs/benchmarks/620.omnetpp_s.html
include(../../SpecCPU2017.cmake)
if (NOT TEST_SUITE_SPEC2017_ROOT)
  return ()
endif ()

speccpu2017_benchmark(SPEED ORIGIN 520.omnetpp_r)
speccpu2017_inherit(../../CINT2017rate/520.omnetpp_r)
