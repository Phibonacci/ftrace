/*
** dump_graph.c for  in /home/hengrui/project/SystemUnix/AUSP_ftrace
**
** Made by hengrui
** Login   <hengrui@epitech.net>
**
** Started on  Sun Jul  6 19:56:15 2014 hengrui
** Last update Sun Jul  6 19:56:23 2014 hengrui
*/

#include "graph.h"

static void		dump_func(t_ktree_elem *data)
{
  t_list_iterator	it;
  t_tracing		*trace;

  it = data->next._front;
  trace = data->data;
  printf("Func %s: ", trace->name);
  while (it)
    {
      trace = it->data;
      printf("\t%s", trace->name);
      it = it->next;
    }
  printf("\n");
}

void			dump_graph(t_ktree *tree)
{
  t_list_iterator	it;

  it = tree->elems._front;
  while (it)
    {
      dump_func((t_ktree_elem*)it->data);
      it = it->next;
    }
}
