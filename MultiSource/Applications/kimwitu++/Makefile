LEVEL = ../../..
PROG = kc
CPPFLAGS=-I$(BUILD_SRC_DIR) -DYYDEBUG=1
LDFLAGS = -lstdc++
LIBS += -lstdc++
RUN_OPTIONS = -o -v -s kcc $(BUILD_SRC_DIR)/inputs/rpn.k $(BUILD_SRC_DIR)/inputs/main.k $(BUILD_SRC_DIR)/inputs/abs.k
include ../../Makefile.multisrc
