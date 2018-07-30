LEVEL    = ../../../..
LIBS    += -lm
LDFLAGS += -lm
PROG     = hotspot
CFLAGS  += -I$(PROJ_SRC_DIR)/../Common
Source   = hotspotKernel.c main.c ../Common/glibc_compat_rand.c

FP_ABSTOLERANCE :=  0.00001

include	$(LEVEL)/MultiSource/Makefile.multisrc
