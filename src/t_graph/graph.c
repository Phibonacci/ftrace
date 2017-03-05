/*
** graph.c for ftrace in /home/vareil_n/projects/systeme_unix_avance/AUSP_ftrace/graph
**
** Made by nicolas vareille
** Login   <vareil_n@epitech.net>
**
** Started on  Wed Jul  2 14:37:43 2014 nicolas vareille
** Last update Sun Jul  6 21:55:08 2014 nicolas vareille
*/

#include <stdlib.h>
#include "graph.h"
#include "t_mangling.h"

static void		def_name(t_graph *g, char *s, t_tracing *t)
{
  if (t->type == SYSCALL)
    define_func(g, s, t, !t->call_nbr ?
		SYSCALL_DEFINITION_UNIQUE : SYSCALL_DEFINITION);
  else if (t->type == FUNCALL)
    define_func(g, s, t, !t->call_nbr ?
		FUNCTION_DEFINITION_UNIQUE : FUNCTION_DEFINITION);
  else
    define_func(g, s, t, !t->call_nbr ?
		EXTERN_DEFINITION_UNIQUE : EXTERN_DEFINITION);
}

static void		def_noname(t_graph *g, t_tracing *t)
{
  char			buff[128];

  if (t->call_nbr)
    snprintf(buff, sizeof(buff), NONAME_DEFINITION,
	     t->address, t->libname, t->address, t->libname, t->call_nbr);
  else
    snprintf(buff, sizeof(buff), NONAME_DEFINITION_UNIQUE,
	     t->address, t->libname, t->address, t->libname);
  my_putgraph(g, buff);
}

void			define_functions(t_graph *g, t_ktree_elem *e)
{
  t_tracing		*t;
  t_list_iterator	it;
  char			*s;

  it = e->next.begin(&e->next);
  t = e->data;
  if (t->name)
    {
      s = unmangle(t->name);
      def_name(g, s, t);
      free(s);
    }
  else
    def_noname(g, t);
  while (it)
    {
      define_functions(g, it->data);
      it = it->next;
    }
}

static void		rec_graph(t_graph *g, t_ktree_elem *e,
				  t_ktree_elem *prev)
{
  t_tracing		*t[2];
  t_list_iterator	it;

  it = e->next.begin(&e->next);
  t[0] = e->data;
  t[1] = prev ? prev->data : 0;
  if (g->put)
    {
      draw_func(g, t[1], 1);
      draw_func(g, t[0], 0);
      my_putgraph(g, GRAPH_END_LINE);
    }
  ++g->put;
  while (it)
    {
      rec_graph(g, it->data, e);
      it = it->next;
    }
}

void			trace_graph(t_graph *graph, t_ktree_elem *tree)
{
  rec_graph(graph, tree, NULL);
}
