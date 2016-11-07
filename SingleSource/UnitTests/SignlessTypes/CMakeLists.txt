add_subdirectory(Large)

execute_process(COMMAND date +%j OUTPUT_VARIABLE TMP1)
set(SEED TMP1)
set(RUN_OPTIONS 31415926)
list(APPEND LDFLAGS -lstdc++)
llvm_singlesource()
