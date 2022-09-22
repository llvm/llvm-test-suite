add_subdirectory(ieee)

# GCC C Torture Suite is conventionally run without warnings
list(APPEND CFLAGS -Wno-implicit-int -Wno-int-conversion -Wno-implicit-function-declaration -w)

set(TestsToSkip)

##
## Main Test Blacklist for Clang
##

# Tests with features unsupported by Clang (usually GCC extensions)
# (Big list of naughty tests)
file(GLOB UnsupportedTests CONFIGURE_DEPENDS
  # GCC Extension: Nested functions
  20000822-1.c
  20010209-1.c
  20010605-1.c
  20030501-1.c
  20040520-1.c
  20061220-1.c
  20090219-1.c
  920415-1.c
  920428-2.c
  920501-7.c
  920612-2.c
  920721-4.c
  921017-1.c
  921215-1.c
  931002-1.c
  comp-goto-2.c
  nest-align-1.c
  nest-stdar-1.c
  nestfunc-1.c
  nestfunc-2.c
  nestfunc-3.c
  nestfunc-5.c
  nestfunc-6.c
  nestfunc-7.c
  pr22061-3.c
  pr22061-4.c
  pr24135.c
  pr51447.c
  pr71494.c

  # Variable length arrays in structs
  20020412-1.c
  20040308-1.c
  20040423-1.c
  20041218-2.c
  20070919-1.c
  align-nest.c
  pr41935.c
  pr82210.c

  # Initialization of flexible array member
  pr28865.c

  # Initialization of union is not required to initialize padding.
  pr19687.c

  # GCC Extension: __builtin_*
  pr39228.c          # __builtin_isinff, __builtin_isinfl
  pr47237.c          # __builtin_apply, __builtin_apply_args
  pr85331.c          # __builtin_shuffle
  va-arg-pack-1.c    # __builtin_va_arg_pack

  # Clang does not support 'DD' suffix on floating constant
  pr80692.c

  # Test requires compiler to recognise llabs without including <inttypes.h> -
  # clang will only recognise this function if the header is included.
  20021127-1.c

  # Tests __attribute__((noinit))
  noinit-attribute.c

  # We are unable to parse the dg-additional-options for this test, which is
  # required for it to work (we discard any with `target`, but we need the
  # define for this test)
  20101011-1.c

  # The following rely on C Undefined Behavior

  # Test relies on UB around (float)INT_MAX
  20031003-1.c

  # UB: Expects very specific behavior around setjmp/longjmp and allocas, which
  # clang is not obliged to replicate.
  pr64242.c

  # UB: Creates two `restrict` pointers that alias in the same scope.
  pr38212.c

  # UB: Each comparisons in (cyx != cyy || mpn_cmp (dx, dy, size + 1) != 0 ||
  #     dx[size] != 0x12345678) is UB on its own.
  921202-1.c

  # The following all expect very specific optimiser behavior from the compiler

  # __builtin_return_address(n) with n > 0 not guaranteed to give expected result
  20010122-1.c

  # Expects gnu89 inline behavior
  20001121-1.c
  20020107-1.c
  930526-1.c
  961223-1.c
  980608-1.c
  bcp-1.c
  loop-2c.c
  p18298.c
  restrict-1.c
  unroll-1.c
  va-arg-7.c
  va-arg-8.c

  # Clang at O0 does not work out the code referencing the undefined symbol can
  # never be executed
  medce-1.c

  # Expects that function is always inlined
  990208-1.c

  # pragma optimize("-option") is ignored by Clang
  alias-1.c
  pr79043.c

  # The following all expect very specific optimiser behavior from the compiler
  # around __printf_chk and friends.
  fprintf-chk-1.c
  printf-chk-1.c
  vfprintf-chk-1.c
  vprintf-chk-1.c

  # Clang at -O0 does not enable -finstrument-functions
  # (https://bugs.llvm.org/show_bug.cgi?id=49143)
  eeprof-1.c

  # Size of array element is not a multiple of its alignment.
  pr36093.c
  pr43783.c
)
list(APPEND TestsToSkip ${UnsupportedTests})

# Tests where clang currently has bugs or issues
file(GLOB FailingTests CONFIGURE_DEPENDS

  # Handling of bitfields is different between clang and GCC:
  # http://lists.llvm.org/pipermail/llvm-dev/2017-October/118507.html
  # https://gcc.gnu.org/ml/gcc/2017-10/msg00192.html
  # http://www.open-std.org/jtc1/sc22/wg14/www/docs/n1260.htm
  bitfld-3.c
  bitfld-5.c
  pr32244-1.c
  pr34971.c

  # This causes a stacktrace on x86 in X86TargetLowering::LowerCallTo
  pr84169.c

  # clang complains the array is too large
  991014-1.c

  # __builtin_setjmp/__builtin_longjmp are interacting badly with optimisation
  pr60003.c
)
list(APPEND TestsToSkip ${FailingTests})

##
## Tests that require extra CFLAGS in Clang
##

# Tests that require -fwrapv
file(GLOB TestRequiresFWrapV CONFIGURE_DEPENDS
  # Test relies on undefined signed overflow behavior (int foo - INT_MIN).
  20040409-1.c
  20040409-2.c
  20040409-3.c
)

# Tests that require -Wno-return-type
file(GLOB TestRequiresWNoReturnType CONFIGURE_DEPENDS
  # Non-void function must return a value
  920302-1.c
  920501-3.c
  920728-1.c
)

# Tests that require libm (-lm ldflag)
file(GLOB TestRequiresLibM CONFIGURE_DEPENDS
  980709-1.c
  float-floor.c
  complex-5.c  # -lm needed on FreeBSD
)

# Tests that require newnlib Nano IO (--undefined=_printf_float ldflag)
file(GLOB TestRequiresNanoIO CONFIGURE_DEPENDS
  920501-8.c
  930513-1.c
)

##
## Architecture-specific Test Blacklists
##


# Tests that require mmap
include(CheckSymbolExists)
CHECK_SYMBOL_EXISTS("mmap" "sys/types.h;sys/mman.h" HAVE_MMAP)
if (NOT HAVE_MMAP)
  file(GLOB MMapTests
    loop-2f.c
    loop-2g.c
  )
  list(APPEND TestsToSkip ${MMapTests})
endif()

# x86-only Tests
if(NOT ARCH MATCHES "x86")
  file(GLOB X86OnlyTests CONFIGURE_DEPENDS
    990413-2.c
  )

  list(APPEND TestsToSkip ${X86OnlyTests})
endif()

# MIPS Test Blacklist
if(ARCH MATCHES "Mips")
  file(GLOB MipsTestsToSkip CONFIGURE_DEPENDS
    # No backend support for __builtin_longjmp/__builtin_setjmp
    built-in-setjmp.c
    pr84521.c
    # Triggers "return address can be determined only for current frame"
    20030323-1.c
    # These test cases compiled very long due PR43263.
    pr20621-1.c
    pr23135.c
    pr28982b.c
  )

  # MIPS 32-bit Test Blacklist
  if(NOT MIPS_IS_MIPS64_ENABLED)
    file(GLOB Mips32TestsToSkip CONFIGURE_DEPENDS
      # No support for __int128 on MIPS 32-bit
      pr84748.c
    )

    list(APPEND MipsTestsToSkip ${Mips32TestsToSkip})
  endif()

  list(APPEND TestsToSkip ${MipsTestsToSkip})
endif()

# RISC-V Test Blacklist
if(ARCH MATCHES "riscv")
  file(GLOB RISCVTestsToSkip CONFIGURE_DEPENDS
    # No backend support for __builtin_longjmp/__builtin_setjmp
    built-in-setjmp.c
    pr84521.c
  )

  # RISC-V 32-bit Test Blacklist
  if (ARCH MATCHES "riscv32")
    file(GLOB RISCV32TestsToSkip CONFIGURE_DEPENDS
      # No support for __int128 on rv32
      pr84748.c
    )

    list(APPEND RISCVTestsToSkip ${RISCV32TestsToSkip})
  endif()

  list(APPEND TestsToSkip ${RISCVTestsToSkip})
endif()

# SystemZ Test Blacklist
if(ARCH MATCHES "SystemZ")
  file(GLOB SystemZTestsToSkip CONFIGURE_DEPENDS
    # error: __builtin_longjmp is not supported for the current target
    # error: __builtin_setjmp is not supported for the current target
    built-in-setjmp.c
    pr84521.c
    # Triggers "Unsupported stack frame traversal count"
    20030323-1.c
  )

  list(APPEND TestsToSkip ${SystemZTestsToSkip})
endif()

# AArch64 Test Blacklist
if(ARCH MATCHES "AArch64")
  file(GLOB AArch64TestsToSkip CONFIGURE_DEPENDS
    # error: __builtin_longjmp is not supported for the current target
    # error: __builtin_setjmp is not supported for the current target
    built-in-setjmp.c
    pr84521.c
    # Triggers an assertion failure at at least -O3
    va-arg-22.c
    # Triggers an assertion failure in RegBankSelect pass at -O0 (GlobalIsel)
    pr71626-1.c
    pr71626-2.c
  )

  list(APPEND TestsToSkip ${AArch64TestsToSkip})
endif()

# ARM Test Blacklist
if(ARCH MATCHES "ARM")
  file(GLOB ARMTestsToSkip CONFIGURE_DEPENDS
    # No support for __int128 on ARM 32-bit
    pr84748.c

    # With some command line options, linking fails with:
    # pr89434.c:(.text+0xac): undefined reference to `__mulodi4'
    pr89434.c

    # Fails in the front end with:
    # clang: llvm/include/llvm/Support/Casting.h:269: typename
    #   cast_retty<X, Y *>::ret_type llvm::cast(Y *) [X = llvm::PointerType,
    #   Y = llvm::Type]: Assertion `isa<X>(Val) && "cast<Ty>() argument of
    #   incompatible type!"' failed.
    va-arg-22.c
  )

  list(APPEND TestsToSkip ${ARMTestsToSkip})
endif()

# Darwin Test Blacklist
if(TARGET_OS STREQUAL "Darwin")
  file(GLOB DarwinTestsToSkip CONFIGURE_DEPENDS
    # error: aliases are not supported on darwin
    alias-2.c
    alias-3.c
    alias-4.c
    # Undefined symbols for architecture x86_64:
    # "_printf_float", referenced from:
    # -u command line option
    930513-1.c
    920501-8.c
  )
  list(APPEND TestsToSkip ${DarwinTestsToSkip})
endif()

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

  if(${File} IN_LIST TestRequiresLibM)
    list(APPEND MaybeLDFlags "-lm")
  endif()

  if(${File} IN_LIST TestRequiresWNoReturnType)
    list(APPEND MaybeCFlags "-Wno-return-type")
  endif()

  if(${File} IN_LIST TestRequiresFWrapV)
    list(APPEND MaybeCFlags "-fwrapv")
  endif()

  if(${File} IN_LIST TestRequiresNanoIO)
    list(APPEND MaybeLDFlags "-Wl,-u,_printf_float")
  endif()

  # Add Test Target
  gcc_torture_execute_test(${File}
                           PREFIX "GCC-C-execute"
                           CFLAGS ${MaybeCFlags}
                           LDFLAGS ${MaybeLDFlags})
endforeach()
