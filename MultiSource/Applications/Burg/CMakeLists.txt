list(APPEND CPPFLAGS -DDEBUG)
list(APPEND CFLAGS -std=gnu89)
list(APPEND LDFLAGS -lstdc++)
set(RUN_OPTIONS < ${CMAKE_CURRENT_SOURCE_DIR}/sample.gr)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
llvm_multisource(burg)
