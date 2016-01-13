set(DIRS)
set(PARALLEL_DIRS)

set(LEVEL ../../../..)
set(PROG ldecod)
set(CPPFLAGS -D __USE_LARGEFILE64 -D _FILE_OFFSET_BITS=64)
set(LDFLAGS -lm ${TOOLLINKOPTS})
set(RUN_OPTIONS -i ${CMAKE_CURRENT_SOURCE_DIR}/data/test.264 -o Output/test_dec.yuv -r ${CMAKE_CURRENT_SOURCE_DIR}/data/test_rec.yuv)
if("${ARCH}" STREQUAL "XCore")
  set(XCORE_TARGET_NEEDS_MEMORY 64)
endif()
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
