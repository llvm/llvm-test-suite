LEVEL = ../../../../../..
ifdef LARGE_PROBLEM_SIZE
RUN_OPTIONS     := -frames 500
else
RUN_OPTIONS     := -frames 10
endif

RUN_OPTIONS += -meshfile mesa.in -ppmfile mesa.ppm
#STDIN_FILENAME  = ammp.in
#STDOUT_FILENAME = ammp.out
CPPFLAGS =
include ../../Makefile.spec
