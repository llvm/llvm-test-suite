list(APPEND CPPFLAGS -DDEBUG)
list(APPEND CFLAGS -Wno-int-conversion)
set(RUN_OPTIONS < sample.gr)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
llvm_multisource(burg)
set_property(TARGET burg PROPERTY C_STANDARD 90)
llvm_test_data(burg sample.gr)
