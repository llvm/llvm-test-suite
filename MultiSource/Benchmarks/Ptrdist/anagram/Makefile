LEVEL=../../../..

#include $(LLVM_OBJ_ROOT)/Makefile.config

PROG = anagram
#OBJS = anagram.o
RUN_OPTIONS = $(PROJ_SRC_DIR)/words 2
STDIN_FILENAME = $(PROJ_SRC_DIR)/input.OUT

include $(LEVEL)/MultiSource/Makefile.multisrc
 
#test:
#	$(SIM) ./anagram words < input.in > FOO
#	$(DIFF) FOO input.OUT
#	rm -f FOO
