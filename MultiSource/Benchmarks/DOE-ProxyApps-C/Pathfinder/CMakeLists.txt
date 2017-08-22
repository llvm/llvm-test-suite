set(PROG PathFinder)
list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS -x ${CMAKE_CURRENT_SOURCE_DIR}/medsmall1.adj_list) 
llvm_multisource()
