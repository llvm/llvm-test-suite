LEVEL = ../../../../../..

PROG     = mason
CPPFLAGS = -DVERSION='"1.00"' -DCOMPDATE="\"today\"" -DCFLAGS='""' -DHOSTNAME="\"thishost\"" 
#LDFLAGS  = -lm
ifdef LARGE_PROBLEM_SIZE
RUN_OPTIONS = ref.in
else
RUN_OPTIONS = test.in
endif
include $(LEVEL)/test/Programs/MultiSource/Makefile.multisrc

