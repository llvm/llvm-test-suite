# https://www.spec.org/cpu2017/Docs/benchmarks/520.omnetpp_r.html
include(../../SpecCPU2017.cmake)
if (NOT TEST_SUITE_SPEC2017_ROOT)
  return ()
endif ()

speccpu2017_benchmark(RATE)

add_definitions(-DWITH_NETBUILDER)
speccpu2017_add_include_dirs(
  simulator/platdep
  simulator
  model
)

# test #########################################################################

speccpu2017_run_test(
  -c General -r 0
  STDOUT omnetpp.General-0.out
  RUN_TYPE test
)

# train ########################################################################

speccpu2017_run_test(
  -c General -r 0
  STDOUT omnetpp.General-0.out
  RUN_TYPE train
)

# ref ##########################################################################

speccpu2017_run_test(
  -c General -r 0
  STDOUT omnetpp.General-0.out
  RUN_TYPE ref
)

################################################################################

speccpu2017_verify_output(RELATIVE_TOLERANCE 0.00001 ABSOLUTE_TOLERANCE 0.000001)
speccpu2017_add_executable()
set_property(TARGET ${PROG} PROPERTY CXX_STANDARD 14)
speccpu2017_prepare_rundir()
