/*
** function_definer.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Wed Jul  2 17:51:15 2014 nicolas vareille
** Last update Sun Jul  6 21:54:00 2014 nicolas vareille
*/

#include <stdio.h>
#include <string.h>
#include "graph.h"
#include "t_mangling.h"

void		my_putgraph(t_graph *graph, char *str)
{
  write(graph->fd, str, strlen(str));
}

void		draw_func(t_graph *graph, t_tracing *t, int first)
{
  char		fct_name[128];
  char		buff[BUFF_SIZE];
  char		*s;

  if (t->name)
    {
      s = unmangle(t->name);
      snprintf(fct_name, sizeof(fct_name), "%s@%s", s,
	       t->libname ? t->libname : SYSCALL_LIB);
      free(s);
    }
  else
    snprintf(fct_name, sizeof(fct_name), "%llx@%s", t->address, t->libname);
  if (!first)
    my_putgraph(graph, FUNCTION_LINK);
  snprintf(buff, sizeof(buff), "\"%s\"", fct_name);
  my_putgraph(graph, buff);
}

void		gen_graph_start(t_graph *graph)
{
  graph->first = 0;
  graph->put = 0;
  my_putgraph(graph, GRAPH_START);
}

void		close_graph(t_graph *graph)
{
  my_putgraph(graph, GRAPH_CLOSING);
  close(graph->fd);
}

void		define_func(t_graph *graph, char const *str,
			    t_tracing *t, char *type)
{
  char		buff[BUFF_SIZE];
  int		id;
  char		*lib;

  id = t->call_nbr + 1;
  if (t->libname)
    lib = t->libname;
  else
    lib = SYSCALL_LIB;
  snprintf(buff, sizeof(buff), type, str, lib, str, lib, id);
  my_putgraph(graph, buff);
}
