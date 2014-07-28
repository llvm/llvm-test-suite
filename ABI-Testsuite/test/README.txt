To run native clang or gcc, do one of:
  python native-x86.py clang test <lit options>
  python native-x86.py gcc test <lit options>
  python native-x86.py 'clang -m32' test <lit options>
  python native-x86.py 'gcc -m32' test <lit options>

The first argument to native-x86 is the 'compiler name', which includes any arguments. It will figure out whether this is a 32 bit or 64 bit compiler and configure the testsuite accordingly.

In addition, if any tests are to be marked XFAIL, put they names, without suffixes, in the list skip_list in native-x86.py. These tests will be expected to fail. If these tests pass, it will be flagged as a test failure.


