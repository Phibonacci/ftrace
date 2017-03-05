/*
** ftrace_delete.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sat Jun 28 18:01:21 2014 Jean Fauquenot
** Last update Sat Jun 28 18:09:35 2014 Jean Fauquenot
*/

#include "t_ftrace.h"

void		ftrace_delete(t_ftrace *this)
{
  ftrace_destroy(this);
  free(this);
}
