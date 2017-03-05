/*
** ftrace_syscall.c for ftrace in /home/leduc_p/AUSP_ftrace
**
** Made by paul-maxime leduc
** Login   <leduc_p@epitech.net>
**
** Started on  Sun Jul  6 18:10:47 2014 paul-maxime leduc
** Last update Sun Jul  6 19:51:49 2014 Jean Fauquenot
*/

#include "t_ftrace.h"
#include "syscalls.h"

#include <string.h>
#include <stdio.h>

static t_state		get_syscall_index(t_ftrace *this)
{
  unsigned int		i;

  if (this->_is32bits)
    {
      i = 0;
      while (i < LEN(g_syscall))
	{
	  if (g_syscall[i].id_x86 != -1 &&
	      g_syscall[i].id_x86 == (unsigned int)this->_syscall_id)
	    return ((int)i);
	  ++i;
	}
    }
  else if (this->_syscall_id < LEN(g_syscall) &&
	   g_syscall[this->_syscall_id].id_x86_64 != -1)
    return (this->_syscall_id);
  return (FAILURE);
}

static bool	ftrace_ktree_aux(void *ref,
				 void *UNUSED(data),
				 void *key)
{
  if (((t_tracing *)ref)->address == *((t_reg *)key))
    return (true);
  return (false);
}

bool			ftrace_syscall_inlist(t_ftrace *UNUSED(this), int id,
					      t_list *elem)
{
  t_list_iterator	it;
  t_ktree_elem		*elemx;

  it = elem->begin(elem);
  while (it)
    {
      elemx = ((t_ktree_elem *)it->data);
      if (((t_tracing *)elemx->data)->type == SYSCALL
	  && ((t_tracing *)elemx->data)->syscall_id == id)
	return (true);
      it = it->next;
    }
  return (false);
}



t_state			ftrace_syscall(t_ftrace *this, t_reg parent)
{
  t_tracing		*new;
  t_ktree_elem		*elem;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (FAILURE);
  memset(new, 0, sizeof(*new));
  new->type = SYSCALL;
  new->address = 0;
  this->_sys_index = get_syscall_index(this);
  new->name = g_syscall[this->_sys_index].name;
  new->syscall_id = this->_sys_index;
  elem = ftrace_call_exist(this, parent);
  if (!this->_syscall_inlist(this, new->syscall_id, &elem->next))
    this->_tree.add(&this->_tree, ftrace_ktree_aux, new, &parent);
  return (SUCCESS);
}
