# BIND(C) is not implemented for x86_64 Windows, so do not enable the test on
# Windows yet.
if (NOT WIN32)
  llvm_multisource(bind-c-value)

  file(COPY lit.local.cfg DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
endif()
