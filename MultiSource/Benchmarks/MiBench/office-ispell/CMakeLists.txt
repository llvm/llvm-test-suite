set(DIRS)
set(PARALLEL_DIRS)

set(PROG office-ispell)
set(CPPFLAGS -Dconst=)
set(LDFLAGS -lm)
set(RUN_OPTIONS -a -d ${CMAKE_CURRENT_SOURCE_DIR}/americanmed+)
set(STDIN_FILENAME ${CMAKE_CURRENT_SOURCE_DIR}/large.txt)
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
