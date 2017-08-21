# https://www.spec.org/cpu2017/Docs/benchmarks/631.deepsjeng_s.html
include(../../SpecCPU2017.cmake)
if (NOT TEST_SUITE_SPEC2017_ROOT)
  return ()
endif ()

speccpu2017_benchmark(SPEED ORIGIN 531.deepsjeng_r)

add_definitions(-DBIG_MEMORY)

speccpu2017_inherit(../../CINT2017rate/531.deepsjeng_r)
