/*
** main.c for ftrace in /home/vareil_n/AUSP_ftrace
**
** Made by nicolas vareille
** Login   <vareil_n@epitech.net>
**
** Started on  Wed Jun 25 17:20:25 2014 nicolas vareille
** Last update Sun Jul  6 21:51:14 2014 nicolas vareille
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include "graph.h"
#include "t_ktree.h"
void			dump_graph(t_ktree *tree);

static int		open_dot_file(char *str)
{
  int			fd;

  fd = open(str, O_CREAT | O_WRONLY | O_TRUNC, 0644);
  return (fd);
}

int			start_graph(t_ktree *tree)
{
  t_graph		graph;

  if ((graph.fd = open_dot_file(TRACE_OUTPUT_FILE)) == -1)
    return (-1);
  gen_graph_start(&graph);
  define_functions(&graph, tree->root);
  trace_graph(&graph, tree->root);
  close_graph(&graph);
  return (0);
}
