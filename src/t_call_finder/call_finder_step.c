/*
** call_finder_step.c for ftrace in /home/leduc_p/SysUnix/AUSP_ftrace
**
** Made by paul-maxime leduc
** Login   <leduc_p@epitech.net>
**
** Started on  Fri Jul  4 23:48:36 2014 paul-maxime leduc
** Last update Sun Jul  6 20:50:00 2014 Jean Fauquenot
*/

#include <string.h>
#include <sys/ptrace.h>
#include "t_call_finder.h"

static void		check_syscall(t_call_finder *this,
				      t_regs *regs,
				      unsigned long word)
{
  t_called_function	*call_fct;

  if ((word & 0xffff) == ASM_SYSCALL ||
      (word & 0xffff) == ASM_SYSENTER ||
      (word & 0xffff) == ASM_INT80)
    {
      this->is_syscall = true;
      this->syscall_id = regs->rax;
      if (!this->_backtrace.empty(&this->_backtrace))
	{
	  call_fct = (t_called_function *)this->
	    _backtrace.top(&this->_backtrace);
	  this->call_parent = call_fct->base_address;
	}
    }
}

static void		check_stack_top(t_call_finder *this, t_addr loc)
{
  t_called_function	*fct;

  if (!this->_backtrace.empty(&this->_backtrace))
    {
      fct = (t_called_function *)this->_backtrace.top(&this->_backtrace);
      if (loc == fct->return_address)
	this->_backtrace.pop(&this->_backtrace);
    }
}

static void	check_call(t_call_finder *this, unsigned long word)
{
  int		mod_rm;

  if ((word & 0xFF) == ASM_CALL || (word & 0xFF) == ASM_ABSCALL)
    this->_incall = 1;
  if ((word & 0xFF) == 0xFF)
    {
      mod_rm = (word >> 8) & 0xFF;
      mod_rm = (mod_rm >> 3) & 0x7;
      if (mod_rm == 2 || mod_rm == 3)
	this->_incall = 1;
    }
}

static t_state		after_call(t_call_finder *this,
				   t_regs *regs,
				   pid_t pid)
{
  t_called_function	*call_fct;

  if (!this->_backtrace.empty(&this->_backtrace))
    {
      call_fct = (t_called_function *)this->_backtrace.top(&this->_backtrace);
      this->is_call = true;
      this->call_parent = call_fct->base_address;
      this->call_address = regs->rip;
    }
  call_fct = malloc(sizeof(t_called_function));
  if (!call_fct)
    return (FAILURE);
  call_fct->base_address = regs->rip;
  call_fct->return_address = ptrace(PTRACE_PEEKTEXT, pid, regs->rsp, NULL);
  this->_backtrace.push(&this->_backtrace, call_fct);
  return (SUCCESS);
}

t_state		call_finder_step(t_call_finder *this,
				 t_regs *regs,
				 pid_t pid)
{
  unsigned long	word;

  this->is_call = false;
  this->is_syscall = false;
  word = ptrace(PTRACE_PEEKTEXT, pid, regs->rip, NULL);
  check_stack_top(this, regs->rip);
  if (this->_incall)
    {
      this->_incall = false;
      if (after_call(this, regs, pid) == FAILURE)
	return (FAILURE);
    }
  check_call(this, word);
  check_syscall(this, regs, word);
  return (SUCCESS);
}
