list(APPEND CPPFLAGS -I${CMAKE_CURRENT_SOURCE_DIR}/include -std=gnu++98 -DNO_TIME)
list(APPEND LDFLAGS -lstdc++ -lm)
llvm_multisource(bullet)
