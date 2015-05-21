# SingleSource/UnitTests/C++11/Makefile
LEVEL = ../../..
include $(LEVEL)/Makefile.config

CPPFLAGS += -std=c++11 -pthread

ifdef BENCHMARKING_ONLY
PROGRAMS_TO_SKIP += stdthreadbug
endif

LDFLAGS += -lstdc++ -pthread
include $(LEVEL)/SingleSource/Makefile.singlesrc
