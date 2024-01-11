/*===-- timeit.c - LLVM Test Suite Timing Tool ------------------*- C++ -*-===*\
|*                                                                            *|
|* Part of the LLVM Project, under the Apache License v2.0 with LLVM          *|
|* Exceptions.                                                                *|
|* See https://llvm.org/LICENSE.txt for license information.                  *|
|* SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception                    *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <errno.h>
#include <signal.h>

#if _WIN32
#include <windows.h>
#else
#include <unistd.h>

#include <sys/resource.h>
#include <sys/time.h>
#include <sys/wait.h>
#endif

/* Enumeration for our exit status codes. */
enum ExitCode {
  /* \brief Indicates a failure monitoring the target. */
  EXITCODE_MONITORING_FAILURE = 66,

  /* \brief Indicates a failure in exec() which usually means an invalid program
   * name. */
  EXITCODE_EXEC_FAILURE = 67,
  EXITCODE_EXEC_NOENTRY = 127,
  EXITCODE_EXEC_NOPERMISSION = 126,

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
#ifndef _WIN32
static pid_t g_monitored_pid = 0;
#else
static DWORD g_monitored_pid = 0;
static HANDLE g_monitored_phandle = INVALID_HANDLE_VALUE;
#endif

/* \brief If non-zero, the path to attempt to chdir() to before executing the
 * target. */
static const char *g_target_exec_directory = 0;

/* \brief If non-zero, the path to write the summary information to (exit status
 * and timing). */
static const char *g_summary_file = 0;

/* \brief If non-zero, the path to redirect the target standard input to. */
static const char *g_target_redirect_input = 0;

/* \brief If non-zero, the path to redirect the target stdout to. */
static const char *g_target_redirect_stdout = 0;

/* \brief If non-zero, the path to redirect the target stderr to. */
static const char *g_target_redirect_stderr = 0;

/* \brief If non-zero, append exit status at end of output file. */
static int g_append_exitstats = 0;

#ifdef _WIN32
/* \brief If platform does not define rlim_t type, then define it as int. */
typedef int rlim_t;

#endif

/* @name Resource Limit Variables */
/* @{ */

/* \brief If non-sentinel, the CPU time limit to set for the target. */
static rlim_t g_target_cpu_limit = ~(rlim_t) 0;

/* \brief If non-sentinel, the stack size limit to set for the target. */
static rlim_t g_target_stack_size_limit = ~(rlim_t) 0;

/* \brief If non-sentinel, the data size limit to set for the target. */
static rlim_t g_target_data_size_limit = ~(rlim_t) 0;

/* \brief If non-sentinel, the RSS size limit to set for the target. */
static rlim_t g_target_rss_size_limit = ~(rlim_t) 0;

/* \brief If non-sentinel, the file size limit to set for the target. */
static rlim_t g_target_file_size_limit = ~(rlim_t) 0;

/* \brief If non-sentinel, the core limit to set for the target. */
static rlim_t g_target_core_limit = ~(rlim_t) 0;

/* \brief If non-sentinel, the file count limit to set for the target. */
static rlim_t g_target_file_count_limit = ~(rlim_t) 0;

/* \brief If non-sentinel, the subprocess count limit to set for the target. */
static rlim_t g_target_subprocess_count_limit = ~(rlim_t) 0;

/* @} */

static double sample_wall_time(void) {
#ifndef _WIN32
  struct timeval t;
  gettimeofday(&t, NULL);
  return (double)t.tv_sec + t.tv_usec * 1.e-6;
#else
  /* frequency init below is not thread-safe. Consider using a mutex if
   * sample_wall_time is required to be thread-safe in future. */
  static LARGE_INTEGER frequency = {0};
  if (frequency.QuadPart == 0)
    QueryPerformanceFrequency(&frequency);
  LARGE_INTEGER timeval;
  QueryPerformanceCounter(&timeval);
  return (double)timeval.QuadPart / frequency.QuadPart;
#endif
}

static int streq(const char *a, const char *b) { return strcmp(a, b) == 0; }

#ifndef _WIN32
static void terminate_handler(int signal) {
  /* If we are monitoring a process, kill its process group and assume we will
   * complete normally.
   */
  if (g_monitored_pid) {
    fprintf(stderr, ("%s: error: received signal %d. "
                     "killing monitored process(es): %s\n"),
            g_program_name, signal, g_target_program);

    /* Kill the process group of monitored_pid. */
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
  (void)signal;
  fprintf(stderr, "%s: TIMING OUT PROCESS: %s\n", g_program_name,
          g_target_program);
  /* We should always be monitoring a process when we receive an alarm. Kill its
   * process group and assume we will terminate normally.
   */
  kill(-g_monitored_pid, SIGKILL);
}

#define set_resource_limit(resource, value)                                    \
  set_resource_limit_actual(#resource, resource, value)
static void set_resource_limit_actual(const char *resource_name, int resource,
                                      rlim_t value) {
  /* Get the current limit. */
  struct rlimit current;
  getrlimit(resource, &current);

  /* Set the limits to as close as requested, assuming we are not super-user. */
  struct rlimit requested;
  requested.rlim_cur = requested.rlim_max =
      (value < current.rlim_max) ? value : current.rlim_max;
  if (setrlimit(resource, &requested) < 0) {
    fprintf(stderr, "%s: warning: unable to set limit for %s (to {%lu, %lu})\n",
            g_program_name, resource_name, (unsigned long)requested.rlim_cur,
            (unsigned long)requested.rlim_max);
  }
}
#else

/* Windows-specific implementation of fopen. */
static FILE *windows_fopen(const char *filename, const char *mode) {
  FILE *file;
  if (fopen_s(&file, filename, mode))
    return NULL;
  return file;
}
#define fopen(filename, mode) windows_fopen(filename, mode)

static HANDLE g_outfile_handle = INVALID_HANDLE_VALUE;
static HANDLE g_job_handle = INVALID_HANDLE_VALUE;

/* Exit status global variable. */
static int exit_status = 0;

/* Kill process group function. */
void kill_process_group(DWORD groupId) {
  GenerateConsoleCtrlEvent(CTRL_BREAK_EVENT, groupId);
}

/* Control handler function. */
BOOL WINAPI ctrl_handler(DWORD fdw_ctrl_type) {
  switch (fdw_ctrl_type) {
  case CTRL_C_EVENT:
  case CTRL_CLOSE_EVENT:
  case CTRL_BREAK_EVENT:
  case CTRL_LOGOFF_EVENT:
  case CTRL_SHUTDOWN_EVENT:
    exit_status = 1;
    kill_process_group(g_monitored_pid);
    return FALSE;
  default:
    return FALSE;
  }
}

/* Timer callback function. */
VOID CALLBACK timer_callback(PVOID lpParam, BOOLEAN TimerOrWaitFired) {
  exit_status = 2;
  kill_process_group(g_monitored_pid);
}

LPSTR create_process_commandline(char *const argv[]) {
  /* Convert argv to CreateProcess style commandline. */
  char *command_line = malloc(1);
  command_line[0] = '\0';
  int argc = 0;
  while (argv[argc] != NULL) {
    int size = strlen(command_line) + strlen(argv[argc]) + 2;
    command_line = realloc(command_line, size);
    strcat_s(command_line, size, argv[argc]);
    strcat_s(command_line, size, " ");
    argc++;
  }
  command_line[strlen(command_line) - 1] = '\0';
  return command_line;
}
#endif

static int monitor_child_process(double start_time) {
  double real_time, user_time, sys_time;
  int res, status;
#ifndef _WIN32
  struct rusage usage;

  /* If we are running with a timeout, set up an alarm now. */
  if (g_timeout_in_seconds) {
    sigset_t masked;
    sigemptyset(&masked);
    sigaddset(&masked, SIGALRM);

    alarm(g_timeout_in_seconds);
  }

  /* Wait for the process to terminate. */
  do {
    res = waitpid(g_monitored_pid, &status, 0);
  } while (res < 0 && errno == EINTR);
  if (res < 0) {
    perror("waitpid");
    return EXITCODE_MONITORING_FAILURE;
  }

  /* Record the real elapsed time as soon as we can. */
  real_time = sample_wall_time() - start_time;

  /* Just in case, kill the child process group. */
  kill(-g_monitored_pid, SIGKILL);

  /* Collect the other resource data on the children. */
  if (getrusage(RUSAGE_CHILDREN, &usage) < 0) {
    perror("getrusage");
    return EXITCODE_MONITORING_FAILURE;
  }
  user_time = (double) usage.ru_utime.tv_sec + usage.ru_utime.tv_usec/1000000.0;
  sys_time = (double) usage.ru_stime.tv_sec + usage.ru_stime.tv_usec/1000000.0;

  /* If the process was signalled, report a more interesting status. */
  int exit_status;
  if (WIFSIGNALED(status)) {
    fprintf(stderr, "%s: error: child terminated by signal %d\n",
            g_program_name, WTERMSIG(status));

    /* Propagate the signalled status to the caller. */
    exit_status = 128 + WTERMSIG(status);
  } else if (WIFEXITED(status)) {
    exit_status = WEXITSTATUS(status);
  } else {
    /* This should never happen, but if it does assume some kind of failure. */
    exit_status = EXITCODE_MONITORING_FAILURE;
  }

#else

  /* If we are running with a timeout, set up an alarm now. */
  HANDLE timer_handle = INVALID_HANDLE_VALUE;
  HANDLE timer_queue_handle = INVALID_HANDLE_VALUE;
  if (g_timeout_in_seconds) {
    /* Create a timer queue and then create a timer that fires after
     * g_timeout_in_seconds seconds. */
    timer_queue_handle = CreateTimerQueue();
    if (timer_queue_handle == NULL) {
      fprintf(stderr, "Failed to create timer queue!\n");
      return 1;
    }

    if (!CreateTimerQueueTimer(&timer_handle, timer_queue_handle,
                               timer_callback, NULL,
                               g_timeout_in_seconds * 1000, 0, 0)) {
      fprintf(stderr, "Failed to create timer!\n");
      return 1;
    }
  }

  /* Wait for the child process to finish, or the timer to fire. */
  WaitForSingleObject(g_monitored_phandle, INFINITE);

  /* Just in case, kill the child process group. */
  kill_process_group(g_monitored_pid);

  /* Record the real elapsed time as soon as we can. */
  real_time = sample_wall_time() - start_time;

  /* Check if process finished cleanly */
  DWORD exit_code;
  if (!GetExitCodeProcess(g_monitored_phandle, &exit_code)) {
    fprintf(stderr, "Failed to get exit code!\n");
  }

  /* If the process was signalled, report a more interesting status. */
  if (!exit_status) {
    if (exit_status == 1) {
      fprintf(stderr, "%s: error: child terminated by signal %d\n",
              g_program_name, exit_status);

      /* Propagate the signalled status to the caller. */
      exit_status = EXITCODE_CHILD_SIGNALLED;
    } else if (exit_status == 2) {
      fprintf(stderr, "%s: error: child terminated by signal %d\n",
              g_program_name, exit_status);
      exit_status = EXITCODE_CHILD_SIGNALLED;
    }
  }
  
  /* Set exit_status to 1 if process was not signalled, but it returned
   * non-zero exit code. */
  if(!exit_status && exit_code == 1)
    exit_status = 1;

  /* Clean up the timer and timer queue. */
  if (g_timeout_in_seconds) {
    if (timer_handle)
      DeleteTimerQueueTimer(timer_queue_handle, timer_handle, NULL);
    if (timer_queue_handle)
      DeleteTimerQueue(timer_queue_handle);
  }

  /* Query the job object information. */
  JOBOBJECT_BASIC_ACCOUNTING_INFORMATION accountingInfo;
  if (QueryInformationJobObject(
          g_job_handle, JobObjectBasicAccountingInformation, &accountingInfo,
          sizeof(JOBOBJECT_BASIC_ACCOUNTING_INFORMATION), NULL)) {
    user_time = (double)accountingInfo.TotalUserTime.QuadPart / 10000.0;
    sys_time = (double)accountingInfo.TotalKernelTime.QuadPart / 10000.0;
  } else {
    fprintf(stderr, "Failed to query job object information! Error code: %u\n",
            GetLastError());
    exit_status = EXITCODE_MONITORING_FAILURE;
    return exit_status;
  }

#endif

  /* If we are not using a summary file, report the information as 
   * /usr/bin/time would. */
  if (!g_summary_file) {
    if (g_posix_mode) {
      fprintf(stderr, "real %12.4f\nuser %12.4f\nsys  %12.4f\n",
              real_time, user_time, sys_time);
    } else {
      fprintf(stderr, "%12.4f real %12.4f user %12.4f sys\n",
              real_time, user_time, sys_time);
    }
  } else {
    /* Otherwise, write the summary data in a simple parsable format. */
    FILE *fp = fopen(g_summary_file, "w");
    if (!fp) {
      perror("fopen");
      return EXITCODE_MONITORING_FAILURE;
    }

    fprintf(fp, "exit %d\n", exit_status);
    fprintf(fp, "%-10s %.4f\n", "real", real_time);
    fprintf(fp, "%-10s %.4f\n", "user", user_time);
    fprintf(fp, "%-10s %.4f\n", "sys", sys_time);
    fclose(fp);
  }
#ifdef _WIN32
  if (g_outfile_handle != INVALID_HANDLE_VALUE)
    CloseHandle(g_outfile_handle);
#endif
  if (g_append_exitstats && g_target_program) {
    FILE *fp_stdout = fopen(g_target_redirect_stdout, "a");
    if (!fp_stdout) {
      perror("fopen");
      return EXITCODE_MONITORING_FAILURE;
    }
    fprintf(fp_stdout, "exit %d\n", exit_status);
    fclose(fp_stdout);
    /* let timeit itself report success */
    exit_status = 0;
  }

  return exit_status;
}

static int execute_target_process(char *const argv[]) {
#if _WIN32
  SECURITY_ATTRIBUTES sec_attr;
  sec_attr.nLength = sizeof(SECURITY_ATTRIBUTES);
  sec_attr.bInheritHandle = TRUE;
  sec_attr.lpSecurityDescriptor = NULL;

  STARTUPINFO sec_info;
  memset(&sec_info, 0, sizeof(STARTUPINFO));
  sec_info.cb = sizeof(STARTUPINFO);
  sec_info.dwFlags |= STARTF_USESTDHANDLES;
  sec_info.hStdInput = GetStdHandle(STD_INPUT_HANDLE);
  sec_info.hStdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
  sec_info.hStdError = GetStdHandle(STD_ERROR_HANDLE);

  /* Set up the input file handle for the child process. */
  if (g_target_redirect_input) {
    HANDLE input_file_handle =
        CreateFile(g_target_redirect_input, GENERIC_READ, 0, &sec_attr,
                   OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (input_file_handle == INVALID_HANDLE_VALUE) {
      perror("CreateFile failed for redirected input");
      return EXITCODE_MONITORING_FAILURE;
    }
    sec_info.hStdInput = input_file_handle;
  }

  /* Set up the output file handle for the child process. */
  if (g_target_redirect_stdout) {
    HANDLE output_file_handle =
        CreateFile(g_target_redirect_stdout, GENERIC_WRITE, 0, &sec_attr,
                   CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (output_file_handle == INVALID_HANDLE_VALUE) {
      perror("CreateFile failed for redirected output");
      return EXITCODE_MONITORING_FAILURE;
    }
    sec_info.hStdOutput = output_file_handle;
    g_outfile_handle = output_file_handle;
  }

  /* Set up the error file handle for the child process. */
  if (g_target_redirect_stderr) {
    if (!streq(g_target_redirect_stdout, g_target_redirect_stderr)) {

      HANDLE error_file_handle =
          CreateFile(g_target_redirect_stderr, GENERIC_WRITE, 0, &sec_attr,
                     CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
      if (error_file_handle == INVALID_HANDLE_VALUE) {
        perror("CreateFile failed for redirected error");
        return EXITCODE_MONITORING_FAILURE;
      }
      sec_info.hStdError = error_file_handle;
    } else
      sec_info.hStdError = sec_info.hStdOutput;
  }

  /* Create a job object to manage the child process resources. */
  g_job_handle = CreateJobObject(NULL, NULL);
  if (g_job_handle == NULL) {
    printf("Failed to create the Job Object. Error code: %lu\n",
           GetLastError());
    return 1;
  }

  /* Configure the job object to set a CPU time limit. */
  if (g_target_cpu_limit != ~(rlim_t)0) {
    JOBOBJECT_BASIC_LIMIT_INFORMATION basicInfo;
    ZeroMemory(&basicInfo, sizeof(JOBOBJECT_BASIC_LIMIT_INFORMATION));
    basicInfo.LimitFlags = JOB_OBJECT_LIMIT_JOB_TIME;

    /* Convert the seconds to 100-nanosecond intervals. */
    basicInfo.PerJobUserTimeLimit.QuadPart = g_target_cpu_limit * 10000000;

    if (!SetInformationJobObject(g_job_handle, JobObjectBasicLimitInformation,
                                 &basicInfo,
                                 sizeof(JOBOBJECT_BASIC_LIMIT_INFORMATION))) {
      fprintf(stderr,
              "Failed to set basic limit information for the job object! Error "
              "code: %u\n",
              GetLastError());
      CloseHandle(g_job_handle);
      return EXITCODE_EXEC_FAILURE;
    }
  }

  /* Configure the job object to set a active process limit. */
  if (g_target_subprocess_count_limit != ~(rlim_t)0) {
    JOBOBJECT_EXTENDED_LIMIT_INFORMATION ext_limit_info;
    ZeroMemory(&ext_limit_info, sizeof(JOBOBJECT_EXTENDED_LIMIT_INFORMATION));
    ext_limit_info.BasicLimitInformation.LimitFlags =
        JOB_OBJECT_LIMIT_ACTIVE_PROCESS;
    ext_limit_info.BasicLimitInformation.ActiveProcessLimit =
        g_target_subprocess_count_limit;

    if (!SetInformationJobObject(
            g_job_handle, JobObjectExtendedLimitInformation, &ext_limit_info,
            sizeof(JOBOBJECT_EXTENDED_LIMIT_INFORMATION))) {
      fprintf(stderr,
              "Failed to set the Job Object information. Error code: %lu\n",
              GetLastError());
      CloseHandle(g_job_handle);
      return EXITCODE_EXEC_FAILURE;
    }
  }

  if (g_target_stack_size_limit != ~(rlim_t)0) {
    fprintf(stderr, "Setting --limit-stack-size unsupported on Windows \n");
    return EXITCODE_EXEC_FAILURE;
  }
  if (g_target_data_size_limit != ~(rlim_t)0) {
    fprintf(stderr, "Setting --limit-data-size unsupported on Windows \n");
    return EXITCODE_EXEC_FAILURE;
  }
  if (g_target_rss_size_limit != ~(rlim_t)0) {
    fprintf(stderr, "Setting --limit-rss-size unsupported on Windows \n");
    return EXITCODE_EXEC_FAILURE;
  }
  if (g_target_file_size_limit != ~(rlim_t)0) {
    fprintf(stderr, "Setting --limit-file-size unsupported on Windows \n");
    return EXITCODE_EXEC_FAILURE;
  }
  if (g_target_core_limit != ~(rlim_t)0) {
    fprintf(stderr, "Setting --limit-core unsupported on Windows \n");
    return EXITCODE_EXEC_FAILURE;
  }
  if (g_target_file_count_limit != ~(rlim_t)0) {
    fprintf(stderr, "Setting --limit-file-count unsupported on Windows \n");
    return EXITCODE_EXEC_FAILURE;
  }

  /* Honor the desired target execute directory. */
  if (g_target_exec_directory) {
    if (SetCurrentDirectory(g_target_exec_directory) == 0) {
      perror("chdir");
      return EXITCODE_EXEC_FAILURE;
    }
  }

  /* Set up the control handler to terminate the child process. */
  if (!SetConsoleCtrlHandler(ctrl_handler, TRUE)) {
    perror("chdir");
    return EXITCODE_EXEC_FAILURE;
  }
  
  PROCESS_INFORMATION proc_info = {0};

  /* Create the child process. */
  if (!CreateProcess(NULL, create_process_commandline(argv), NULL, NULL, TRUE,
                     CREATE_NEW_PROCESS_GROUP, NULL, NULL, &sec_info,
                     &proc_info)) {
    fprintf(stderr, "Failed to create process. Error code: %lu\n",
            GetLastError());
    return EXITCODE_EXEC_FAILURE;
  }

  /* Assign the child process to the job object. */
  if (!AssignProcessToJobObject(g_job_handle, proc_info.hProcess)) {
    fprintf(
        stderr,
        "Failed to assign child process to the job object. Error code: %lu\n",
        GetLastError());
    TerminateProcess(proc_info.hProcess, 1);
    CloseHandle(proc_info.hProcess);
    CloseHandle(proc_info.hThread);
    return EXITCODE_EXEC_FAILURE;
  }

  /* Record the ID and HANDLE of the process we are monitoring. */
  g_monitored_pid = proc_info.dwProcessId;
  g_monitored_phandle = proc_info.hProcess;
#else

  /* Create a new process group for pid, and the process tree it may spawn. We
   * do this, because later on we might want to kill pid _and_ all processes
   * spawned by it and its descendants.
   */
  setpgid(0, 0);

  /* Redirect the standard input, if requested. */
  if (g_target_redirect_input) {
    FILE *fp = fopen(g_target_redirect_input, "r");
    if (!fp) {
      perror("fopen");
      return EXITCODE_MONITORING_FAILURE;
    }

    int fd = fileno(fp);
    if (dup2(fd, 0) < 0) {
      perror("dup2");
      return EXITCODE_MONITORING_FAILURE;
    }

    fclose(fp);
  }

  /* Redirect the standard output, if requested. */
  FILE *fp_stdout = NULL;
  if (g_target_redirect_stdout) {
    fp_stdout = fopen(g_target_redirect_stdout, "w");
    if (!fp_stdout) {
      perror("fopen");
      return EXITCODE_MONITORING_FAILURE;
    }

    int fd = fileno(fp_stdout);
    if (dup2(fd, STDOUT_FILENO) < 0) {
      perror("dup2");
      return EXITCODE_MONITORING_FAILURE;
    }
  }

  if (g_target_redirect_stderr) {
    FILE *fp_stderr = NULL;
    int fd;
    if (streq(g_target_redirect_stdout, g_target_redirect_stderr))
      fd = fileno(fp_stdout);
    else {
      fp_stderr = fopen(g_target_redirect_stderr, "w");
      if (!fp_stderr) {
        perror("fopen");
        return EXITCODE_MONITORING_FAILURE;
      }
      fd = fileno(fp_stderr);
    }

    if (dup2(fd, STDERR_FILENO) < 0) {
      perror("dup2");
      return EXITCODE_MONITORING_FAILURE;
    }
    if (fp_stderr != NULL)
      fclose(fp_stderr);
  }

  if (fp_stdout != NULL)
    fclose(fp_stdout);

  /* Honor any requested resource limits. */
  if (g_target_cpu_limit != ~(rlim_t) 0) {
    set_resource_limit(RLIMIT_CPU, g_target_cpu_limit);
  }
  if (g_target_stack_size_limit != ~(rlim_t) 0) {
    set_resource_limit(RLIMIT_STACK, g_target_stack_size_limit);
  }
  if (g_target_data_size_limit != ~(rlim_t) 0) {
    set_resource_limit(RLIMIT_DATA, g_target_data_size_limit);
  }
#if defined(RLIMIT_RSS) && !defined(__APPLE__)
  // On Apple platforms, RLIMIT_RSS is mapped to RLIMIT_AS and setting RLIMIT_AS
  // to a value smaller than the current virtual memory size will fail, This is
  // incompatible with the current usage in timeit and can cause issues on
  // platforms enforcing strict virtual memory size limits. Ignore RLIMIT_RSS on
  // Apple platforms for now.
  if (g_target_rss_size_limit != ~(rlim_t) 0) {
    set_resource_limit(RLIMIT_RSS, g_target_rss_size_limit);
  }
#endif
  if (g_target_file_size_limit != ~(rlim_t) 0) {
    set_resource_limit(RLIMIT_FSIZE, g_target_file_size_limit);
  }
  if (g_target_core_limit != ~(rlim_t) 0) {
    set_resource_limit(RLIMIT_CORE, g_target_core_limit);
  }
  if (g_target_file_count_limit != ~(rlim_t) 0) {
    set_resource_limit(RLIMIT_NOFILE, g_target_file_count_limit);
  }
#ifdef RLIMIT_NPROC
  if (g_target_subprocess_count_limit != ~(rlim_t) 0) {
    set_resource_limit(RLIMIT_NPROC, g_target_subprocess_count_limit);
  }
#endif

  /* Honor the desired target execute directory. */
  if (g_target_exec_directory) {
    if (chdir(g_target_exec_directory) < 0) {
      perror("chdir");
      return EXITCODE_MONITORING_FAILURE;
    }
  }

  execvp(argv[0], argv);
  perror("execv");

  if (errno == ENOENT) {
    return EXITCODE_EXEC_NOENTRY;
  } else if (errno == EACCES) {
    return EXITCODE_EXEC_NOPERMISSION;
  }

  return EXITCODE_EXEC_FAILURE;
#endif
}

static int execute(char * const argv[]) {
  double start_time;

#ifndef _WIN32
  /* Set up signal handlers so we can terminate the monitored process(es) on
   * SIGINT or SIGTERM. */
  signal(SIGINT, terminate_handler);
  signal(SIGTERM, terminate_handler);

  /* Set up a signal handler to terminate the process on timeout. */
  signal(SIGALRM, timeout_handler);
#endif

  start_time = sample_wall_time();

#ifndef _WIN32
  pid_t pid;
  
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

  /* Record the PID we are monitoring. */
  g_monitored_pid = pid;
#else

  /* If running on windows, do not return after creating process. */
  execute_target_process(argv);
#endif

  /* Otherwise, we are in the context of the monitoring process. */
  return monitor_child_process(start_time);
}

static void usage(int is_error) {
#define WRAPPED "\n                       "
  fprintf(stderr, "usage: %s [options] command ... arguments ...\n",
          g_program_name);
  fprintf(stderr, "Options:\n");
  fprintf(stderr, "  %-20s %s", "-h, --help",
          "Show this help text.\n");
  fprintf(stderr, "  %-20s %s", "-p, --posix",
          "Report time in /usr/bin/time POSIX format.\n");
  fprintf(stderr, "  %-20s %s", "-t, --timeout <N>",
          "Execute the subprocess with a timeout of N seconds.\n");
  fprintf(stderr, "  %-20s %s", "-c, --chdir <PATH>",
          "Execute the subprocess in the given working directory.\n");
  fprintf(stderr, "  %-20s %s", "--summary <PATH>",
          "Write monitored process summary (exit code and time) to PATH.\n");
  fprintf(stderr, "  %-20s %s", "--redirect-output <PATH>",
          WRAPPED "Redirect stdout and stderr for the target to PATH.\n");
  fprintf(stderr, "  %-20s %s", "--redirect-stdout <PATH>",
          WRAPPED "Redirect stdout for the target to PATH.\n");
  fprintf(stderr, "  %-20s %s", "--redirect-stderr <PATH>",
          WRAPPED "Redirect stderr for the target to PATH.\n");
  fprintf(stderr, "  %-20s %s", "--redirect-input <PATH>",
          WRAPPED "Redirect stdin for the target to PATH.\n");
  fprintf(stderr, "  %-20s %s", "--limit-cpu <N>",
          WRAPPED "Limit the target to N seconds of CPU time.\n");
  fprintf(stderr, "  %-20s %s", "--limit-stack-size <N>",
          WRAPPED "Limit the target to N bytes of stack space.\n");
  fprintf(stderr, "  %-20s %s", "--limit-data-size <N>",
          WRAPPED "Limit the target to N bytes of data.\n");
  fprintf(stderr, "  %-20s %s", "--limit-rss-size <N>",
          WRAPPED "Limit the target to N bytes of resident memory.\n");
  fprintf(stderr, "  %-20s %s", "--limit-file-size <N>",
          WRAPPED "Limit the target to creating files no more than N bytes.\n");
  fprintf(stderr, "  %-20s %s", "--limit-core <N>",
          WRAPPED "Limit the size for which core files will be generated.\n");
  fprintf(stderr, "  %-20s %s", "--limit-file-count <N>",
          (WRAPPED
           "Limit the maximum number of open files the target can have.\n"));
  fprintf(stderr, "  %-20s %s", "--limit-subprocess-count <N>",
          (WRAPPED
           "Limit the maximum number of simultaneous processes "
           "the target can use.\n"));
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

    if (streq(arg, "--summary")) {
      if (i + 1 == argc) {
        fprintf(stderr, "error: %s argument requires an option\n", arg);
        usage(/*is_error=*/1);
      }
      g_summary_file = argv[++i];
      continue;
    }

    if (streq(arg, "--redirect-input")) {
      if (i + 1 == argc) {
        fprintf(stderr, "error: %s argument requires an option\n", arg);
        usage(/*is_error=*/1);
      }
      g_target_redirect_input = argv[++i];
      continue;
    }

    if (streq(arg, "--redirect-output")) {
      if (i + 1 == argc) {
        fprintf(stderr, "error: %s argument requires an option\n", arg);
        usage(/*is_error=*/1);
      }
      g_target_redirect_stdout = argv[++i];
      g_target_redirect_stderr = g_target_redirect_stdout;
      continue;
    }

    if (streq(arg, "--redirect-stdout")) {
      if (i + 1 == argc) {
        fprintf(stderr, "error: %s argument requires an option\n", arg);
        usage(/*is_error=*/1);
      }
      g_target_redirect_stdout = argv[++i];
      continue;
    }

    if (streq(arg, "--redirect-stderr")) {
      if (i + 1 == argc) {
        fprintf(stderr, "error: %s argument requires an option\n", arg);
        usage(/*is_error=*/1);
      }
      g_target_redirect_stderr = argv[++i];
      continue;
    }

    if (streq(arg, "--append-exitstatus")) {
      g_append_exitstats = 1;
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

    if (strncmp(arg, "--limit-", 8) == 0) {
      rlim_t value;

      if (i + 1 == argc) {
        fprintf(stderr, "error: %s argument requires an option\n", arg);
        usage(/*is_error=*/1);
      }

      value = atoi(argv[++i]);
      if (streq(arg, "--limit-cpu")) {
        g_target_cpu_limit = value;
      } else if (streq(arg, "--limit-stack-size")) {
        g_target_stack_size_limit = value;
      } else if (streq(arg, "--limit-data-size")) {
        g_target_data_size_limit = value;
      } else if (streq(arg, "--limit-rss-size")) {
        g_target_rss_size_limit = value;
      } else if (streq(arg, "--limit-file-size")) {
        g_target_file_size_limit = value;
      } else if (streq(arg, "--limit-core")) {
        g_target_core_limit = value;
      } else if (streq(arg, "--limit-file-count")) {
        g_target_file_count_limit = value;
      } else if (streq(arg, "--limit-subprocess-count")) {
        g_target_subprocess_count_limit = value;
      } else {
        fprintf(stderr, "error: invalid limit argument '%s'\n", arg);
        usage(/*is_error=*/1);
      }
      continue;
    }

    fprintf(stderr, "error: invalid argument '%s'\n", arg);
    usage(/*is_error=*/1);
  }

  if (i == argc) {
    fprintf(stderr, "error: no command (or arguments) was given\n");
    usage(/*is_error=*/1);
  }

  g_target_program = argv[i];
  return execute(&argv[i]);
}
