/*
** graph.h for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sun Jul  6 12:43:07 2014 Jean Fauquenot
** Last update Sun Jul  6 21:53:08 2014 nicolas vareille
*/

#ifndef GRAPH_H_
# define GRAPH_H_

# include <unistd.h>
# include <stdio.h>
# include "t_tracing.h"
# include "t_ktree.h"
# include "t_mangling.h"

# define GRAPH_START "digraph tracing {\n"
# define GRAPH_END_LINE ";\n"
# define GRAPH_CLOSING "\n}"
# define FUNCTION_LINK " -> "
# define SYSCALL_DEFINITION1 "\"%s@%s\"[color=red shape=box "
# define SYSCALL_DEFINITION2 "label=\"%s\\n@ %s\\nx %d\"];\n"
# define SYSCALL_DEFINITION SYSCALL_DEFINITION1 SYSCALL_DEFINITION2
# define SYSCALL_DEFINITION_U1 "\"%s@%s\"[color=red shape=box "
# define SYSCALL_DEFINITION_U2 "label=\"%s\\n@ %s\"];\n"
# define SYSCALL_DEFINITION_UNIQUE SYSCALL_DEFINITION_U1 SYSCALL_DEFINITION_U2
# define FUNCTION_DEFINITION1 "\"%s@%s\"[color=blue shape=octagon "
# define FUNCTION_DEFINITION2 "label=\"%s\\n@ %s\\nx %d\"];\n"
# define FUNCTION_DEFINITION FUNCTION_DEFINITION1 FUNCTION_DEFINITION2
# define FUNCTIO_DEFINITION_U1 "\"%s@%s\"[color=blue shape=octagon "
# define FUNCTIO_DEFINITION_U2 "label=\"%s\\n@ %s\"];\n"
# define FUNCTION_DEFINITION_UNIQUE FUNCTIO_DEFINITION_U1 FUNCTIO_DEFINITION_U2
# define EXTERN_D1 "\"%s@%s\"[color=black shape=oval "
# define EXTERN_D2 "label=\"%s\\n@ %s\\nx %d\"];\n"
# define EXTERN_DEFINITION EXTERN_D1 EXTERN_D2
# define EXTERN_D_U1 "\"%s@%s\"[color=black shape=oval "
# define EXTERN_D_U2 "label=\"%s\\n@ %s\"];\n"
# define EXTERN_DEFINITION_UNIQUE EXTERN_D1 EXTERN_D2
# define NONAME_DEF1 "\"%llx@%s\"[color=black shape=oval "
# define NONAME_DEF2 "label=\"%llx\\n@ %s\\nx %d\"];\n"
# define NONAME_DEFINITION NONAME_DEF1 NONAME_DEF2
# define NONAME_D_U1 "\"%llx@%s\"[color=black shape=oval "
# define NONAME_D_U2 "label=\"%llx\\n@ %s\"];\n"
# define NONAME_DEFINITION_UNIQUE NONAME_D_U1 NONAME_D_U2
# define SYSCALL_LIB "syscall"
# define TRACE_OUTPUT_FILE "tracing.dot"
# define BUFF_SIZE 1024

typedef struct	s_graph
{
  int		fd;
  int		first;
  int		put;
}		t_graph;

void			close_graph(t_graph *graph);
void			define_func(t_graph *graph, char const *, t_tracing *,
				    char *type);
void			define_functions(t_graph *, t_ktree_elem *);
void			draw_func(t_graph *graph, t_tracing *, int first);
void			gen_graph_start(t_graph *graph);
void			my_putgraph(t_graph *graph, char *str);
int			start_graph(t_ktree *tree);
void			trace_graph(t_graph *, t_ktree_elem *);

#endif /* !GRAPH_H_ */
