set(DIRS)
set(PARALLEL_DIRS)

list(APPEND LDFLAGS -lm)
if("${ARCH}" STREQUAL "XCore")
  set(XCORE_TARGET_NEEDS_MEMORY 256)
endif()
if(DEFINED BENCHMARKING_ONLY)
  list(APPEND PROGRAMS_TO_SKIP hello)
endif()
llvm_singlesource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
