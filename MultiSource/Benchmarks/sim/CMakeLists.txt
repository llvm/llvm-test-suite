set(DIRS)
set(PARALLEL_DIRS)

set(PROG sim)
set(CPPFLAGS -DUNIX)
set(LDFLAGS )
set(RUN_OPTIONS 8 ${CMAKE_CURRENT_SOURCE_DIR}/tob.38-44 ${CMAKE_CURRENT_SOURCE_DIR}/liv.42-48)
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
