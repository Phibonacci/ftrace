/*
** ftrace_getlib_name.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sun Jul  6 20:00:47 2014 Jean Fauquenot
** Last update Sun Jul  6 20:47:48 2014 Jean Fauquenot
*/

#include "t_ftrace.h"
#include "t_tracing.h"

#include <string.h>

char		*ftrace_getlib_name(t_ftrace *UNUSED(this), const char *path)
{
  char		*start;

  if ((start = strrchr(path, '/')) != NULL && start[0] == '/')
    return (strdup(start + 1));
  return (NULL);
}
