# https://www.spec.org/cpu2017/Docs/benchmarks/544.nab_r.html
include(../../SpecCPU2017.cmake)
if (NOT TEST_SUITE_SPEC2017_ROOT)
  return ()
endif ()

speccpu2017_benchmark(RATE)

add_definitions(-DNOPERFLIB -DNOREDUCE)
speccpu2017_add_include_dirs(specrand regex-alpha)
link_libraries(-lm)

## test ########################################################################

speccpu2017_run_test(
  hkrdenq 1930344093 1000
  STDOUT hkrdenq.out
  RUN_TYPE test
)

## train #######################################################################

speccpu2017_run_test(
  aminos 391519156 1000
  STDOUT aminos.out
  RUN_TYPE train
)

speccpu2017_run_test(
  gcn4dna 1850041461 300
  STDOUT gcn4dna.out
  RUN_TYPE train
)

## ref #########################################################################

speccpu2017_run_test(
  1am0 1122214447 122
  STDOUT 1am0.out
  RUN_TYPE ref
  SUITE_TYPE rate
)

################################################################################

speccpu2017_verify_output(RELATIVE_TOLERANCE 0.01)
speccpu2017_add_executable(
  nabmd.c
  sff.c
  nblist.c
  prm.c
  memutil.c
  molio.c
  molutil.c
  errormsg.c
  binpos.c
  rand2.c
  select_atoms.c
  reslib.c
  database.c
  traceback.c
  chirvol.c
  specrand/specrand.c
  regex-alpha/regcomp.c
  regex-alpha/regerror.c
  regex-alpha/regexec.c
  regex-alpha/regfree.c
)
speccpu2017_prepare_rundir()
