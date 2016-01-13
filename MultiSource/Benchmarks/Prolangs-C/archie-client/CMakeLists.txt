set(DIRS)
set(PARALLEL_DIRS)


include(CheckFunctionExists)
check_function_exists(re_comp HAVE_RE_COMP)

if(HAVE_RE_COMP)
  set(PROG archie)
  if("${TARGET_OS}" STREQUAL "SunOS")
    list(APPEND LDFLAGS -lsocket -lnsl)
  endif()
  llvm_multisource()
endif()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
