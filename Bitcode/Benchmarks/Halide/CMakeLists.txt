if(NOT WIN32)
  list(APPEND LDFLAGS -lpthread -ldl)
endif()
if(NOT MSVC)
  list(APPEND CXXFLAGS "-std=c++11")
endif()

macro(test_img_input img)
  set(imgpath "${CMAKE_CURRENT_SOURCE_DIR}/../images/${img}")
  llvm_test_run(${imgpath}.bytes ${ARGN}
	        ${CMAKE_CURRENT_BINARY_DIR}/${img}_out.bytes)
  llvm_test_verify(${FPCMP}
    ${CMAKE_CURRENT_SOURCE_DIR}/output/${img}_out.bytes
    ${CMAKE_CURRENT_BINARY_DIR}/${img}_out.bytes
  )
endmacro()

if(ARCH STREQUAL "x86")
  add_subdirectory(local_laplacian)
  add_subdirectory(bilateral_grid)
  add_subdirectory(blur)
endif()
