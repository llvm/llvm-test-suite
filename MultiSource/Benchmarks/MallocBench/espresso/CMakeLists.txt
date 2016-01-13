set(DIRS)
set(PARALLEL_DIRS)

set(PROG espresso)
list(APPEND CPPFLAGS -DNOMEMOPT)
list(APPEND CFLAGS -std=gnu89)
set(RUN_OPTIONS -t ${CMAKE_CURRENT_SOURCE_DIR}/INPUT/largest.espresso)
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
