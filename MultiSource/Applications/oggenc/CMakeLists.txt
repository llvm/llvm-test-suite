set(DIRS)
set(PARALLEL_DIRS)

set(LEVEL ../../..)
set(PROG oggenc)
set(CPPFLAGS -fno-strict-aliasing)
set(LDFLAGS -lm)
set(STDIN_FILENAME ${CMAKE_CURRENT_SOURCE_DIR}/tune)
set(RUN_OPTIONS "-Q -s 901820 -")
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
