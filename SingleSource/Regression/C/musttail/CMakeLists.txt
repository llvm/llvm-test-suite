# Regression tests for `__attribute__((musttail))` argument forwarding.
#
# Triggered by LLVM PR #185094, which fixed a RISC-V miscompile where
# indirectly-passed arguments were re-spilled into the caller's frame
# before a musttail call, leaving the forwarded pointer dangling after
# the tail call deallocated the frame.
#
# The tests cover paths shared with AArch64 (SVE-disabled) and x86_64:
# 256-bit struct args are too large for the by-value paths on all three,
# so they all flow through the indirect-arg / sret machinery.
#
# Gated on Clang because GCC does not support __attribute__((musttail)).
if(CMAKE_C_COMPILER_ID STREQUAL "Clang")
  llvm_singlesource(PREFIX "Regression-C-musttail-")
endif()
