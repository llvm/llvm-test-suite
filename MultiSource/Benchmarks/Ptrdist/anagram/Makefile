LEVEL=../../../..

#include $(LLVM_OBJ_ROOT)/Makefile.config

PROG = anagram
#OBJS = anagram.o
RUN_OPTIONS = $(BUILD_SRC_DIR)/words 
STDIN_FILENAME = $(BUILD_SRC_DIR)/input.OUT

include $(LEVEL)/MultiSource/Makefile.multisrc
 
#test:
#	$(SIM) ./anagram words < input.in > FOO
#	$(DIFF) FOO input.OUT
#	rm -f FOO
