/*
** ftrace_attach.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sun Jun 29 21:34:38 2014 Jean Fauquenot
** Last update Sun Jul  6 20:18:14 2014 Jean Fauquenot
*/

#include "t_ftrace.h"
#include "merror.h"

#include <stdio.h>
#include <sys/ptrace.h>

t_state	ftrace_attach(t_ftrace *this)
{
  if (ptrace(PTRACE_ATTACH, this->_pid, NULL, NULL) == -1)
    {
      merror("%s: %d", E_PTRACE_ATTACH, this->_pid);
      return (FAILURE);
    }
  this->_isattached = 1;
  fprintf(stderr, "Process %d attached\n", this->_pid);
  if (this->_trace(this) == FAILURE)
    {
      if (ptrace(PTRACE_DETACH, this->_pid, NULL, NULL) == -1)
	merror("%s: %d", E_PTRACE_DETACH, this->_pid);
      return (FAILURE);
    }
  if (ptrace(PTRACE_DETACH, this->_pid, NULL, NULL) == -1)
    {
      merror("%s: %d", E_PTRACE_DETACH, this->_pid);
      return (FAILURE);
    }
  fprintf(stderr, "Process %d detached\n", this->_pid);
  return (SUCCESS);
}
