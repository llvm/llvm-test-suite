list(APPEND LDFLAGS -lstdc++ -lobjc -framework Foundation)
if(DEFINED CC_UNDER_TEST_IS_LLVM_GCC)
  set(PROGRAMS_TO_SKIP property-reference-object)
endif()
