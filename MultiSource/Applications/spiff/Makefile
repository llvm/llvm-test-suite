LEVEL = ../../..
PROG     = spiff
CPPFLAGS = 
LDFLAGS  =

#RUN_OPTIONS = $(PROJ_SRC_DIR)/Sample.1 $(PROJ_SRC_DIR)/Sample.2
RUN_OPTIONS = $(PROJ_SRC_DIR)/Sample.3 $(PROJ_SRC_DIR)/Sample.4
#RUN_OPTIONS = ./Sample.3 ./Sample.4
#RUN_OPTIONS = ./one ./two
# you get the idea...

ifeq ($(ARCH),XCore)
ifndef SMALL_PROBLEM_SIZE
XCORE_TARGET_NEEDS_MEMORY = 1024
endif
endif

include ../../Makefile.multisrc

