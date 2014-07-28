This directory contains the IA64-ABI testsuite.

To run the testsuite on linux

1) Make sure you have 'lit' in PYTHONOPATH, and FileCheck in PATH.
2) Do 
      python linux-x86.py <compiler+args> test [any lit arguments]

   <compiler+args> is the compiler to be tested, with any args as one argument; such as

      python linux-x86.py clang test                    # clang must be in PATH
      python linux-x86.py /home/me/bin/my-clang test    # my own compiler, not in PATH
      python linux-x86.py 'clang -m32' test             # test 32 bit mode
      python linux-x86.py 'clang -O' test               # test with optimization on
      python linux-x86.py 'gcc' test -v                 # test gcc, with -v passed to lit
      python linux-x86.py clang test/basic              # test only 'basic' directory 
      
linux-x86.py runs a small executable to first figure out whether this is 32 bit or 64 bit 
platform, and then chooses one of the two configurations for testing.

Other, non-linux platforms will require edits to the python script to specify compilers,
linker, runner (if any). We will provide a sample file that can be modified to other 
'similar' platforms, however it should be noted that the testsuite, as released, supports
only x86-linux-like platforms (both ILP32 and LP64).

Tests are arranged in multiple diretories, starting from 'test'. The pyhthon script can be 
given any subdirectory. The directory 'test/common' contains utility files used by the
testsuite.

The overview of files is as follows:

README.text                         # This README
linux-x86.py                        # top level python script

test/basic/basic.x                  # A small directory to test that the basic configuration
test/basic/T_st.x                   # is correct. If this fails, everything else will too.

test/common/genselector.c           # Directory containing utilities used by the testsuite
test/common/select2.h
test/common/testsuite.c
test/common/testsuite.h             

test/lit.site.cfg                   # top config file called from lit

test/mangling/arrays.xpp            # Mangling test. Using FileCheck
test/mangling/c++11.xpp
test/mangling/c++11s.xpp
....

test/misc/s2_8a.xpp                 # miscellaneous test directory
test/misc/s2_8b.x
test/misc/s2_9_5.x
test/misc/s3_1.xpp
...

test/s2_4/T_novirt_1.x              # test targetted to particular section of the spec
...

test/s2_5/T_vf1.x
test/s2_5/T_vf2.x
...

test/s2_6/T_isc.x
test/s2_6/T_ksc0.x
test/s2_6/T_ksc1.x
...

test/struct_layout_tests/CT_bf.x    #  tests for plain struct layout
test/struct_layout_tests/CT_Snen_xaa.x
test/struct_layout_tests/CT_Snen_xab.x
...

test/struct_layout_tests/PACKED/CT_Snen_xaa.x   # test for packed structs
test/struct_layout_tests/PACKED/CT_Snen_xab.x
...

------------------------------------------------------------------

Some points to note:

a) This release consists of about 290 files. We plan to release more tests a little later.
b) As one can see, test files are named with suffixes '.x' and '.xpp'. This is intentional.
   There is a mechanism, in lit.site.cfg, which copies them to correspondig '.c' or '.cpp' 
   files, looking into a 'skip_list' specified at the top level python file. This mechanism
   is meant to allow users to mark certain tests 'XFAIL' (expected to fail), on per-file,
   per-test-script basis. 
c) Test files are all self-contained and independent. They can be removed or moved around to 
   different directories.
d) Most files are named T_*.x or CT_*.x and are 'combined' files having both C and C++ code,
   separated by '#ifdef __cplusplus'. The '//RUN' header at the top of these files runs both the
   C and C++ compilers on them and links the resulting object files to make the excutable test.

------------------------------------------------------------------
There are several ways to handle situations where some tests are failing for some understood 
reasons.

1) There is a mechanism of skip_list to mark certain tests XFAIL by adding them to the skip_list,
   as shown in sample.py
2) The results of test executablles can be saved as a 'golden master' to compare against future 
   runs.
3) Finally, 'test_params['checker'] can be changed from plain 'grep' to any user written program
   that can match the test results to such a 'golden master'.

   


