# Enable the VPlan-native path for outer-loop vectorization. Disable
# vectorization in general (`#pragma clang loop vectorize(enable)` overwrites
# this) because the two code paths do not mix well.
list(APPEND CXXFLAGS "-mllvm" "-enable-vplan-native-path" "-fno-vectorize")

llvm_singlesource()
