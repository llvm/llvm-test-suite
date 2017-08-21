# https://www.spec.org/cpu2017/Docs/benchmarks/657.xz_s.html
include(../../SpecCPU2017.cmake)
if (NOT TEST_SUITE_SPEC2017_ROOT)
  return ()
endif ()

speccpu2017_benchmark(SPEED ORIGIN 557.xz_r)

## ref #########################################################################

speccpu2017_run_test(
  cpu2006docs.tar.xz 6643 055ce243071129412e9dd0b3b69a21654033a9b723d874b2015c774fac1553d9713be561ca86f74e4f16f22e664fc17a79f30caa5ad2c04fbc447549c2810fae 1036078272 1111795472 4
  STDOUT cpu2006docs.tar-6643-4.out
  WORKDIR "${INPUT_all_DIR}"
  RUN_TYPE ref
  SUITE_TYPE speed
)

speccpu2017_run_test(
  cld.tar.xz 1400 19cf30ae51eddcbefda78dd06014b4b96281456e078ca7c13e1c0c9e6aaea8dff3efb4ad6b0456697718cede6bd5454852652806a657bb56e07d61128434b474 536995164 539938872 8
  STDOUT cld.tar-1400-8.out
  WORKDIR "${INPUT_all_DIR}"
  RUN_TYPE ref
  SUITE_TYPE speed
)

################################################################################

speccpu2017_inherit(../../CINT2017rate/557.xz_r)
