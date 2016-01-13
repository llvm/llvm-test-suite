set(DIRS)
set(PARALLEL_DIRS)

set(PROG bullet)
list(APPEND CPPFLAGS -I${CMAKE_CURRENT_SOURCE_DIR}/include -DNO_TIME)
set(LDFLAGS -lstdc++ -lm)
if("${ARCH}" STREQUAL "XCore")
  set(XCORE_TARGET_NEEDS_MEMORY 64)
else()
  set(RUNTIMELIMIT 1500)
endif()
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
