set(DIRS)
set(PARALLEL_DIRS)

set(LEVEL ../../..)
set(PROG make_dparser)
set(Source make_dparser.c write_ctables.c gram.c lex.c lr.c arg.c parse.c scan.c symtab.c util.c version.c grammar.g.c)
set(CPPFLAGS -DD_BUILD_VERSION=5725)
set(RUN_OPTIONS -v ${CMAKE_CURRENT_SOURCE_DIR}/grammar.g)
set(HASH_PROGRAM_OUTPUT 1)
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
