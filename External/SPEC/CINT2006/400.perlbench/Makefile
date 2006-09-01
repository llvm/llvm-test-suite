##===- Makefile --------------------------------------------*- Makefile -*-===##
#
# This makefile contains information for building the SPEC2006 400.perlbench
# test.
#
##===----------------------------------------------------------------------===##

LEVEL = ../../../..

Source = $(addprefix $(SPEC_BENCH_DIR)/src/, \
     av.c deb.c doio.c doop.c dump.c globals.c gv.c hv.c locale.c mg.c        \
     numeric.c op.c pad.c perl.c perlapi.c perlio.c perlmain.c perly.c pp.c   \
     pp_ctl.c pp_hot.c pp_pack.c pp_sort.c pp_sys.c regcomp.c regexec.c run.c \
     scope.c sv.c taint.c toke.c universal.c utf8.c util.c xsutils.c Base64.c \
     Cwd.c Dumper.c HiRes.c IO.c Peek.c attrs.c poll.c stdio.c DynaLoader.c   \
     MD5.c Storable.c Parser.c specrand.c Hostname.c Opcode.c)

include ../../Makefile.spec2006

CPPFLAGS += -DPERL_CORE

ifeq ($(OS),Darwin)
ifeq ($(ARCH),PowerPC)
  CPPFLAGS += -DSPEC_CPU_MACOSX_PPC
else
ifeq ($(ARCH),x86)
  CPPFLAGS += -DSPEC_CPU_MACOSX_IA32
endif
endif
endif

ifeq ($(RUN_TYPE),test)
  RUN_OPTIONS = xxx
else
  RUN_OPTIONS = xxx
endif
