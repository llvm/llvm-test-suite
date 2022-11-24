LEVEL = ../../../..

include $(LEVEL)/Makefile.config

CXXFLAGS += -Wno-implicit-function-declaration
CFLAGS += -Wno-implicit-function-declaration

# This test uses the deprecated re_comp functions.
ifdef HAVE_RE_COMP
PROG = archie
endif

include $(LEVEL)/MultiSource/Makefile.multisrc

ifeq ($(TARGET_OS),SunOS)
LDFLAGS += -lsocket -lnsl
endif

# archie-client utilizes functions from <netdb.h>. However, since
# _XOPEN_SOURCE=700 is defined globally on AIX, it prevents us from having
# access to some of the functions that are required within archie-client.
# Thus, _XOPEN_SOURCE=600 is defined explicitly for AIX to resolve this issue.
ifeq ($(TARGET_OS),AIX)
CFLAGS += -D_XOPEN_SOURCE=600
CXXFLAGS += -D_XOPEN_SOURCE=600
endif
