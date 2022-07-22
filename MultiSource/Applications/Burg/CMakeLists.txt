list(APPEND CPPFLAGS -DDEBUG)
list(APPEND CFLAGS -std=gnu89 -Wno-int-conversion)
set(RUN_OPTIONS < sample.gr)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
llvm_multisource(burg)
llvm_test_data(burg sample.gr)
