# SingleSource/UnitTests/Integer/Makefile
LEVEL = ../../../..
DISABLE_JIT := 1

include $(LEVEL)/SingleSource/Makefile.singlesrc

CXXFLAGS += -I$(LLVM_SRC_ROOT)/include -D_GNU_SOURCE -D__STDC_LIMIT_MACROS -D__NO_MATH_INLINES
ifeq ($(ENABLE_PROFILING),1)
LDFLAGS += -L$(LLVM_OBJ_ROOT)/Profile/lib 
CXXFLAGS += -g -pg -O3
else
LDFLAGS += -L$(LLVM_OBJ_ROOT)/Debug/lib 
CXXFLAGS += -g -O0
endif
LDFLAGS += -lLLVMSupport -lLLVMSystem -lstdc++
