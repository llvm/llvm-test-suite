LEVEL = ../../../..

PROG       = treeadd
CPPFLAGS   = -DTORONTO
LDFLAGS    = 

ifdef SMALL_PROBLEM_SIZE
RUN_OPTIONS = 20
REFERENCE_OUTPUT_FILE = $(PROJ_SRC_DIR)/reference-output.small
else
RUN_OPTIONS = 22
REFERENCE_OUTPUT_FILE = $(PROJ_SRC_DIR)/reference-output.normal
endif

include $(LEVEL)/MultiSource/Makefile.multisrc

