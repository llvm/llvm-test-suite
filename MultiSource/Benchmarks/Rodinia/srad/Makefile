LEVEL    = ../../../..
LIBS    += -lm
LDFLAGS += -lm
PROG     = srad
CFLAGS  += -I$(PROG_SRC_DIR)/../Common
Source   = sradKernel.c main.c ../Common/glibc_compat_rand.c 

FP_ABSTOLERANCE :=  0.00001

include	$(LEVEL)/MultiSource/Makefile.multisrc

