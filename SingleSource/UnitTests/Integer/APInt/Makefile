# SingleSource/UnitTests/Integer/Makefile
LEVEL = ../../../..
DISABLE_JIT := 1

include $(LEVEL)/SingleSource/Makefile.singlesrc

LDFLAGS += -L$(LLVM_OBJ_ROOT)/Debug/lib -lLLVMSupport -lLLVMSystem -lstdc++
CXXFLAGS += -I$(LLVM_SRC_ROOT)/include -D_GNU_SOURCE -D__STDC_LIMIT_MACROS -D__NO_MATH_INLINES -g -O0
