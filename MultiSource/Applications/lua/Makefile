LEVEL = ../../../

Source = lapi.c lcode.c ldebug.c ldo.c ldump.c lfunc.c lgc.c llex.c lmem.c\
	 lobject.c lopcodes.c lparser.c lstate.c lstring.c ltable.c ltm.c\
	 lundump.c lvm.c lzio.c lauxlib.c lbaselib.c ldblib.c liolib.c lmathlib.c\
	 loslib.c ltablib.c lstrlib.c loadlib.c linit.c lua.c

LDFLAGS += -lm
CPPFLAGS += -DLUA_USE_POSIX

PROG = lua
RUN_OPTIONS = alltests.lua <in

include $(LEVEL)/Makefile.config

include ../../Makefile.multisrc
DIFFPROG := $(PROGDIR)/DiffOutput.sh "diff "

# generate input files
lua.c: .input_generated

.input_generated:
	./generate_inputs.sh
