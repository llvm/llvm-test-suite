set(DIRS)
set(PARALLEL_DIRS)

set(LEVEL ../../..)
set(PROG optimizer-eval)
set(CPPFLAGS )
set(LDFLAGS -lm)
set(PROGRAM_IS_NONDETERMINISTIC 1)
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
