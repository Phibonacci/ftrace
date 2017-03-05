/*
** ftrace_trace.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sat Jun 28 20:33:14 2014 Jean Fauquenot
** Last update Wed Jul  2 17:01:04 2014 paul-maxime leduc
*/

#include "t_ftrace.h"
#include "merror.h"

#include <stdio.h>
#include <errno.h>
#include <sys/wait.h>

static t_state	ftrace_wait_callback(t_ftrace *this, int status)
{
  int		signum;

  if (WIFSTOPPED(status))
    {
      signum = WSTOPSIG(status);
      if (this->_break(this,
		       (signum == SIGTRAP ||
			signum == SIGSTOP ? 0 : signum)))
	return (FAILURE);
    }
  else
    {
      if (WIFEXITED(status))
	fprintf(stderr, "exited with %d\n", WEXITSTATUS(status));
      if (WIFSIGNALED(status))
	fprintf(stderr, "killed by %d%s\n", WTERMSIG(status),
		WCOREDUMP(status) ? " (core dumped)" : "");
      this->_isrunning = 0;
    }
  return (SUCCESS);
}

t_state		ftrace_trace(t_ftrace *this)
{
  int		status;

  this->_init_signal();
  this->_isrunning = 1;
  while (this->_isrunning)
    {
      if (waitpid(this->_pid, &status, 0) == -1 && errno != EINTR)
	return (FAILURE);
      if (this->_last_signal())
	{
	  if (!this->_isattached)
	    kill(this->_pid, SIGKILL);
	  return (SUCCESS);
	}
      if (ftrace_wait_callback(this, status))
	return (FAILURE);
    }
  return (SUCCESS);
}
