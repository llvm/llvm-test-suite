LEVEL = ../../..
PARALLEL_DIRS  := NP city deriv1 deriv2 employ family fsm garage \
                  life objects ocean office primes shapes simul trees vcirc

ifdef BENCHMARKING_ONLY
PARALLEL_DIRS := $(filter-out deriv1, $(PARALLEL_DIRS))
PARALLEL_DIRS := $(filter-out deriv2, $(PARALLEL_DIRS))
PARALLEL_DIRS := $(filter-out family, $(PARALLEL_DIRS))
PARALLEL_DIRS := $(filter-out fsm, $(PARALLEL_DIRS))
PARALLEL_DIRS := $(filter-out garage, $(PARALLEL_DIRS))
PARALLEL_DIRS := $(filter-out NP, $(PARALLEL_DIRS))
PARALLEL_DIRS := $(filter-out objects, $(PARALLEL_DIRS))
PARALLEL_DIRS := $(filter-out office, $(PARALLEL_DIRS))
PARALLEL_DIRS := $(filter-out shapes, $(PARALLEL_DIRS))
PARALLEL_DIRS := $(filter-out trees, $(PARALLEL_DIRS))
PARALLEL_DIRS := $(filter-out vcirc, $(PARALLEL_DIRS))
endif

include $(LEVEL)/Makefile.programs
