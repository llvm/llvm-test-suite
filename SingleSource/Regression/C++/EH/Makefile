LEVEL = ../../../..
REQUIRES_EH_SUPPORT = 1

ifdef CC_UNDER_TEST_IS_CLANG
EXEC_XFAILS = ConditionalExpr
endif

CFLAGS += -std=c99
LDFLAGS += -lstdc++
include $(LEVEL)/SingleSource/Makefile.singlesrc
