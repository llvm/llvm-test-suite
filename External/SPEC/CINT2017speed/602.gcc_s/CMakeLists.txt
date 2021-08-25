# https://www.spec.org/cpu2017/Docs/benchmarks/602.gcc_s.html
include(../../SpecCPU2017.cmake)
if (NOT TEST_SUITE_SPEC2017_ROOT)
  return ()
endif ()

speccpu2017_benchmark(SPEED ORIGIN 502.gcc_r)

## ref #########################################################################

speccpu2017_run_test(
  "${RUN_ref_DIR_REL}/gcc-pp.c" -O5 -fipa-pta -o gcc-pp.opts-O5_-fipa-pta.s
  RUN_TYPE ref
  SUITE_TYPE speed
)

speccpu2017_run_test(
  "${RUN_ref_DIR_REL}/gcc-pp.c" -O5 -finline-limit=1000 -fselective-scheduling
    -fselective-scheduling2 -o gcc-pp.opts-O5_-finline-limit_1000_-fselective-scheduling_-fselective-scheduling2.s
  RUN_TYPE ref
  SUITE_TYPE speed
)

speccpu2017_run_test(
  "${RUN_ref_DIR_REL}/gcc-pp.c" -O5 -finline-limit=24000 -fgcse -fgcse-las
    -fgcse-lm -fgcse-sm -o gcc-pp.opts-O5_-finline-limit_24000_-fgcse_-fgcse-las_-fgcse-lm_-fgcse-sm.s
  RUN_TYPE ref
  SUITE_TYPE speed
)

################################################################################

speccpu2017_inherit(../../CINT2017rate/502.gcc_r)
