/*
** ftrace_start.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sat Jun 28 19:33:40 2014 Jean Fauquenot
** Last update Sun Jul  6 12:31:44 2014 nicolas vareille
*/

#include "t_ftrace.h"
#include "merror.h"
#include "graph.h"

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <string.h>

void		ftrace_child(char *process, char **argv)
{
  if (ptrace(PTRACE_TRACEME, 0, NULL, NULL) == -1)
    {
      merror("%s", E_PTRACE_TRACEME);
      exit(1);
    }
  if (kill(getpid(), SIGTRAP) == -1)
    {
      merror("%s", E_KILL);
      exit(1);
    }
  execvp(process, argv);
  merror("%s\n", E_EXECVP);
  exit(1);
}

t_state		ftrace_fork(t_ftrace *this)
{
  pid_t		pid;

  pid = fork();
  if (pid == -1)
    {
      return (merror("%s", E_FORK));
    }
  if (pid > 0)
    {
      this->_pid = pid;
      if (this->_trace(this) == FAILURE)
	return (FAILURE);
    }
  else
    this->_child(this->_bin, this->_opt);
  return (SUCCESS);
}

t_state		ftrace_start(t_ftrace *this)
{
  if (this->_isattached == true)
    {
      if (this->_attach(this) == FAILURE)
	return (FAILURE);
    }
  else
    {
      if (this->_fork(this) == FAILURE)
	return (FAILURE);
    }
  start_graph(&this->_tree);
  return (SUCCESS);
}
