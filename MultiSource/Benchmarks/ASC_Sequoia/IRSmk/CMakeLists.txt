set(PROG IRSmk)
list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS ${CMAKE_CURRENT_SOURCE_DIR}/irsmk_input)
llvm_multisource()
