By default LLVM flang prints a stop message in certain circumstances that 
breaks some of the tests in this directory. As such we add the environment 
variable NO_STOP_MESSAGE=1 to disable this behaviour. If we wish to add tests
in future that need to check the stop message, those can be added in a 
subdirectory with a lit.local.cfg that unsets this environment variable.
