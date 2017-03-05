/*
** ftrace_break.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sun Jun 29 15:57:14 2014 Jean Fauquenot
** Last update Sun Jul  6 16:40:54 2014 Jean Fauquenot
*/

#include "t_ftrace.h"
#include "merror.h"

#include <stdio.h>
#include <string.h>
#include <sys/uio.h>
#include <sys/ptrace.h>

static t_state	check_registers(t_ftrace *this, t_regs *regs)
{
  if (this->_call_finder.step(&this->_call_finder,
			      regs, this->_pid) == FAILURE)
    return (FAILURE);
  if (this->_call_finder.is_syscall)
    {
      this->_syscall_id = this->_call_finder.syscall_id;
      if (this->_syscall(this, this->_call_finder.call_parent) == FAILURE)
	return (FAILURE);
    }
  if (this->_call_finder.is_call)
    {
      if (this->_call(this,
		      this->_call_finder.call_parent,
		      this->_call_finder.call_address) == FAILURE)
	return (FAILURE);
    }
  return (SUCCESS);
}

static t_state	get_registers(t_ftrace *this, t_regs *regs)
{
  struct iovec	storage;

  storage.iov_base = regs;
  storage.iov_len = sizeof(t_regs);
  if (ptrace(PTRACE_GETREGSET, this->_pid, 1, &storage) == -1)
    {
      merror("%s", E_PTRACE_GETREGS);
      return (FAILURE);
    }
  if ((this->_is32bits = (storage.iov_len < 100 ? 1 : 0)))
    {
      if (ptrace(PTRACE_GETREGS, this->_pid, 0, regs) == -1)
	{
	  merror("%s", E_PTRACE_GETREGS);
	  return (FAILURE);
	}
    }
  return (SUCCESS);
}

t_state		ftrace_break(t_ftrace *this, int signal)
{
  t_regs	regs;

  if (signal != 0)
    this->_break_signal(this, signal);
  if (get_registers(this, &regs) == FAILURE)
    return (FAILURE);
  if (check_registers(this, &regs))
    return (FAILURE);
  if (ptrace(PTRACE_SINGLESTEP, this->_pid, NULL, signal))
    {
      merror("%s", E_PTRACE_SINGLESTEP);
      return (FAILURE);
    }
  return (SUCCESS);
}
