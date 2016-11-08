# XCore and older Darwin version do not support thread local storage
if(NOT ARCH STREQUAL "XCore" AND NOT ARCH STREQUAL "Darwin")
  list(APPEND LDFLAGS -pthread)
  list(APPEND CFLAGS -pthread)
  llvm_singlesource()
endif()
