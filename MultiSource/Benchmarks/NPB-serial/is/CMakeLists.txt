if(SMALL_PROBLEM_SIZE)
  list(APPEND CPPFLAGS -DSMALL_PROBLEM_SIZE)
endif()
llvm_multisource(is)
