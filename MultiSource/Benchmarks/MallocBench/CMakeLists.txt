add_subdirectory(espresso)
add_subdirectory(gs)
if(NOT "${ARCH}" STREQUAL "Alpha")
  # [DEV] Disable cfrac
  # add_subdirectory(cfrac)
endif()
