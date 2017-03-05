/*
** ftrace_ktree_link.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sun Jul  6 19:45:54 2014 Jean Fauquenot
** Last update Sun Jul  6 19:46:03 2014 Jean Fauquenot
*/

#include "t_ftrace.h"
#include "t_tracing.h"

t_state			ftrace_ktree_link(t_ftrace *this, t_ktree_elem *elem,
					  t_reg parent)
{
  t_list_iterator	it;
  t_ktree_elem		*elemx;
  t_ktree_elem		*new;

  it = this->_tree.elems.begin(&this->_tree.elems);
  while (it)
    {
      elemx = ((t_ktree_elem *)it->data);
      if (((t_tracing *)elemx->data)->type != SYSCALL
	  && ((t_tracing *)elemx->data)->address == parent)
	{
	  if ((new = ktree_elem_new(elem->data)) == NULL)
	    return (FAILURE);
	  if (!ftrace_call_inlist(this,
				  ((t_tracing *)elem->data)->address,
				  &elemx->next))
	    elemx->next.push_back(&elemx->next, new);
	  return (SUCCESS);
	}
      it = it->next;
    }
  return (FAILURE);
}
