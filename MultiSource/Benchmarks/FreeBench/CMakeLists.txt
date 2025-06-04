add_subdirectory(distray)
# [DEV] Disable fourinarow
# add_subdirectory(fourinarow)
add_subdirectory(mason)
add_subdirectory(neural)
add_subdirectory(pcompress2)
# [DEV] Disable pifft
# add_subdirectory(pifft)
if(NOT "${ARCH}" STREQUAL "Sparc")
  add_subdirectory(analyzer)
endif()
