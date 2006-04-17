LEVEL = ../..

include $(LEVEL)/Makefile.config

PROG = nurbs
SourceDir := $(NURBS_ROOT)

CPPFLAGS =
LDFLAGS = -lstdc++
LIBS += -lstdc++

RUN_OPTIONS = /k all timed /t 500 /vsteps 64 /usteps 64 /vcp 20 /ucp 20

include $(LEVEL)/MultiSource/Makefile.multisrc
