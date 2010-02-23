# SingleSource/UnitTests/Makefile
LEVEL = ../..
include $(LEVEL)/Makefile.config

DIRS := SetjmpLongjmp

# FIXME: Disable SJLJ tests for now, until EH edges are represented.
DIRS :=

DIRS += Vector 

DIRS += SignlessTypes Threads

# Only test Obj-C on darwin/x86 for time being.
ifeq ($(TARGET_OS),Darwin)
ifeq ($(ARCH),x86)
DIRS += ObjC ObjC++
endif
ifeq ($(ARCH),x86_64)
DIRS += ObjC ObjC++
endif
endif

# Darwin doesn't support weak/weak_import in a way that we can test in this
# framework.
ifeq ($(TARGET_OS),Darwin)
PROGRAMS_TO_SKIP := 2007-04-25-weak
endif

PROGRAM_REQUIRED_TO_EXIT_OK := 1
include $(LEVEL)/SingleSource/Makefile.singlesrc
