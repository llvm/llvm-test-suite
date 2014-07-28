# This file is distributed under the University of Illinois Open Source License.
# See LICENSE.TXT for details.
import os
import sys
wopt = " -w"
test_params = {
    "bindump" : "nm",
    "runtool" : "", # if None, then runtool_func must exists
    "Platform" : "linux-gcc",
    "cxx_rtti" : "-frtti",   # option to enable rtti
    "cxx_exceptions" : "-fexceptions",   # option to enable rtti
    "cxx_cpp11" : "-std=c++0x" ,
}

def build_cxx_compiler_name(cn):
  # build c++ compiler name from C compiler name
  # <prefix>clang <options> : becomes <prefix>clang -x c++ <options>
  # <prefix>gcc <options> : becomes <prefix>g++ <options>
  # <prefix>gcc-<vers> <options>: becomes <prefix>g++-<vers> <options>

  cnlen = len(cn)
  if (cn == 'clang'): #plain clang
    return "clang -x c++"

  idx = cn.find("clang ")
  if (idx >= 0): # clang with some options
    return cn[:(idx+6)] + "-x c++ " + cn[(idx+6):]

  idx = cn.rfind('clang')
  if (idx == (cnlen-5)): # ends in gcc
    return cn + " -x c++"

  if (cn == 'gcc'):
    return "g++"

  idx = cn.rfind('gcc')
  if (idx == (cnlen-3)): # ends in gcc
    return cn + " -x c++"

  idx = cn.find("gcc ")
  if (idx >= 0): # gcc with some options
    return cn[:(idx+1)] + "++ " + cn[(idx+4):]

  idx = cn.find("gcc-")
  if (idx >= 0): # gcc-<version>
    return cn[:(idx+1)] + "++" + cn[(idx+3):]

  return "UNEXPECTED COMPILER"

def build_linker_name(cn):
  # build linkercompiler name from C compiler name
  # <prefix>clang <options> : becomes <prefix>clang++ <options>
  # <prefix>gcc <options> : becomes <prefix>g++ <options>
  # <prefix>gcc-<vers> <options>: becomes <prefix>g++-<vers> <options>

  if (cn == 'clang'): #plain clang
    return "clang++"

  idx = cn.find("clang ")
  if (idx >= 0): # clang with some options
    return cn[:(idx+5)] + "++ " + cn[(idx+6):]

  cnlen = len(cn)
  idx = cn.rfind('clang')
  if (idx == (cnlen-5)): # ends in clang
    return cn + "++"

  return build_cxx_compiler_name(cn) # for gcc, linekr name is same as c++ compiler name


import subprocess
if __name__ == "__main__":
  print sys.argv
  litargs = [sys.argv[0]] # args for lit.main
  c_compiler_name = sys.argv[1].strip()
  cxx_compiler_name = build_cxx_compiler_name(c_compiler_name)
  linker_name = build_linker_name(c_compiler_name)
  #print "C++ compiler:", cxx_compiler_name
  #print "linker :", linker_name
  for la in sys.argv[2:]:
    litargs.append(la)
  sys.argv = litargs
  cmd = c_compiler_name.split() + [ "-o", "b.exe", "test/common/genselector.c"]
  #print "cmd = ", cmd
  rv = subprocess.call(cmd)
  #print "rv = " , rv
  if rv != 0:
    print "compiler failed: ", cmd
    sys.exit(1)
  rv = subprocess.call("./b.exe")
  fp = open("nselector.h")
  fi = fp.read();
  fp.close()
  if ("LP64" in fi):
    test_params["Mode"] = "LP64-x86"
    prf = "--check-prefix=LP64"
  else:
    # 'gcc -m32' or 'clang -m32' mode
    test_params["Mode"] = "ILP32-x86"
    prf = "--check-prefix=ILP32"
  test_params["prefixes"] = prf;
  test_params["c_compiler"] = c_compiler_name
  test_params["cxx_compiler"] = cxx_compiler_name
  test_params["linker"] = linker_name
  test_params["Platform"] = "linux-" + cmd[0]

  print "test_params = " , test_params
  builtin_parameters = {
    'build_mode' : "Release",
    'llvm_site_config' : os.path.join(os.getcwd(), 'lit.site.cfg'),
    'clang_site_config': os.path.join(os.getcwd(), 'lit.site.cfg'),
    'test_params' : test_params
    }
  #print "builtin_params = " , test_params
  import lit
  lit.main(builtin_parameters)

