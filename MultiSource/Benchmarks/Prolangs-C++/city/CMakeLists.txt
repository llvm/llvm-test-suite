set(PROG city)
list(APPEND LDFLAGS -lstdc++)
llvm_multisource()
target_include_directories(city PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
