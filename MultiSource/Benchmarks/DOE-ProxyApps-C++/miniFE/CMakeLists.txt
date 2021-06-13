list(APPEND CXXFLAGS -I. -DMINIFE_SCALAR=double  -DMINIFE_LOCAL_ORDINAL=int -DMINIFE_GLOBAL_ORDINAL=int -DMINIFE_CSR_MATRIX -DREDSTORM) # -DREDSTORM for mkdir
# Use X/OPEN compatibility flag on AIX to avoid problems with some
# versions of the system headers. Define "UseTimes" to avoid usages of
# "struct timezone" in some source files because it's not available on
# AIX when the compatibility flag is set.
if(CMAKE_SYSTEM_NAME STREQUAL "AIX")
  list(APPEND CXXFLAGS -D_XOPEN_SOURCE=700 -DUseTimes)
endif()
# Floating point contraction must be suppressed due to accuracy issues
list(APPEND CXXFLAGS -ffp-contract=off -DFMA_DISABLED=1)
list(APPEND CFLAGS -ffp-contract=off -DFMA_DISABLED=1)

list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS -nx 64 -ny 64 -nz 64)
llvm_multisource(miniFE)
target_include_directories(miniFE PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
