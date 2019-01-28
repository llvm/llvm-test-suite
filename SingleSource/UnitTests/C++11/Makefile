# SingleSource/UnitTests/C++11/Makefile
LEVEL = ../../..
include $(LEVEL)/Makefile.config

CPPFLAGS += -std=c++11 -pthread

ifdef BENCHMARKING_ONLY
PROGRAMS_TO_SKIP += stdthreadbug
else
ifeq (-static, $(findstring -static, $(TARGET_FLAGS)))
LDFLAGS += -Wl,--whole-archive -lpthread -Wl,--no-whole-archive
endif
endif

LDFLAGS += -lstdc++ -pthread
include $(LEVEL)/SingleSource/Makefile.singlesrc
