set(DIRS)
set(PARALLEL_DIRS)

set(PROG sphot)
list(APPEND LIBS -lm)
list(APPEND LDFLAGS -lm)

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
