# SingleSource/UnitTests/Matrix/Makefile
LEVEL = ../../..

include $(LEVEL)/Makefile.config

DIRS = 

ifeq ($(CC_UNDER_TEST_IS_CLANG), 1)
# FIXME: Once testing infrastructure runs on sapphirerapids, we should change following line.
# currenly we only test compilation results of AMX cases
ifeq ($(HAVE_X86_AVX512F_INSTRUCTIONS), 1)
DIRS += AMXINT8
endif
endif

include $(LEVEL)/SingleSource/Makefile.singlesrc


