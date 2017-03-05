/*
** ftrace_call_exist.c for ftrace in /home/leduc_p/AUSP_ftrace
**
** Made by paul-maxime leduc
** Login   <leduc_p@epitech.net>
**
** Started on  Sun Jul  6 20:11:59 2014 paul-maxime leduc
** Last update Sun Jul  6 20:12:58 2014 paul-maxime leduc
*/

#include <stdlib.h>
#include "t_ftrace.h"

t_ktree_elem		*ftrace_call_exist(t_ftrace *this, t_reg addr)
{
  t_list_iterator	it;
  t_ktree_elem		*elemx;

  it = this->_tree.elems.begin(&this->_tree.elems);
  while (it)
    {
      elemx = ((t_ktree_elem *)it->data);
      if (((t_tracing *)elemx->data)->type != SYSCALL
	  && ((t_tracing *)elemx->data)->address == addr)
	return (elemx);
      it = it->next;
    }
  return (NULL);
}
