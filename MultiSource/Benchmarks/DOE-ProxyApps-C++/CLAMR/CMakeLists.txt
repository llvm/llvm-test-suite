include(CheckIncludeFiles)

# Allow CLAMR tests only if the target has 'sys/queue.h' header file.
# The header is not shipped with musl and might be missing for such targets.
# See https://wiki.musl-libc.org/faq.html#Q:-Why-is-%3Ccode%3Esys/queue.h%3C/code%3E-not-included?
# This header is requred by genmalloc.c, but we cannot exclude just
# a single file and need to disable the whole test.
check_include_files("sys/queue.h" HAVE_SYS_QUEUE_INCLUDE LANGUAGE C)

set(RUN_OPTIONS -n 64 -t 1000)
# Floating point contraction must be suppressed due to accuracy issues
list(APPEND CXXFLAGS -ffp-contract=off -DFMA_DISABLED=1)
list(APPEND CFLAGS -ffp-contract=off -DFMA_DISABLED=1)

if (HAVE_SYS_QUEUE_INCLUDE)
  llvm_multisource(CLAMR)
else()
  message(WARNING "The 'sys/queue.h' file is missing for the target platform, disabling the 'CLAMR' test.")
endif()
