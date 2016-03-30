llvm_add_subdirectories(Vector Vectorizer SignlessTypes Threads C++11)

# FIXME: Disable SJLJ tests for now, until EH edges are represented.
# llvm_add_subdirectories(SetjmpLongjmp)

if(TARGET_OS STREQUAL "Darwin")
  llvm_add_subdirectories(ObjC ObjC++)
endif()
if(TARGET_OS STREQUAL "Darwin")
  set(PROGRAMS_TO_SKIP 2007-04-25-weak)
  if(ARCH STREQUAL "PowerPC")
    list(APPEND PROGRAMS_TO_SKIP AtomicOps)
  endif()
endif()
if(ARCH STREQUAL "AArch64")
  list(APPEND PROGRAMS_TO_SKIP blockstret)
endif()
if(ARCH STREQUAL "Mips")
  llvm_add_subdirectories(Mips)
  # Only MIPS 64-bit supports 8 bytes atomic operations.
  if(NOT MIPS_IS_MIPS64_ENABLED)
    list(APPEND PROGRAMS_TO_SKIP AtomicOps)
  endif()
endif()
if(ARCH STREQUAL "XCore")
  list(APPEND PROGRAMS_TO_SKIP AtomicOps)
  list(APPEND PROGRAMS_TO_SKIP initp1)
  set(XCORE_TARGET_NEEDS_MEMORY 1)
endif()
list(APPEND LDFLAGS -lstdc++)
if(NOT ARCH STREQUAL "x86")
  list(APPEND PROGRAMS_TO_SKIP
    ms_struct-bitfield
    ms_struct-bitfield-1
    ms_struct-bitfield-init
    ms_struct-bitfield-init-1
    ms_struct_pack_layout
    ms_struct_pack_layout-1
  )
endif()
llvm_singlesource()
