# GCC C Torture Suite is conventionally run without warnings
list(APPEND CFLAGS -Wno-implicit-int -Wno-implicit-function-declaration -w)
set(TestsToSkip)

##
## Main Test Blacklist for Clang
##

# Tests with features unsupported by Clang (usually GCC extensions)
# (Big list of naughty tests)
file(GLOB UnsupportedTests
  CONFIGURE_DEPENDS

  # The following all expect very specific optimiser behavior from the compiler

  # Clang at O0 does not work out the code referencing the undefined symbol can
  # never be executed
  fp-cmp-7.c
)
list(APPEND TestsToSkip ${UnsupportedTests})

##
## Tests that require extra CFLAGS in Clang
##

# Tests that require libm (-lm flag)
file(GLOB TestRequiresLibM CONFIGURE_DEPENDS
  20041213-1.c
  mzero4.c
)

# Tests that require -fno-trapping-math
file(GLOB TestRequiresFNoTrappingMath CONFIGURE_DEPENDS
  # Needs additional flags from compare-fp-3.x
  compare-fp-3.c
)

if(TEST_SUITE_PROFILE_GENERATE OR TEST_SUITE_PROFILE_USE)
  file(GLOB UnsupportedWithPGO CONFIGURE_DEPENDS
    # Fails to compile when compiling with instrumentation
    compare-fp-3.c
  )
  list(APPEND TestsToSkip ${UnsupportedWithPGO})
endif()

##
## Architecture-specific Test Blacklists
##

##
## Test target setup
##

file(GLOB TestFiles CONFIGURE_DEPENDS
  *.c
)
foreach(TestToSkip ${TestsToSkip})
  list(REMOVE_ITEM TestFiles ${TestToSkip})
endforeach()

foreach(File ${TestFiles})
  set(MaybeCFlags)
  set(MaybeLDFlags)

  # Add Test-specific CFLAGS/LDFLAGS here

  if (${File} IN_LIST TestRequiresLibM)
    list(APPEND MaybeLDFlags "-lm")
  endif()

  if (${File} IN_LIST TestRequiresFNoTrappingMath)
    list(APPEND MaybeCFlags "-fno-trapping-math")
  endif()

  # Add Test Target
  gcc_torture_execute_test(${File}
                           PREFIX "GCC-C-execute-ieee"
                           CFLAGS ${MaybeCFlags}
                           LDFLAGS ${MaybeLDFlags})
endforeach()
