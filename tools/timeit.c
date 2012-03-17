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

#include <errno.h>
#include <signal.h>
#include <unistd.h>

#include <sys/resource.h>
#include <sys/time.h>
#include <sys/wait.h>

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
                     "Killing monitored process(es): %s\n"),
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
  _exit(69);
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
    return 68;
  }

  /* Record the real elapsed time as soon as we can. */
  real_time = sample_wall_time() - start_time;

  /* Just in case there was another error in waitpid, kill the child process
   * group. */
  kill(-pid, SIGKILL);

  /* Collect the other resource data on the children. */
  if (getrusage(RUSAGE_CHILDREN, &usage) < 0) {
    perror("getrusage");
    return 125;
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

  return WEXITSTATUS(status);
}

void execute_target_process(char * const argv[]) {
  /* Create a new process group for pid, and the process tree it may spawn. We
   * do this, because later on we might want to kill pid _and_ all processes
   * spawned by it and its descendants.
   */
  setpgrp();

  execv(argv[0], argv);
  perror("execv");
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
    return 66;
  }

  /* If we are in the context of the child process, spawn it. */
  if (pid == 0) {
    /* Setup and execute the target process. This never returns except on
     * failure. */
    execute_target_process(argv);
    return 67;
  }

  /* Otherwise, we are in the context of the monitoring process. */
  return monitor_child_process(pid, start_time);
}

int main(int argc, char * const argv[]) {
  int i;

  for (i = 1; i != argc; ++i) {
    if (argv[i][0] != '-')
      break;

    switch (argv[i][1]) {
    case 'p':
      g_posix_mode = 1;
      continue;

    case 't':
      if (i + 1 == argc) {
        fprintf(stderr, "error: -t argument requires an option\n");
        return 1;
      }
      g_timeout_in_seconds = atoi(argv[++i]);
      continue;

    default:
      fprintf(stderr, "error: invalid argument '%s'\n", argv[i]);
      return 1;
    }
  }

  if (i == argc) {
    fprintf(stderr, "error: no command (or arguments) was given\n");
    return 1;
  }

  g_program_name = argv[0];
  g_target_program = argv[i];
  return execute(&argv[i]);
}
