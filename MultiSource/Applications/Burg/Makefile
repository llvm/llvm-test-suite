LEVEL = ../../..

PROG     = burg
CPPFLAGS = -DDEBUG
CFLAGS  += -std=gnu89 -Wno-int-conversion
LDFLAGS  = -lstdc++

STDIN_FILENAME = $(PROJ_SRC_DIR)/sample.gr

include $(LEVEL)/Makefile.config

Source  := $(ExtraSource) $(wildcard $(PROJ_SRC_DIR)/*.c)

include	$(LEVEL)/MultiSource/Makefile.multisrc

lex.c: y.tab.h

src:
	echo Sources = $(Source)

clean::
	rm -f y.tab.* gram.cpp gram.h
