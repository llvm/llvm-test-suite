//===- test_not.cpp - Test for enviroment variables in the not tool -------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include <cstdlib>
#include <iostream>
#include <sstream>

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#endif

#if defined(__unix__) || defined(__APPLE__)
#include <spawn.h>
#include <sys/wait.h>
#endif

int main(int argc, char *const *argv) {
  ++argv;
  --argc;
  if (argc == 0)
    return EXIT_FAILURE;

#ifdef _WIN32
  SetEnvironmentVariableA("SET_IN_PARENT", "something");
#else
  setenv("SET_IN_PARENT", "something", 0);
#endif

  int result;

#if defined(__unix__) || defined(__APPLE__)
  pid_t pid;
  extern char **environ;
  if (posix_spawn(&pid, argv[0], NULL, NULL, argv, environ))
    return EXIT_FAILURE;
  if (waitpid(pid, &result, WUNTRACED | WCONTINUED) == -1)
    return EXIT_FAILURE;
#else
  std::stringstream ss;
  ss << argv[0];
  for (int i = 1; i < argc; ++i)
    ss << " " << argv[i];
  std::string cmd = ss.str();
  result = std::system(cmd.c_str());
#endif

  int retcode = 0;
  int signal = 0;

#ifdef _WIN32
  // Handle abort() in msvcrt -- It has exit code as 3.  abort(), aka
  // unreachable, should be recognized as a crash.  However, some binaries use
  // exit code 3 on non-crash failure paths, so only do this if we expect a
  // crash.
  if (errno) {
    // If the command interpreter was not found, errno will be set and 0 will
    // be returned. It is unlikely that this will happen in our use case, but
    // check anyway.
    retcode = 1;
    signal = 1;
  } else {
    // On Windows, result is the exit code, except for the special case above.
    retcode = result;
    signal = 0;
  }
#elif defined(WIFEXITED) && defined(WEXITSTATUS) && defined(WIFSIGNALED) &&    \
    defined(WTERMSIG)
  // On POSIX systems and Solaris, result is a composite value of the exit code
  // and, potentially, the signal that caused termination of the command.
  if (WIFEXITED(result))
    retcode = WEXITSTATUS(result);
  if (WIFSIGNALED(result))
    signal = WTERMSIG(result);
#else
#error "Unsupported system"
#endif

  if (!signal && retcode == EXIT_SUCCESS)
    return EXIT_SUCCESS;
  return EXIT_FAILURE;
}
