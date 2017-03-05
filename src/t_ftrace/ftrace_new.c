/*
** ftrace_new.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sat Jun 28 17:53:04 2014 Jean Fauquenot
** Last update Sat Jun 28 18:37:10 2014 Jean Fauquenot
*/

#include "t_ftrace.h"

#include <stdlib.h>

t_ftrace	*ftrace_new(int argc, char **argv)
{
  t_ftrace	*new;

  if ((new = malloc(sizeof(*new))) == NULL
      || ftrace_init(new, argc, argv) == FAILURE)
    return (NULL);
  return (new);
}
