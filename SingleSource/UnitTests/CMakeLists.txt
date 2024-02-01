include(CheckCCompilerFlag)

add_subdirectory(C++11)
add_subdirectory(Float)
add_subdirectory(Matrix)
add_subdirectory(SignlessTypes)
add_subdirectory(Threads)
add_subdirectory(Vector)
add_subdirectory(Vectorizer)
add_subdirectory(X86)
add_subdirectory(AArch64)

list(APPEND CFLAGS -Wno-implicit-function-declaration -Wno-implicit-int)

# FIXME: Disable SJLJ tests for now, until EH edges are represented.
# add_subdirectory(SetjmpLongjmp)
if(TARGET_OS STREQUAL "Darwin")
  add_subdirectory(ObjC)
  add_subdirectory(ObjC++)
endif()

file(GLOB Source RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.c *.cpp)
if(TARGET_OS STREQUAL "AIX" AND ARCH STREQUAL "PowerPC")
  list(REMOVE_ITEM Source 2007-04-25-weak.c)
  if (NOT PPC_IS_PPC64_ENABLED)
    list(REMOVE_ITEM Source AtomicOps.c)
  endif()
endif()
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
endif()
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

# Enable matrix types extension tests for compilers supporting -fenable-matrix.
check_c_compiler_flag(-fenable-matrix COMPILER_HAS_MATRIX_FLAG)
if (COMPILER_HAS_MATRIX_FLAG)
  set_property(SOURCE matrix-types-spec.cpp PROPERTY COMPILE_FLAGS -fenable-matrix)
else()
  list(REMOVE_ITEM Source matrix-types-spec.cpp)
endif()

llvm_singlesource()

if (COMPILER_HAS_MATRIX_FLAG)
  set_property(TARGET matrix-types-spec PROPERTY LINK_OPTIONS -fenable-matrix)
endif()
