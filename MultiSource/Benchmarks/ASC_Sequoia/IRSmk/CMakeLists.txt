set(DIRS)
set(PARALLEL_DIRS)

set(PROG IRSmk)
list(APPEND LIBS -lm)
list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS ${CMAKE_CURRENT_SOURCE_DIR}/irsmk_input)
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
