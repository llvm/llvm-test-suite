/*===-- timeit.c - LLVM Test Suite Timing Tool ------------------*- C++ -*-===*\
|*                                                                            *|
|*                     The LLVM Compiler Infrastructure                       *|
|*                                                                            *|
|* This file is distributed under the University of Illinois Open Source      *|
|* License. See LICENSE.TXT for details.                                      *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <errno.h>
#include <signal.h>
#include <unistd.h>

#include <sys/resource.h>
#include <sys/time.h>
#include <sys/wait.h>

/* Enumeration for our exit status codes. */
enum ExitCode {
  /* \brief Indicates a failure monitoring the target. */
  EXITCODE_MONITORING_FAILURE = 66,

  /* \brief Indicates a failure in exec() which usually means an invalid program
   * name. */
  EXITCODE_EXEC_FAILURE = 67,

  /* \brief Indicates that we were unexpectedly signalled(). */
  EXITCODE_SIGNALLED = 68,

  /* \brief Indicates the child was signalled. */
  EXITCODE_CHILD_SIGNALLED = 69
};

/* \brief Record our own program name, for error messages. */
static const char *g_program_name = 0;

/* \brief Record the child command name, for error messages. */
static const char *g_target_program = 0;

/* \brief If given, report output in POSIX mode format. */
static int g_posix_mode = 0;

/* \brief If non-zero, execute the program with a timeout of the given number
 * of seconds.
 */
static int g_timeout_in_seconds = 0;

/* \brief If non-zero, the PID of the process being monitored. */
static pid_t g_monitored_pid = 0;

/* \brief If non-zero, the path to attempt to chdir() to before executing the
 * target. */
static const char *g_target_exec_directory = 0;

static double sample_wall_time(void) {
  struct timeval t;
  gettimeofday(&t, NULL);
  return (double) t.tv_sec + t.tv_usec * 1.e-6;
}

static void terminate_handler(int signal) {
  /* If we are monitoring a process, kill its process group and assume we will
   * complete normally.
   */
  if (g_monitored_pid) {
    fprintf(stderr, ("%s: error: received signal %d. "
                     "killing monitored process(es): %s\n"),
            g_program_name, signal, g_target_program);

    /* Kill the process group of monitored_pid.  Since we called
       setpgrp() for pid, this will not kill us, or any of our
       ancestors */
    kill(-g_monitored_pid, SIGKILL);
    return;
  }

  fprintf(stderr, "%s: error: received signal %d. exiting.\n",
          g_program_name, signal);
  /* Otherwise, we received a signal we should treat as for ourselves, and exit
   * quickly. */
  _exit(EXITCODE_SIGNALLED);
}

static void timeout_handler(int signal) {
  fprintf(stderr, "%s: TIMING OUT PROCESS: %s\n", g_program_name,
          g_target_program);
  /* We should always be monitoring a process when we receive an alarm. Kill its
   * process group and assume we will terminate normally.
   */
  kill(-g_monitored_pid, SIGKILL);
}

int monitor_child_process(pid_t pid, double start_time) {
  double real_time, user_time, sys_time;
  struct rusage usage;
  int res, status;

  /* Record the PID we are monitoring, for use in the signal handlers. */
  g_monitored_pid = pid;

  /* If we are running with a timeout, set up an alarm now. */
  if (g_timeout_in_seconds) {
    sigset_t masked;
    sigemptyset(&masked);
    sigaddset(&masked, SIGALRM);

    alarm(g_timeout_in_seconds);
  }

  /* Wait for the process to terminate. */
  do {
    res = waitpid(pid, &status, 0);
  } while (res < 0 && errno == EINTR);
  if (res < 0) {
    perror("waitpid");
    return EXITCODE_MONITORING_FAILURE;
  }

  /* Record the real elapsed time as soon as we can. */
  real_time = sample_wall_time() - start_time;

  /* Just in case, kill the child process group. */
  kill(-pid, SIGKILL);

  /* Collect the other resource data on the children. */
  if (getrusage(RUSAGE_CHILDREN, &usage) < 0) {
    perror("getrusage");
    return EXITCODE_MONITORING_FAILURE;
  }
  user_time = (double) usage.ru_utime.tv_sec + usage.ru_utime.tv_usec/1000000.0;
  sys_time = (double) usage.ru_stime.tv_sec + usage.ru_stime.tv_usec/1000000.0;

  if (g_posix_mode) {
    fprintf(stderr, "real %12.4f\nuser %12.4f\nsys  %12.4f\n",
            real_time, user_time, sys_time);
  } else {
    fprintf(stderr, "%12.4f real %12.4f user %12.4f sys\n",
            real_time, user_time, sys_time);
  }

  /* If the process was signalled, report a more interesting status. */
  if (WIFSIGNALED(status)) {
    fprintf(stderr, "%s: error: child terminated by signal %d\n",
            g_program_name, WTERMSIG(status));
    return EXITCODE_CHILD_SIGNALLED;
  }

  if (WIFEXITED(status)) {
    return WEXITSTATUS(status);
  }

  /* This should never happen, but if it does assume some kind of failure. */
  return EXITCODE_MONITORING_FAILURE;
}

static int execute_target_process(char * const argv[]) {
  /* Create a new process group for pid, and the process tree it may spawn. We
   * do this, because later on we might want to kill pid _and_ all processes
   * spawned by it and its descendants.
   */
  setpgrp();

  /* Honor the desired target execute directory. */
  if (g_target_exec_directory) {
    if (chdir(g_target_exec_directory) < 0) {
      perror("chdir");
      return EXITCODE_MONITORING_FAILURE;
    }
  }

  execvp(argv[0], argv);
  perror("execv");
  return EXITCODE_EXEC_FAILURE;
}

int execute(char * const argv[]) {
  double start_time;
  pid_t pid;

  /* Set up signal handlers so we can terminal the monitored process(es) on
   * SIGINT or SIGTERM. */
  signal(SIGINT, terminate_handler);
  signal(SIGTERM, terminate_handler);

  /* Set up a signal handler to terminate the process on timeout. */
  signal(SIGALRM, timeout_handler);

  start_time = sample_wall_time();

  /* Fork the child process. */
  pid = fork();
  if (pid < 0) {
    perror("fork");
    return EXITCODE_MONITORING_FAILURE;
  }

  /* If we are in the context of the child process, spawn it. */
  if (pid == 0) {
    /* Setup and execute the target process. This never returns except on
     * failure. */
    return execute_target_process(argv);
  }

  /* Otherwise, we are in the context of the monitoring process. */
  return monitor_child_process(pid, start_time);
}

static int streq(const char *a, const char *b) {
  return strcmp(a, b) == 0;
}

static void usage(int is_error) {
  fprintf(stderr, "usage: %s [options] command ... arguments ...\n",
          g_program_name);
  fprintf(stderr, "Options:\n");
  fprintf(stderr, "  %-20s %s", "{-h,--help}",
          "Show this help text.\n");
  fprintf(stderr, "  %-20s %s", "{-p,--posix}",
          "Report time in /usr/bin/time POSIX format.\n");
  fprintf(stderr, "  %-20s %s", "{-t,--timeout} <N>",
          "Execute the subprocess with a timeout of N seconds.\n");
  fprintf(stderr, "  %-20s %s", "{-c,--chdir} <PATH>",
          "Execute the subprocess in the given working directory.\n");
  _exit(is_error);
}

int main(int argc, char * const argv[]) {
  int i;

  g_program_name = argv[0];
  for (i = 1; i != argc; ++i) {
    const char *arg = argv[i];

    if (arg[0] != '-')
      break;

    if (streq(arg, "-h") || streq(arg, "--help")) {
      usage(/*is_error=*/0);
    }

    if (streq(arg, "-p") || streq(arg, "--posix")) {
      g_posix_mode = 1;
      continue;
    }

    if (streq(arg, "-t") || streq(arg, "--timeout")) {
      if (i + 1 == argc) {
        fprintf(stderr, "error: %s argument requires an option\n", arg);
        usage(/*is_error=*/1);
      }
      g_timeout_in_seconds = atoi(argv[++i]);
      continue;
    }

    if (streq(arg, "-c") || streq(arg, "--chdir")) {
      if (i + 1 == argc) {
        fprintf(stderr, "error: %s argument requires an option\n", arg);
        usage(/*is_error=*/1);
      }
      g_target_exec_directory = argv[++i];
      continue;
    }

    fprintf(stderr, "error: invalid argument '%s'\n", argv[i]);
    usage(/*is_error=*/1);
  }

  if (i == argc) {
    fprintf(stderr, "error: no command (or arguments) was given\n");
    usage(/*is_error=*/1);
  }

  g_target_program = argv[i];
  return execute(&argv[i]);
}
