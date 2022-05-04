LEVEL = ../../../..

PROG     = office-ispell
CPPFLAGS = -Dconst=
CFLAGS += -Wno-implicit-function-declaration -Wno-implicit-int
LDFLAGS  = -lm
RUN_OPTIONS = -a -d $(PROJ_SRC_DIR)/americanmed+
STDIN_FILENAME = $(PROJ_SRC_DIR)/large.txt

include $(LEVEL)/MultiSource/Makefile.multisrc
