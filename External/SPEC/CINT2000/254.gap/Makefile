LEVEL = ../../../../../..
RUN_OPTIONS     = -l ./ -q -m 64M \< $(RUN_TYPE).in
STDOUT_FILENAME = $(RUN_TYPE).out
CPPFLAGS = -DSYS_IS_USG -DSYS_HAS_CALLOC_PROTO -DSYS_HAS_IOCTL_PROTO -DSYS_HAS_TIME_PROTO
include ../../Makefile.spec
