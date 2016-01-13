set(DIRS)
set(PARALLEL_DIRS)

list(APPEND CPPFLAGS -std=c++11 -pthread)
if(DEFINED BENCHMARKING_ONLY)
  list(APPEND PROGRAMS_TO_SKIP stdthreadbug)
endif()
list(APPEND LDFLAGS -lstdc++ -pthread)
llvm_singlesource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
