/*
** ftrace_break_signal.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sun Jun 29 15:58:17 2014 Jean Fauquenot
** Last update Sun Jun 29 16:15:40 2014 Jean Fauquenot
*/

#include <stdio.h>
#include <signal.h>
#include <sys/ptrace.h>
#include "t_ftrace.h"

int		ftrace_break_signal(t_ftrace *this, int signal)
{
  siginfo_t	siginfo;

  if (ptrace(PTRACE_GETSIGINFO, this->_pid, 0, &siginfo) == -1)
    return (-1);
  fprintf(stderr, "--- %d {si_signo=%d, si_code=%d} ---\n", signal,
	  siginfo.si_signo, siginfo.si_code);
  return (0);
}
