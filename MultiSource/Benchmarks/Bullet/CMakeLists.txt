list(APPEND CPPFLAGS -I${CMAKE_CURRENT_SOURCE_DIR}/include -DNO_TIME)
list(APPEND LDFLAGS -lm)
llvm_multisource(bullet)
set_property(TARGET bullet PROPERTY CXX_STANDARD 98)
