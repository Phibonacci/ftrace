/*
** ftrace_parser.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sat Jun 28 19:27:28 2014 Jean Fauquenot
** Last update Sat Jun 28 20:08:27 2014 Jean Fauquenot
*/

#include "t_ftrace.h"
#include "merror.h"

#include <string.h>
#include <stdio.h>

t_state		ftrace_parser(t_ftrace *this, int argc, char **argv)
{
  int		pid;

  if (argc < 2)
    return (merror("%s", E_ARGC));
  if (argc >= 3 && strcmp(argv[1], "-p") == 0)
    {
      if ((sscanf(argv[2], "%d", &pid)) != 1
	  || pid < 0)
	return (merror("%s", E_ARGC));
      this->_isattached = true;
      this->_pid = pid;
    }
  else
    {
      this->_bin = argv[1];
      this->_opt = &argv[1];
    }
  return (SUCCESS);
}
