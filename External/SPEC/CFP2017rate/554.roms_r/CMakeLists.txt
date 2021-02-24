# https://www.spec.org/cpu2017/Docs/benchmarks/554.roms_r.html
include(../../SpecCPU2017.cmake)
if (NOT TEST_SUITE_SPEC2017_ROOT)
  return ()
endif ()

ninja_required()

speccpu2017_benchmark(RATE)

speccpu2017_add_include_dirs(.)

# SPEC benchmark uses customized version of filepp, called specpp.
# However, these additional filepp flags do not make any impact
# to the benchmark results. This note serves a a reminder.
# set(MODULE_SPECPP_DIR "${TEST_SUITE_SPEC2017_ROOT}/bin/modules.specpp")
# add_definitions(-w -m literal-single.pm -m c-comment.pm)

add_definitions(-DBENCHMARK -DNestedGrids=1 -DNO_GETTIMEOFDAY)
  
## test ########################################################################

speccpu2017_run_test(
  < ocean_benchmark0.in.x
  STDOUT ocean_benchmark0.log
  STDERR ocean_benchmark0.err
  RUN_TYPE test
)

## train #######################################################################

speccpu2017_run_test(
  < ocean_benchmark1.in.x
  STDOUT ocean_benchmark1.log
  STDERR ocean_benchmark1.err  
  RUN_TYPE train
)

## ref #########################################################################

speccpu2017_run_test(
  < ocean_benchmark2.in.x
  STDOUT ocean_benchmark2.log
  STDERR ocean_benchmark2.err
  RUN_TYPE ref
)

################################################################################

# ROMS has both relative and absolute tolerances
speccpu2017_verify_output(RELATIVE_TOLERANCE 1.0e-7 ABSOLUTE_TOLERANCE 1.0e-7)

speccpu2017_add_executable()

speccpu2017_prepare_rundir()
