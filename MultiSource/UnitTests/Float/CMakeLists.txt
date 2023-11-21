# Tests in Rounding can run only if the target implements builtin functions for
# manipulation of rounding mode.
set(SUPPORTED_ARCHS x86 AArch64)
if(ARCH IN_LIST SUPPORTED_ARCHS)
  add_subdirectory(rounding)
endif()
