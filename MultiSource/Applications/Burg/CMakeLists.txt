set(PROG burg)
set(CPPFLAGS -DDEBUG)
list(APPEND CFLAGS -std=gnu89)
set(LDFLAGS -lstdc++)
set(STDIN_FILENAME ${CMAKE_CURRENT_SOURCE_DIR}/sample.gr)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
llvm_multisource()
