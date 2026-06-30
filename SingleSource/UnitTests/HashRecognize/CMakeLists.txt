include(CheckCCompilerFlag)

llvm_singlesource()

function(llvm_hashrecognize_variant prefix)
  llvm_singlesource(PREFIX "${prefix}-" DEST_SUFFIX "-${prefix}")
endfunction()

if ("${CMAKE_C_COMPILER_ID}" MATCHES "Clang")
  check_c_compiler_flag("-mllvm -disable-loop-idiom-hashrecognize" HAS_DISABLE_HASHRECOGNIZE)
  if (HAS_DISABLE_HASHRECOGNIZE)
    set(BASE_CFLAGS ${CFLAGS})

    list(APPEND CFLAGS "-mllvm" "-disable-loop-idiom-hashrecognize")
    llvm_hashrecognize_variant("no-hr")
    set(CFLAGS ${BASE_CFLAGS})
  endif()
endif()
