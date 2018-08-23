list(APPEND CPPFLAGS -DHAVE_SIGLIST -DNO_LDAV -DNOMEMOPT -DPOSIX)
set(RUN_OPTIONS -n -f INPUT/GNUmakefile.make USEROPT=BWGC)
llvm_multisource(make
  commands.c
  job.c
  dir.c
  file.c
  load.c
  misc.c
  main.c
  read.c
  remake.c
  remote.c
  rule.c
  implicit.c
  default.c
  variable.c
  expand.c
  function.c
  vpath.c
  version.c
  arscan.c
  ar.c
)
llvm_test_data(make INPUT/GNUmakefile.make)
