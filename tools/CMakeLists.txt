add_executable(timeit-target timeit.c)

# FIXME: These need to be host-compiled, if we're cross compiling.
# FIXME: Replicate Makefile.tools's logic for determining whether to use fpcmp/fpcmp.sh
add_executable(fpcmp fpcmp.c)
add_executable(timeit timeit.c)
