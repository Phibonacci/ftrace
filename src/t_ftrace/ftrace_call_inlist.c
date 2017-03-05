/*
** ftrace_call_inlist.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sun Jul  6 17:48:48 2014 Jean Fauquenot
** Last update Sun Jul  6 17:53:45 2014 Jean Fauquenot
*/

#include "t_ftrace.h"
#include "t_tracing.h"

bool			ftrace_call_inlist(t_ftrace *this, t_reg addr,
					    t_list *elem)
{
  t_list_iterator	it;
  t_ktree_elem		*elemx;

  it = elem->begin(&this->_tree.elems);
  while (it)
    {
      elemx = ((t_ktree_elem *)it->data);
      if (((t_tracing *)elemx->data)->address == addr)
	return (true);
      it = it->next;
    }
  return (false);
}
