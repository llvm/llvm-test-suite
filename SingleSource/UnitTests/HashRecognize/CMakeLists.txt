include(CheckCCompilerFlag)

llvm_singlesource()

function(llvm_hashrecognize_variant variant_name llvm_flag)
  check_c_compiler_flag("-mllvm ${llvm_flag}" HAS_LLVM_FLAG_${variant_name})
  if (HAS_LLVM_FLAG_${variant_name})
    set(BASE_CFLAGS ${CFLAGS})
    list(APPEND CFLAGS "-mllvm" ${llvm_flag})
    llvm_singlesource(PREFIX "${variant_name}-" DEST_SUFFIX "-${variant_name}")
    set(CFLAGS ${BASE_CFLAGS})
  endif()
endfunction()

if ("${CMAKE_C_COMPILER_ID}" MATCHES "Clang")
  llvm_hashrecognize_variant("no-hr" "-disable-loop-idiom-hashrecognize")
endif()
