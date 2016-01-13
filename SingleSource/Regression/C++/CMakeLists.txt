set(DIRS)
set(PARALLEL_DIRS)

set(LEVEL ../../..)
set(DIRS EH)
if(DEFINED BENCHMARKING_ONLY)
  list(APPEND PROGRAMS_TO_SKIP 2003-05-14-array-init 2003-05-14-expr_stmt 2003-06-08-BaseType 2003-06-08-VirtualFunctions 2003-06-13-Crasher 2003-08-20-EnumSizeProblem 2003-09-29-NonPODsByValue 2008-01-29-ParamAliasesReturn 2011-03-28-Bitfield BuiltinTypeInfo fixups global_ctor global_type ofstream_ctor pointer_member pointer_method pointer_method2 short_circuit_dtor)
endif()
list(APPEND LDFLAGS -lstdc++)
llvm_singlesource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
