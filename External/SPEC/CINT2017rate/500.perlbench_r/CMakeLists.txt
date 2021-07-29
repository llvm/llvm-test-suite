# https://www.spec.org/cpu2017/Docs/benchmarks/500.perlbench_r.html
include(../../SpecCPU2017.cmake)
if (NOT TEST_SUITE_SPEC2017_ROOT)
  return ()
endif ()

speccpu2017_benchmark(RATE)

if (TARGET_OS STREQUAL "Darwin")
  add_definitions(-DSPEC_MACOSX_X64)
endif ()

add_definitions(
  -DPERL_CORE
  -DDOUBLE_SLASHES_SPECIAL=0
  -D_LARGE_FILES
  -D_LARGEFILE_SOURCE
  -D_FILE_OFFSET_BITS=64
)
speccpu2017_add_include_dirs(
  .
  dist/IO
  cpan/Time-HiRes
  cpan/HTML-Parser
  ext/re
  specrand
)
add_compile_options(-fno-strict-aliasing)
link_libraries(-lm)

## test ########################################################################

speccpu2017_run_test(
  -I. -I./lib makerand.pl
  STDOUT makerand.out
  RUN_TYPE test
)

speccpu2017_run_test(
  -I. -I./lib test.pl
  STDOUT test.out
  RUN_TYPE test
)

## train #######################################################################

speccpu2017_run_test(
  -I./lib diffmail.pl 2 550 15 24 23 100
  STDOUT diffmail.2.550.15.24.23.100.out
  RUN_TYPE train
)

speccpu2017_run_test(
  -I./lib perfect.pl b 3
  STDOUT perfect.b.3.out
  RUN_TYPE train
)

speccpu2017_run_test(
  -I. -I./lib scrabbl.pl  -i scrabbl.in -o scrabbl.out
  STDOUT scrabbl.out
  RUN_TYPE train
)

speccpu2017_run_test(
  -I./lib splitmail.pl 535 13 25 24 1091 1
  STDOUT splitmail.535.13.25.24.1091.1.out
  RUN_TYPE train
)

speccpu2017_run_test(
  -I. -I./lib suns.pl
  STDOUT suns.out
  RUN_TYPE train
)

## ref #########################################################################

speccpu2017_run_test(
  -I./lib checkspam.pl 2500 5 25 11 150 1 1 1 1
  STDOUT checkspam.2500.5.25.11.150.1.1.1.1.out
  RUN_TYPE ref
)

speccpu2017_run_test(
  -I./lib diffmail.pl 4 800 10 17 19 300
  STDOUT diffmail.4.800.10.17.19.300.out
  RUN_TYPE ref
)

speccpu2017_run_test(
  -I./lib splitmail.pl 6400 12 26 16 100 0
  STDOUT splitmail.6400.12.26.16.100.0.out
  RUN_TYPE ref
)

################################################################################

speccpu2017_verify_output()
speccpu2017_add_executable(
  av.c
  caretx.c
  deb.c
  doio.c
  doop.c
  dump.c
  globals.c
  gv.c
  hv.c
  keywords.c
  locale.c
  mg.c
  numeric.c
  op.c
  pad.c
  perl.c
  perlapi.c
  perlio.c
  perlmain.c
  perly.c
  pp.c
  pp_ctl.c
  pp_hot.c
  pp_pack.c
  pp_sort.c
  pp_sys.c
  regcomp.c
  regexec.c
  run.c
  scope.c
  sv.c
  taint.c
  toke.c
  universal.c
  utf8.c
  util.c
  reentr.c
  mro_core.c
  mathoms.c
  specrand/specrand.c
  dist/PathTools/Cwd.c
  dist/Data-Dumper/Dumper.c
  ext/Devel-Peek/Peek.c
  cpan/Digest-MD5/MD5.c
  cpan/Digest-SHA/SHA.c
  DynaLoader.c
  dist/IO/IO.c
  dist/IO/poll.c
  cpan/MIME-Base64/Base64.c
  Opcode.c
  dist/Storable/Storable.c
  ext/Sys-Hostname/Hostname.c
  cpan/Time-HiRes/HiRes.c
  ext/XS-Typemap/stdio.c
  ext/attributes/attributes.c
  cpan/HTML-Parser/Parser.c
  ext/mro/mro.c
  ext/re/re.c
  ext/re/re_comp.c
  ext/re/re_exec.c
  ext/arybase/arybase.c
  ext/PerlIO-scalar/scalar.c
  ext/PerlIO-via/via.c
  ext/File-Glob/bsd_glob.c
  ext/File-Glob/Glob.c
  ext/Hash-Util/Util.c
  ext/Hash-Util-FieldHash/FieldHash.c
  ext/Tie-Hash-NamedCapture/NamedCapture.c
  cpan/Scalar-List-Utils/ListUtil.c
)
speccpu2017_prepare_rundir()
