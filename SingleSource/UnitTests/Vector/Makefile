# SingleSource/UnitTests/Vector/Makefile
LEVEL = ../../..

include $(LEVEL)/Makefile.config

DIRS = 

ifeq ($(ARCH),PowerPC)
DIRS += Altivec
endif

ifeq ($(ARCH),x86)
DIRS += SSE
endif
ifeq ($(ARCH),x86_64)
DIRS += SSE
endif

include $(LEVEL)/SingleSource/Makefile.singlesrc


