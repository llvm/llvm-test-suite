add_subdirectory(HPCCG)
add_subdirectory(PENNANT)
add_subdirectory(miniFE)
if(NOT CMAKE_SYSTEM_NAME MATCHES "AIX")
# [DEV] Disable CLAMR
# add_subdirectory(CLAMR)
endif()
add_subdirectory(HACCKernels)
