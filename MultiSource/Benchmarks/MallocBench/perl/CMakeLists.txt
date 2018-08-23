list(APPEND CPPFLAGS -DHAS_STRERROR -DHAS_MKDIR -DHAS_RMDIR -U_POSIX_SOURCE -D__USE_MISC)
list(APPEND LDFLAGS -lm -lcrypt)
set(RUN_OPTIONS INPUT/endsort.perl INPUT/endsort.perl)
llvm_multisource(perl
  array.c
  doarg.c
  eval.c
  regexec.c
  cmd.c
  doio.c
  form.c
  perl.c
  stab.c
  usersub.c
  cons.c
  dolist.c
  hash.c
  perly.c
  str.c
  util.c
  consarg.c
  dump.c
  malloc.c
  regcomp.c
  toke.c
)
llvm_test_data(perl INPUT)
