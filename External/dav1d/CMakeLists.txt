include(External)

# git clone -b 1.5.0 https://code.videolan.org/videolan/dav1d.git
# in llvm-test-suite/test-suite-externals.

llvm_externals_find(TEST_SUITE_DAV1D_ROOT "dav1d" "dav1d 1.5.0")

if (NOT TEST_SUITE_DAV1D_ROOT)
  return()
endif()

include(CheckCCompilerFlag)
include(CheckFunctionExists)
include(CheckLanguage)
include(CheckLibraryExists)
include(CheckLinkerFlag)

set(CMAKE_C_STANDARD 17)

include_directories(.)
include_directories(${TEST_SUITE_DAV1D_ROOT}/include)
include_directories(${TEST_SUITE_DAV1D_ROOT}/include/dav1d)
include_directories(${TEST_SUITE_DAV1D_ROOT})
include_directories(${TEST_SUITE_DAV1D_ROOT}/src)

if (WIN32)
  include_directories(${TEST_SUITE_DAV1D_ROOT}/include/compat)
endif()

# Convenience helper for adding an option if it is supported, automatically
# setting up suitable cache variables for the tests.
function(check_enable_option option)
  if (${option} MATCHES "^-Wno")
    # GCC silently accepts any unknown warning class in options like -Wno-foo,
    # but such unrecognized options can produce other distracting notices
    # if there actual warnings to print. Therefore, for options like -Wno-foo,
    # test whether -Wfoo is supported instead, and if it is, add -Wno-foo.
    string(REGEX REPLACE "^-Wno-" "-W" test_option ${option})
  else()
    set(test_option ${option})
  endif()
  # Transform the option name into a suitable cmake cache variable name, to
  # avoid requiring the caller to uniquely set one for each case.
  string(REGEX REPLACE "^--*" "" varname ${test_option})
  string(TOUPPER ${varname} varname)
  string(REGEX REPLACE "[-=]" "_" varname ${varname})
  set(varname "SUPPORTS_${varname}")
  check_c_compiler_flag(${test_option} ${varname})
  if (${varname})
    # If supported, enable the original form of the option that was requested.
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${option}" PARENT_SCOPE)
  endif()
endfunction()

if (NOT MSVC)
  # clang-cl supports -Wall, but it corresponds to -Weverything
  check_enable_option(-Wall)
endif()

check_enable_option(-Wundef)
check_enable_option(-Werror=vla)
check_enable_option(-Wno-maybe-uninitialized)
check_enable_option(-Wno-missing-field-initializers)
check_enable_option(-Wno-unused-parameter)
check_enable_option(-Wstrict-prototypes)
check_enable_option(-Werror=missing-prototypes)
check_enable_option(-Wshorten-64-to-32)

check_function_exists(sin HAVE_DEFAULT_MATH)
if (NOT HAVE_DEFAULT_MATH)
  check_library_exists(m sin "" HAVE_LIBM)
  if (HAVE_LIBM)
    link_libraries(m)
  endif()
endif()
check_library_exists(atomic __atomic_load_8 "" HAVE_LIBATOMIC)
if (HAVE_LIBATOMIC)
  link_libraries(atomic)
endif()
if (NOT WIN32)
  find_package(Threads)
  if (Threads_FOUND)
    link_libraries(${CMAKE_THREAD_LIBS_INIT})
  endif()
endif()

if (WIN32)
  add_compile_definitions(WIN32_LEAN_AND_MEAN)
  if (MSVC)
    add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
    add_compile_definitions(_CRT_NONSTDC_NO_DEPRECATE)
  endif()
endif()

if (CMAKE_SYSTEM_PROCESSOR STREQUAL "aarch64" OR CMAKE_SYSTEM_PROCESSOR STREQUAL "arm64")
  set(ARCH_AARCH64 1)
  enable_language(ASM)
  message(STATUS "dav1d: Enabling aarch64 assembly")
elseif (CMAKE_SYSTEM_PROCESSOR MATCHES "^arm")
  set(ARCH_ARM 1)
  enable_language(ASM)
  message(STATUS "dav1d: Enabling arm assembly")
elseif (CMAKE_SYSTEM_PROCESSOR MATCHES "^i.86$" OR CMAKE_SYSTEM_PROCESSOR MATCHES "^[Xx]86$")
  set(ARCH_I386 1)
  check_language(ASM_NASM)
  if (CMAKE_ASM_NASM_COMPILER)
    enable_language(ASM_NASM)
    message(STATUS "dav1d: Enabling i386 nasm assembly")
  else()
    add_compile_definitions(NO_X86ASM)
    message(STATUS "dav1d: Not enabling i386 nasm assembly")
  endif()
  if (CMAKE_SYSTEM_NAME STREQUAL "Darwin" OR CMAKE_SYSTEM_NAME STREQUAL "Windows")
    set(CMAKE_ASM_NASM_FLAGS "${CMAKE_ASM_NASM_FLAGS} -DPREFIX")
  endif()
elseif (CMAKE_SYSTEM_PROCESSOR STREQUAL "x86_64" OR CMAKE_SYSTEM_PROCESSOR STREQUAL "AMD64" OR CMAKE_SYSTEM_PROCESSOR STREQUAL "amd64")
  set(ARCH_X86_64 1)
  add_compile_definitions(PIC)
  check_language(ASM_NASM)
  if (CMAKE_ASM_NASM_COMPILER)
    enable_language(ASM_NASM)
    message(STATUS "dav1d: Enabling x86_64 nasm assembly")
  else()
    add_compile_definitions(NO_X86ASM)
    message(STATUS "dav1d: Not enabling x86_64 nasm assembly")
  endif()
  set(CMAKE_ASM_NASM_FLAGS "${CMAKE_ASM_NASM_FLAGS} -DARCH_X86_64=1")
  if (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    set(CMAKE_ASM_NASM_FLAGS "${CMAKE_ASM_NASM_FLAGS} -DPREFIX")
  endif()
else()
  message(STATUS "dav1d: Not enabling any assembly optimizations for ${CMAKE_SYSTEM_PROCESSOR}")
endif()

# src

set(dav1d_src
    cdf.c
    cpu.c
    ctx.c
    data.c
    decode.c
    dequant_tables.c
    getbits.c
    intra_edge.c
    itx_1d.c
    lf_mask.c
    lib.c
    log.c
    mem.c
    msac.c
    obu.c
    pal.c
    picture.c
    qm.c
    ref.c
    refmvs.c
    scan.c
    tables.c
    thread_task.c
    warpmv.c
    wedge.c)

if (WIN32)
  list(APPEND dav1d_src
      win32/thread.c)
endif()

set(dav1d_tmpl_src
    cdef_apply_tmpl.c
    cdef_tmpl.c
    fg_apply_tmpl.c
    filmgrain_tmpl.c
    ipred_prepare_tmpl.c
    ipred_tmpl.c
    itx_tmpl.c
    lf_apply_tmpl.c
    loopfilter_tmpl.c
    looprestoration_tmpl.c
    lr_apply_tmpl.c
    mc_tmpl.c
    recon_tmpl.c)

if (ARCH_AARCH64)
  list(APPEND dav1d_src
      arm/cpu.c
      arm/64/itx.S
      arm/64/looprestoration_common.S
      arm/64/msac.S
      arm/64/refmvs.S
      arm/64/cdef.S
      arm/64/filmgrain.S
      arm/64/ipred.S
      arm/64/loopfilter.S
      arm/64/looprestoration.S
      arm/64/mc.S
      arm/64/mc_dotprod.S
      arm/64/cdef16.S
      arm/64/filmgrain16.S
      arm/64/ipred16.S
      arm/64/itx16.S
      arm/64/loopfilter16.S
      arm/64/looprestoration16.S
      arm/64/mc16.S
      arm/64/mc16_sve.S)
elseif (ARCH_ARM)
  list(APPEND dav1d_src
      arm/cpu.c
      arm/32/itx.S
      arm/32/looprestoration_common.S
      arm/32/msac.S
      arm/32/refmvs.S
      arm/32/cdef.S
      arm/32/filmgrain.S
      arm/32/ipred.S
      arm/32/loopfilter.S
      arm/32/looprestoration.S
      arm/32/mc.S
      arm/32/cdef16.S
      arm/32/filmgrain16.S
      arm/32/ipred16.S
      arm/32/itx16.S
      arm/32/loopfilter16.S
      arm/32/looprestoration16.S
      arm/32/mc16.S)
elseif (ARCH_I386 OR ARCH_X86_64)
  list(APPEND dav1d_src
      x86/cpu.c)
  if (CMAKE_ASM_NASM_COMPILER)
    set(x86_nasm_sources
        x86/cpuid.asm
        x86/msac.asm
        x86/pal.asm
        x86/refmvs.asm
        x86/itx_avx512.asm
        x86/cdef_avx2.asm
        x86/itx_avx2.asm
        x86/cdef_sse.asm
        x86/itx_sse.asm
        x86/cdef_avx512.asm
        x86/filmgrain_avx512.asm
        x86/ipred_avx512.asm
        x86/loopfilter_avx512.asm
        x86/looprestoration_avx512.asm
        x86/mc_avx512.asm
        x86/filmgrain_avx2.asm
        x86/ipred_avx2.asm
        x86/loopfilter_avx2.asm
        x86/looprestoration_avx2.asm
        x86/mc_avx2.asm
        x86/filmgrain_sse.asm
        x86/ipred_sse.asm
        x86/loopfilter_sse.asm
        x86/looprestoration_sse.asm
        x86/mc_sse.asm
        x86/cdef16_avx512.asm
        x86/filmgrain16_avx512.asm
        x86/ipred16_avx512.asm
        x86/itx16_avx512.asm
        x86/loopfilter16_avx512.asm
        x86/looprestoration16_avx512.asm
        x86/mc16_avx512.asm
        x86/cdef16_avx2.asm
        x86/filmgrain16_avx2.asm
        x86/ipred16_avx2.asm
        x86/itx16_avx2.asm
        x86/loopfilter16_avx2.asm
        x86/looprestoration16_avx2.asm
        x86/mc16_avx2.asm
        x86/cdef16_sse.asm
        x86/filmgrain16_sse.asm
        x86/ipred16_sse.asm
        x86/itx16_sse.asm
        x86/loopfilter16_sse.asm
        x86/looprestoration16_sse.asm
        x86/mc16_sse.asm)
    list(APPEND dav1d_src
        ${x86_nasm_sources})
    list(TRANSFORM x86_nasm_sources PREPEND ${TEST_SUITE_DAV1D_ROOT}/src/)
    set_source_files_properties(${x86_nasm_sources} PROPERTIES LANGUAGE ASM_NASM)
  endif()
endif()

list(TRANSFORM dav1d_tmpl_src PREPEND ${TEST_SUITE_DAV1D_ROOT}/src/)
list(TRANSFORM dav1d_src PREPEND ${TEST_SUITE_DAV1D_ROOT}/src/)

foreach(bitdepth 8 16)
  llvm_test_library(dav1d_bitdepth_${bitdepth} OBJECT ${dav1d_tmpl_src})
  target_compile_definitions(dav1d_bitdepth_${bitdepth} PRIVATE -DBITDEPTH=${bitdepth})
  list(APPEND bitdepth_libraries dav1d_bitdepth_${bitdepth})
endforeach()

llvm_test_library(dav1d_lib ${dav1d_src})
target_link_libraries(dav1d_lib LINK_PRIVATE ${bitdepth_libraries})


# tools

set(dav1d_cli_src
    dav1d.c
    dav1d_cli_parse.c
    input/input.c
    input/annexb.c
    input/ivf.c
    input/section5.c
    output/md5.c
    output/null.c
    output/output.c
    output/y4m2.c
    output/yuv.c)

if (WIN32)
  list(APPEND dav1d_cli_src
      compat/getopt.c)
endif()

list(TRANSFORM dav1d_cli_src PREPEND ${TEST_SUITE_DAV1D_ROOT}/tools/)

llvm_test_executable_no_test(dav1d ${dav1d_cli_src})

target_include_directories(dav1d PRIVATE ${TEST_SUITE_DAV1D_ROOT}/tools)
target_link_libraries(dav1d PRIVATE dav1d_lib)


# checkasm

set(checkasm_src
    checkasm.c
    msac.c
    pal.c
    refmvs.c)

set(checkasm_tmpl_src
    cdef.c
    filmgrain.c
    ipred.c
    itx.c
    loopfilter.c
    looprestoration.c
    mc.c)

if (ARCH_AARCH64)
  list(APPEND checkasm_src
      arm/checkasm_64.S)
elseif (ARCH_ARM)
  list(APPEND checkasm_src
      arm/checkasm_32.S)
elseif (ARCH_I386 OR ARCH_X86_64)
  if (CMAKE_ASM_NASM_COMPILER)
    set(x86_nasm_sources
        x86/checkasm.asm)
    list(APPEND checkasm_src
        ${x86_nasm_sources})
    list(TRANSFORM x86_nasm_sources PREPEND ${TEST_SUITE_DAV1D_ROOT}/tests/checkasm/)
    set_source_files_properties(${x86_nasm_sources} PROPERTIES LANGUAGE ASM_NASM)
  endif()
endif()

list(TRANSFORM checkasm_tmpl_src PREPEND ${TEST_SUITE_DAV1D_ROOT}/tests/checkasm/)
list(TRANSFORM checkasm_src PREPEND ${TEST_SUITE_DAV1D_ROOT}/tests/checkasm/)

foreach(bitdepth 8 16)
  llvm_test_library(checkasm_bitdepth_${bitdepth} OBJECT ${checkasm_tmpl_src})
  target_compile_definitions(checkasm_bitdepth_${bitdepth} PRIVATE -DBITDEPTH=${bitdepth})
  list(APPEND bitdepth_libraries checkasm_bitdepth_${bitdepth})
endforeach()

llvm_test_run()
llvm_test_executable(dav1d_checkasm ${checkasm_src})
target_link_libraries(dav1d_checkasm LINK_PRIVATE ${bitdepth_libraries})
target_link_libraries(dav1d_checkasm PRIVATE dav1d_lib)
