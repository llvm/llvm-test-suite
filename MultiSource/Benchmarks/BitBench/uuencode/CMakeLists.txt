set(DIRS)
set(PARALLEL_DIRS)

set(PROG uuencode)
set(LDFLAGS )
set(RUN_OPTIONS ${CMAKE_CURRENT_SOURCE_DIR}/input.txt)
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
