set(RUN_OPTIONS -f INPUT/adj.awk type=l linelen=70 indent=5 INPUT/words-large.awk)
list(APPEND LDFLAGS -lm)
list(APPEND CPPFLAGS -DBCOPY_MISSING -DSPRINTF_INT -DDOPRNT_MISSING  -DGCVT_MISSING -DSTRCASE_MISSING -DSTRTOD_MISSING  -DTMPNAM_MISSING)

llvm_multisource(gawk
  alloca.c
  awk.tab.c
  debug.c
  field.c
  main.c
  msg.c
  regex.c
  array.c
  builtin.c
  eval.c
  io.c
  node.c
)
llvm_test_data(gawk INPUT/adj.awk INPUT/words-large.awk)
