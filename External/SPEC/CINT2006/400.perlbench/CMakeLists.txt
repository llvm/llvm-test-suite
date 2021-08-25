list(APPEND CPPFLAGS -DPERL_CORE -DI_TIME)
list(APPEND CFLAGS -std=gnu89)
# We want reproducible builds
list(APPEND CPPFLAGS -D__DATE__="XXX" -D__TIME__="XXX")
list(APPEND LDFLAGS -lm)
if(TARGET_OS STREQUAL "Darwin")
  # Necessary for iOS
  list(APPEND LDFLAGS -Xlinker -stack_size -Xlinker 0x8000000)
endif()

include_directories(${BENCHMARK_DIR}/src)

set(SourceNames
  av.c
  deb.c
  doio.c
  doop.c
  dump.c
  globals.c
  gv.c
  hv.c
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
  xsutils.c
  Base64.c
  Cwd.c
  Dumper.c
  HiRes.c
  IO.c
  Peek.c
  attrs.c
  poll.c
  stdio.c
  DynaLoader.c
  MD5.c
  Storable.c
  Parser.c
  specrand.c
  Hostname.c
  Opcode.c
)
set(Source "")
foreach(FILENAME ${SourceNames})
  list(APPEND Source ${BENCHMARK_DIR}/src/${FILENAME})
endforeach()

macro(test_input run_type perlscript output)
  llvm_test_run(RUN_TYPE ${run_type}
    -I%S/data/all/input/lib ${perlscript}
    > %S/${output}
    ${ARGN}
  )
  llvm_test_verify(RUN_TYPE ${run_type}
    %b/${FPCMP} %S/data/${run_type}/output/${output} %S/${output}
  )
endmacro()

# (Parameters come from the respective XXX.in files)
test_input(train
  diffmail.pl diffmail.2.550.15.24.23.100.out 2 550 15 24 23 100
  WORKDIR %S/data/all/input
)
test_input(train
  perfect.pl perfect.b.3.out b 3
  WORKDIR %S/data/train/input
)
test_input(train
  splitmail.pl splitmail.535.13.25.24.1091.out 535 13 25 24 1091
  WORKDIR %S/data/all/input
)
test_input(train
  suns.pl suns.out
  WORKDIR %S/data/train/input
)
llvm_test_verify(RUN_TYPE train
  %b/${FPCMP} %S/data/train/output/validate %S/data/train/input/validate
)
#test_input(train scrabbl.pl scrabbl.in) # spec doesn't come with output files?

test_input(ref
  diffmail.pl diffmail.4.800.10.17.19.300.out 4 800 10 17 19 300
  WORKDIR %S/data/all/input
)
test_input(ref
  splitmail.pl splitmail.1600.12.26.16.4500.out 1600 12 26 16 4500
  WORKDIR %S/data/all/input
)
test_input(ref
  %S/data/ref/input/checkspam.pl
  checkspam.2500.5.25.11.150.1.1.1.1.out
  2500 5 25 11 150 1 1 1 1
  WORKDIR %S/data/all/input
)

file(GLOB inputs ${BENCHMARK_DIR}/data/test/input/*.t)
foreach(input ${inputs})
  get_filename_component(basename ${input} NAME_WE)
  test_input(test
    ${basename}.t ${basename}.out
    WORKDIR %S/data/test/input
  )
endforeach()

llvm_test_executable(400.perlbench ${Source})
llvm_test_data_spec(400.perlbench MUST_COPY data)
