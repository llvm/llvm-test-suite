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
    -I${BENCHMARK_DIR}/data/all/input/lib ${perlscript}
    > ${CMAKE_CURRENT_BINARY_DIR}/${output}
    ${ARGN}
  )
  llvm_test_verify(RUN_TYPE ${run_type} ${FPCMP}
    ${BENCHMARK_DIR}/data/${run_type}/output/${output}
    ${CMAKE_CURRENT_BINARY_DIR}/${output}
  )
endmacro()

# (Parameters come from the respective XXX.in files)
test_input(train
  ${BENCHMARK_DIR}/data/all/input/diffmail.pl
  2.350.15.24.23.150.out
  2 350 15 24 23 150
  WORKDIR ${BENCHMARK_DIR}/data/all/input
)
test_input(train
  ${BENCHMARK_DIR}/data/all/input/perfect.pl
  b.3.out
  b 3
  WORKDIR ${BENCHMARK_DIR}/data/all/input
)
test_input(train
  ${BENCHMARK_DIR}/data/train/input/scrabbl.pl
  scrabbl.out
  < ${BENCHMARK_DIR}/data/train/input/scrabbl.in
  WORKDIR ${BENCHMARK_DIR}/data/train/input
)

test_input(ref
  ${BENCHMARK_DIR}/data/ref/input/splitmail.pl
  850.5.19.18.1500.out
  850 5 19 18 1500
  WORKDIR ${CMAKE_CURRENT_BINARY_DIR}/data/ref/input
)
test_input(ref
  ${BENCHMARK_DIR}/data/ref/input/splitmail.pl
  704.12.26.16.836.out
  704 12 26 16 836
  WORKDIR ${CMAKE_CURRENT_BINARY_DIR}/data/ref/input
)
test_input(ref
  ${BENCHMARK_DIR}/data/ref/input/splitmail.pl
  535.13.25.24.1091.out
  535 13 25 24 1091
  WORKDIR ${CMAKE_CURRENT_BINARY_DIR}/data/ref/input
)
test_input(ref
  ${BENCHMARK_DIR}/data/ref/input/splitmail.pl
  957.12.23.26.1014.out
  957 12 23 26 1014
  WORKDIR ${CMAKE_CURRENT_BINARY_DIR}/data/ref/input
)
test_input(ref
  ${BENCHMARK_DIR}/data/all/input/diffmail.pl
  2.550.15.24.23.100.out
  2 550 15 24 23 100
  WORKDIR ${BENCHMARK_DIR}/data/all/input
)
test_input(ref
  ${BENCHMARK_DIR}/data/all/input/perfect.pl
  b.3.m.4.out
  b 3 m 4
  WORKDIR ${BENCHMARK_DIR}/data/all/input
)
test_input(ref
  ${BENCHMARK_DIR}/data/ref/input/makerand.pl
  makerand.out
  WORKDIR ${BENCHMARK_DIR}/data/all/input
)

file(GLOB inputs ${BENCHMARK_DIR}/data/test/input/*.t)
foreach(input ${inputs})
  get_filename_component(basename ${input} NAME_WE)
  test_input(test
    ${CMAKE_CURRENT_BINARY_DIR}/data/test/input/${basename}.t
    ${basename}.out
    WORKDIR ${CMAKE_CURRENT_BINARY_DIR}/data/test/input
  )
endforeach()

llvm_test_executable(${PROG} ${Source})

include(CopyDir)
llvm_copy_dir(${PROG} ${CMAKE_CURRENT_BINARY_DIR}/data/test/input
  ${BENCHMARK_DIR}/data/all/input
  ${BENCHMARK_DIR}/data/test/input
)
llvm_copy_dir(${PROG} ${CMAKE_CURRENT_BINARY_DIR}/data/ref/input
  ${BENCHMARK_DIR}/data/all/input
  ${BENCHMARK_DIR}/data/ref/input
)
