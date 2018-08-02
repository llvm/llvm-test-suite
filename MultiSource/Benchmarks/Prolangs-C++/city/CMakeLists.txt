list(APPEND LDFLAGS -lstdc++)
llvm_multisource(city)
target_include_directories(city PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
