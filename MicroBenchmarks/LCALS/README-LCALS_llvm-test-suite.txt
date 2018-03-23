##################### llvm test suite notes ########################

The following changes were made to the source to add LCALS to the
llvm test suite using the google benchmark library.

Macro'd out reporting and the built in control of the suite to 
allow the benchmark library to control run and time information.
The loop data initialization and cache flushing is maintained, but 
the checksum information cannot be used in the test suite as it 
can show slight differences due to compiler optimizations.
The "Raw" and "ForeachLambda" versions of the loops have been 
rewritten to be used by the google benchmark library, while 
the files included other versions have not been included at this
time.

See the original README_LCALS_license.txt for copyright information

See the original README_LCALS_instructions.txt for information about
the suite.  

####################################################################
