set(SourceNames
  av.c
  byterun.c
  deb.c
  doio.c
  doop.c
  dump.c
  ebcdic.c
  fake_dyna.c
  globals.c
  gv.c
  hv.c
  mg.c
  op.c
  perl.c
  perlio.c
  perly.c
  pp.c
  pp_ctl.c
  pp_hot.c
  pp_sys.c
  regcomp.c
  regexec.c
  run.c
  scope.c
  sv.c
  taint.c
  toke.c
  universal.c
  util.c
  MD5.c
  md5c.c
)

list(APPEND CPPFLAGS -DSPEC_CPU2000_NEED_BOOL)
list(APPEND LDFLAGS -lm)

if(TARGET_OS STREQUAL "Win32")
  list(APPEND SourceNames nt_perlmain.c win32.c win32sck.c perllib.c)
  list(APPEND CPPFLAGS -DSPEC_CPU2000_NTOS -DWIN32 -D_CONSOLE)
  include_directories(${BENCHMARK_DIR}/src)
  include_directories(${BENCHMARK_DIR}/src/win32)
else()
  list(APPEND SourceNames unix_perlmain.c)
  list(APPEND CPPFLAGS -DSPEC_CPU2000_LINUX)
endif()
list(APPEND CFLAGS -std=gnu89)

include(TestBigEndian)
test_big_endian(IS_BIGENDIAN)
if(IS_BIGENDIAN)
  if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    list(APPEND CPPFLAGS -DBYTEORDER=0x87654321)
  else()
    list(APPEND CPPFLAGS -DBYTEORDER=0x4321)
  endif()
else()
  if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    list(APPEND CPPFLAGS -DBYTEORDER=0x12345678)
  else()
    list(APPEND CPPFLAGS -DBYTEORDER=0x1234)
  endif()
endif()

# We want reproducible builds
list(APPEND CPPFLAGS -D__DATE__="XXX" -D__TIME__="XXX")

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
  diffmail.pl 2.350.15.24.23.150.out 2 350 15 24 23 150
  WORKDIR %S/data/all/input
)
test_input(train
  perfect.pl b.3.out b 3
  WORKDIR %S/data/all/input
)
test_input(train
  scrabbl.pl scrabbl.out < scrabbl.in
  WORKDIR %S/data/train/input
)

test_input(ref
  splitmail.pl 850.5.19.18.1500.out 850 5 19 18 1500
  WORKDIR %S/data/ref/input
)
test_input(ref
  splitmail.pl 704.12.26.16.836.out 704 12 26 16 836
  WORKDIR %S/data/ref/input
)
test_input(ref
  splitmail.pl 535.13.25.24.1091.out 535 13 25 24 1091
  WORKDIR %S/data/ref/input
)
test_input(ref
  splitmail.pl 957.12.23.26.1014.out 957 12 23 26 1014
  WORKDIR %S/data/ref/input
)
test_input(ref
  diffmail.pl 2.550.15.24.23.100.out 2 550 15 24 23 100
  WORKDIR %S/data/ref/input
)
test_input(ref
  perfect.pl b.3.m.4.out b 3 m 4
  WORKDIR %S/data/ref/input
)
test_input(ref
  makerand.pl makerand.out
  WORKDIR %S/data/ref/input
)

file(GLOB inputs ${BENCHMARK_DIR}/data/test/input/*.t)
foreach(input ${inputs})
  get_filename_component(basename ${input} NAME_WE)
  test_input(test
    ${basename}.t ${basename}.out
    WORKDIR %S/data/test/input
  )
endforeach()

llvm_test_executable(253.perlbmk ${Source})
llvm_test_data_spec(253.perlbmk MUST_COPY
  data/test/output
  data/train/input
  data/train/output
  data/ref/output
  data/all/input
)

llvm_copy_dir(253.perlbmk ${CMAKE_CURRENT_BINARY_DIR}/data/test/input
  ${BENCHMARK_DIR}/data/all/input
  ${BENCHMARK_DIR}/data/test/input
)
llvm_copy_dir(253.perlbmk ${CMAKE_CURRENT_BINARY_DIR}/data/ref/input
  ${BENCHMARK_DIR}/data/all/input
  ${BENCHMARK_DIR}/data/ref/input
)
