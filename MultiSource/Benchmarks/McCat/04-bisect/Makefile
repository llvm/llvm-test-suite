LEVEL = ../../../../../..
PROG = bisect
LDFLAGS = -lm
#RUN_OPTIONS += 

include $(LEVEL)/Makefile.config

STDIN_FILENAME = $(BUILD_SRC_DIR)/bisect_test.in

# This program is adversely effected by the underlying precision of the machine
PROGRAM_IS_NONDETERMINISTIC = 1

include $(LEVEL)/test/Programs/MultiSource/Makefile.multisrc
