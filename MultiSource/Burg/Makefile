LEVEL = ../../../..

PROG     = burg
CPPFLAGS = -DDEBUG 
CFLAGS   = -g
LDFLAGS  = 

ExtraSource := y.tab.c

STDIN_FILENAME = sample.gr

Source  := $(ExtraSource) $(wildcard *.c)

## $(BUILD_ROOT)/Depend/y.tab.d:: y.tab.c $(BUILD_ROOT)/Depend/.dir

%.cpp %.h : %.y
	yacc -d $<
	$(VERB) cp -p y.tab.c $(basename $@).cpp
	$(VERB) cp -p y.tab.h $(basename $@).h

##	$(VERB) mv -f $(basename $@).tab.c $(basename $@).cpp
##	$(VERB) mv -f $(basename $@).tab.h $(basename $@).h

include	../Makefile.multisrc

y.tab.c y.tab.h: gram.y
	yacc -d $<

Source := $(patsubst gram.%,,$(Source))

## $(BUILD_ROOT)/Depend/gram.d: gram.y

src:
	echo Sources = $(Source)

clean::
	rm -f y.tab.* gram.cpp gram.h
