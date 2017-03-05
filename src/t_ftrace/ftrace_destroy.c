/*
** ftrace_destroy.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sat Jun 28 18:00:27 2014 Jean Fauquenot
** Last update Fri Jul  4 23:45:58 2014 paul-maxime leduc
*/

#include "t_ftrace.h"

void	ftrace_destroy(t_ftrace *this)
{
  call_finder_destroy(&this->_call_finder);
}
