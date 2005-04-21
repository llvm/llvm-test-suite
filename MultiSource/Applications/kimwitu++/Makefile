LEVEL = ../../..
PROG = kc
CPPFLAGS=-I$(PROJ_SRC_DIR) -DYYDEBUG=1
LDFLAGS = -lstdc++
LIBS += -lstdc++
RUN_OPTIONS = -f test  -o -v -s kcc $(PROJ_SRC_DIR)/inputs/f3.k $(PROJ_SRC_DIR)/inputs/f2.k $(PROJ_SRC_DIR)/inputs/f1.k
include ../../Makefile.multisrc

