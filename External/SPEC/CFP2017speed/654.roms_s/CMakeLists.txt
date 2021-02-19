# https://www.spec.org/cpu2017/Docs/benchmarks/654.roms_s.html
include(../../SpecCPU2017.cmake)
if (NOT TEST_SUITE_SPEC2017_ROOT)
  return ()
endif ()

speccpu2017_benchmark(SPEED ORIGIN 554.roms_r)

speccpu2017_inherit(../../CFP2017rate/554.roms_r)
