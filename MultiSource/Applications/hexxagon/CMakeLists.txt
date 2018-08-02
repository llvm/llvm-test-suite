list(APPEND LDFLAGS -lstdc++)
set(RUN_OPTIONS < ${CMAKE_CURRENT_SOURCE_DIR}/input)
llvm_multisource(hexxagon)
target_include_directories(hexxagon PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
