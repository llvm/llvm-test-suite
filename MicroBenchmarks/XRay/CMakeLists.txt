add_subdirectory(ReturnReference)
if(NOT TARGET_OS STREQUAL "Darwin")
  # FDRMode test is failing on Darwin because
  # `__xray_log_select_mode("xray-fdr")` returns `XRAY_MODE_NOT_FOUND`.
  #
  # Disable the test until it is fixed. rdar://problem/44578416
  add_subdirectory(FDRMode)
endif()
