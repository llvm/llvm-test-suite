LEVEL=../../../../../..

include $(LEVEL)/Makefile.config

PROG = anagram
#OBJS = anagram.o
RUN_OPTIONS = words 
STDIN_FILENAME = $(BUILD_SRC_DIR)/input.OUT

include $(LEVEL)/test/Programs/MultiSource/Makefile.multisrc
 
#test:
#	$(SIM) ./anagram words < input.in > FOO
#	$(DIFF) FOO input.OUT
#	rm -f FOO
