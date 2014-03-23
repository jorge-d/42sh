/*
** write_status.c for Error Message  in /u/all/di-mar_j/cu/svn/42shsvn/trunk
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu May 13 19:43:54 2010 julien di-marco
** Last update Thu May 20 19:55:49 2010 julien di-marco
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	<signal.h>
#include	<stdio.h>
#include	"42sh.h"

t_signal	l_signal[] = {
  {SIGHUP, "Hangup :)\n"},
  {SIGINT, "\b\b\bInterrupt :)\n"},
  {SIGQUIT, "Quit :)\n"},
  {SIGILL, "Illegal instruction :)\n"},
  {SIGTRAP, "Trace/BPT trap :)\n"},
  {SIGABRT, "Abprt trap :)\n"},
  {SIGFPE, "Floating point exception :)\n"},
  {SIGKILL, "Killed :(\n"},
  {SIGBUS, "Bus error :)\n"},
  {SIGSEGV, "Segmentation fault :)\n"},
  {SIGSYS, "Bad system call :)\n"},
  {SIGPIPE, "Broken pipe :o\n"},
  {SIGALRM, "Alarm clock :)\n"},
  {SIGTERM, "Terminated :)\n"},
  {SIGURG, "Urgent I/O condition :)\n"},
  {SIGSTOP, "Suspended (signal) :)\n"},
  {SIGTSTP, "Suspended :)\n"},
  {SIGCONT, "Continued :)\n"},
  {SIGCHLD, "Child exited :)\n"},
  {SIGTTIN, "Stopped (tty output) :)\n"},
  {SIGIO, "I/O possible :)\n"},
  {SIGXCPU, "Cputime limit exceeded :)\n"},
  {SIGXFSZ, "Filesize limit exceeded :)\n"},
  {SIGVTALRM, "Virtual timer expired :)\n"},
  {SIGPROF, "Profiling timer expired :)\n"},
  {SIGWINCH, "Window size changes :)\n"},
  {SIGUSR1, "User defined signal 1 :)\n"},
  {SIGUSR2, "User defined signal 2 :)\n"},
#if		_FreeBSD_
  {SIGEMT, "EMT trap :)\n"},
  {SIGINFO, "Information request :)\n"},
  {SIGTHR, "Thread interrupt :)\n"},
#elif		_SunOS_
  {SIGPWR, "Power-Fail/Restart :)\n"},
  {SIGPOLL, "Pollable Event :)\n"},
  {SIGWAITING, "No runnable lwp :)\n"},
  {SIGFREEZE, "Checkpoint Freeze :)\n"},
  {SIGTHAW, "Checkpoint Thaw :)\n"},
  {SIGCANCEL, "Thread Cancellation :)\n"},
  {SIGLOST, "Resource Lost :)\n"},
#endif		/* _SunOs_ & _FreeBSD_ */
  {0, 0}
};

int		write_statut(int status)
{
  int		i;

  i = 0;
  if (status == 0)
    return (EXIT_SUCCESS);
  while (l_signal[i].number)
    {
      if (status == l_signal[i].number)
	  fprintf(stderr, "%s", l_signal[i].msg);
      i++;
    }
  return (EXIT_FAILURE);
}
