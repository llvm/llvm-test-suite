# This file is distributed under the University of Illinois Open Source License.
# See LICENSE.TXT for details.

# This is a sample file meant to be modified for specific configurations

import os
import sys
wopt = ""   # set to " -w", or equivalent option, to disable warnings.

#skiplist = [ "test/s2_7/test_02", "test/s2_7/test_06"] # Enable to choose a 'skip list'

test_params =  {
    'bindump': 'nm',                 # name of the nm-like tool to print symbol names
    'cxx_rtti': '-frtti',            # option to enable rtti
    'runtool': '',                   # leave empty for native runs. 
                                     # Set to the name of the 'runner' tool for cross tools
    'linker': 'clang++ -w',          # name of the linker
    'cxx_compiler': 'clang -x c++'+wopt, # name of the C++ compiler
    'c_compiler': 'clang'+wopt,      # name of the C compiler
    'cxx_cpp11': '-std=c++0x',       # option to enable C++11 mode, if any 
    'prefixes': '--check-prefix=LP64', # must be LP64 or ILP32
    'Platform': 'linux-clang',       # just for documentation
    'Mode': 'LP64-x86',              # must be "LP64-x86" or "ILP32-x86"
    'cxx_exceptions': '-fexceptions' # options to enable exceptions
    # , skip_list: skiplist          # if skiplist is not empty
    }


import subprocess
if __name__ == "__main__":
  print "test_params = " , test_params
  builtin_parameters = {
    'build_mode' : "Release",
    'llvm_site_config' : os.path.join(os.getcwd(), 'lit.site.cfg'),
    'clang_site_config': os.path.join(os.getcwd(), 'lit.site.cfg'),
    'test_params' : test_params
    }
  import lit
  lit.main(builtin_parameters)

