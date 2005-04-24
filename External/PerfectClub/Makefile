LEVEL = ../../..
include $(LEVEL)/Makefile.config

# We can only compile these SPEC benchmarks with F2C
ifdef USE_F2C
PARALLEL_DIRS := \
  adm \
  arc2d \
  bdna \
else
PARALLEL_DIRS :=
endif

include $(LEVEL)/External/Makefile.external
