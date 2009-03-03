##===- Makefile --------------------------------------------*- Makefile -*-===##
#
# This makefile contains information for building the SPEC2006 xalancbmk test.
#
##===----------------------------------------------------------------------===##

LEVEL = ../../../..
include $(LEVEL)/Makefile.config

CPPFLAGS += -DNDEBUG -DAPP_NO_THREADS -DXALAN_INMEM_MSG_LOADER        \
            -DPROJ_XMLPARSER -DPROJ_XMLUTIL -DPROJ_PARSERS            \
            -DPROJ_SAX4C -DPROJ_SAX2 -DPROJ_DOM -DPROJ_VALIDATORS     \
            -DXML_USE_NATIVE_TRANSCODER -DXML_USE_INMEM_MESSAGELOADER \
            -DXML_USE_PTHREADS                                        \
            -I$(SPEC_BENCH_DIR)/src/xercesc                           \
            -I$(SPEC_BENCH_DIR)/src/xercesc/dom                       \
            -I$(SPEC_BENCH_DIR)/src/xercesc/dom/impl                  \
            -I$(SPEC_BENCH_DIR)/src/xercesc/sax                       \
            -I$(SPEC_BENCH_DIR)/src/xercesc/util/MsgLoaders/InMemory  \
            -I$(SPEC_BENCH_DIR)/src/xercesc/util/Transcoders/Iconv    \
            -I$(SPEC_BENCH_DIR)/src/xalanc/include

ifeq ($(OS),Darwin)
  CPPFLAGS += -DSPEC_CPU_MACOSX
endif
ifeq ($(OS),Linux)
  CPPFLAGS += -DSPEC_CPU_LINUX
endif

LDFLAGS = -lstdc++ -lm
LIBS    = -lstdc++ -lm

include ../../Makefile.spec2006

ifeq ($(RUN_TYPE),test)
  RUN_OPTIONS      = -v test.xml xalanc.xsl
  STDOUT_FILENAME := test.out
else
  RUN_OPTIONS      = -v allbooks.xml xalanc.xsl
  STDOUT_FILENAME := train.out
endif
