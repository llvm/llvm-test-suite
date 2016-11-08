add_subdirectory(C++11)
add_subdirectory(SignlessTypes)
add_subdirectory(Threads)
add_subdirectory(Vector)
add_subdirectory(Vectorizer)
# FIXME: Disable SJLJ tests for now, until EH edges are represented.
# add_subdirectory(SetjmpLongjmp)
if(TARGET_OS STREQUAL "Darwin")
  add_subdirectory(ObjC)
  add_subdirectory(ObjC++)
endif()

file(GLOB Source RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.c *.cpp)
if(TARGET_OS STREQUAL "Darwin")
  list(REMOVE_ITEM Source 2007-04-25-weak.c)
  if(ARCH STREQUAL "PowerPC")
    list(REMOVE_ITEM Source AtomicOps.c)
  endif()
endif()
if(ARCH STREQUAL "AArch64")
  list(REMOVE_ITEM Source blockstret.c)
endif()
if(ARCH STREQUAL "Mips")
  add_subdirectory(Mips)
  # Only MIPS 64-bit supports 8 bytes atomic operations.
  if(NOT MIPS_IS_MIPS64_ENABLED)
    list(REMOVE_ITEM Source AtomicOps.c)
  endif()
endif()
if(ARCH STREQUAL "XCore")
  list(REMOVE_ITEM Source AtomicOps.c)
  list(REMOVE_ITEM Source initp1.cpp)
  set(XCORE_TARGET_NEEDS_MEMORY 1)
endif()
list(APPEND LDFLAGS -lstdc++)
if(NOT ARCH STREQUAL "x86")
  list(REMOVE_ITEM Source
    ms_struct-bitfield.c
    ms_struct-bitfield-1.c
    ms_struct-bitfield-init.c
    ms_struct-bitfield-init-1.c
    ms_struct_pack_layout.c
    ms_struct_pack_layout-1.c
  )
endif()
llvm_singlesource()
