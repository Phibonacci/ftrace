/*
** main.c for ftrace in /home/leduc_p/AUSP_ftrace/src
**
** Made by paul-maxime leduc
** Login   <leduc_p@epitech.net>
**
** Started on  Sun Jul  6 11:59:58 2014 paul-maxime leduc
** Last update Sun Jul  6 11:59:59 2014 paul-maxime leduc
*/

#include "t_ftrace.h"
#include "merror.h"

int		main(int argc, char **argv)
{
  t_ftrace	ftrace;

  if (ftrace_init(&ftrace, argc, argv) == FAILURE)
    return (FAILURE);
  if (ftrace.start(&ftrace) == FAILURE)
    return (FAILURE);
  ftrace_destroy(&ftrace);
  return (0);
}
