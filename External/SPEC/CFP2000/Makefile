LEVEL = ../../..
include $(LEVEL)/Makefile.config

PARALLEL_DIRS :=   \
	177.mesa   \
	179.art    \
	183.equake \
	188.ammp

ifdef USE_F2C
PARALLEL_DIRS += \
	168.wupwise \
	171.swim    \
	172.mgrid   \
        173.applu
endif


include $(LEVEL)/Makefile.programs
