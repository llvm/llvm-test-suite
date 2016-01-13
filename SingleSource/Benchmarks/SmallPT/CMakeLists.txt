set(DIRS)
set(PARALLEL_DIRS)

set(LEVEL ../../..)
list(APPEND LDFLAGS -lm -lstdc++)
set(FP_TOLERANCE 0.001)
if("${ARCH}" STREQUAL "XCore")
  set(RUNTIMELIMIT 10800)
else()
  set(RUNTIMELIMIT 1200)
endif()
llvm_singlesource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
