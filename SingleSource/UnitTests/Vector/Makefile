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

# FIXME: CBE doesn't support vectors yet: PR1126
DISABLE_CBE=1

include $(LEVEL)/SingleSource/Makefile.singlesrc


