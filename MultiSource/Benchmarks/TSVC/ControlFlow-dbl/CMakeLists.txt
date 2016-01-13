set(DIRS)
set(PARALLEL_DIRS)

set(LEVEL ../../../..)
set(PROG ControlFlow-dbl)
set(LDFLAGS -lm)
list(APPEND CFLAGS -std=gnu99)
set(RUN_OPTIONS 2325 14)
if("${ARCH}" STREQUAL "XCore")
  set(RUNTIMELIMIT 7200)
endif()
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
