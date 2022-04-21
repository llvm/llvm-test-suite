list(APPEND CPPFLAGS -DD_BUILD_VERSION=5725)
list(APPEND CFLAGS -Wno-implicit-function-declaration)
set(RUN_OPTIONS -v grammar.g)
set(HASH_PROGRAM_OUTPUT 1)
llvm_multisource(make_dparser
  make_dparser.c
  write_ctables.c
  gram.c
  lex.c
  lr.c
  arg.c
  parse.c
  scan.c
  symtab.c
  util.c
  version.c
  grammar.g.c
)
llvm_test_data(make_dparser grammar.g)
