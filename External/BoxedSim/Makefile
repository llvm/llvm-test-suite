LEVEL = ../..
                                                                                
include $(LEVEL)/Makefile.config
                                                                                
PROG = bsim
SourceDir := $(BOXEDSIM_ROOT)
CFLAGS += -I$(BOXEDSIM_ROOT) -DBASENAME="\"boxed-async\""
LIBS += -lm
LDFLAGS += -lm
                                                                                
RUN_OPTIONS = -n 15 -s 10
include $(LEVEL)/MultiSource/Makefile.multisrc

