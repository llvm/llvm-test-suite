LEVEL = ../../..
include $(LEVEL)/Makefile.config

PARALLEL_DIRS :=   \
	177.mesa   \
	179.art    \
	183.equake \
	188.ammp

# These are f90 and hence cannot be converted with f2c:
# 178.galgel, 187.facerec, 189.lucas, 191.fma3d
#
# These are broken with f2c: output does not compile natively
# 200.sixtrack, 301.apsi

ifdef USE_F2C
PARALLEL_DIRS += \
	168.wupwise \
	171.swim    \
	172.mgrid   \
	173.applu
endif

include $(LEVEL)/Makefile.programs
