set(DIRS)
set(PARALLEL_DIRS)

set(PROG paq8p)
list(APPEND CPPFLAGS -DNOASM -DLLVM)
set(LDFLAGS -lstdc++ -lm)
if(DEFINED SMALL_PROBLEM_SIZE)
  set(RUN_OPTIONS -1 ${CMAKE_CURRENT_SOURCE_DIR}/small.in)
else()
  set(RUN_OPTIONS -4 ${CMAKE_CURRENT_SOURCE_DIR}/file1.in)
endif()
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
