/*
** remove.c for  in ./
**
** Made by Jean Fauquenot
** Login   <@epitech.net>
**
** Started on  Thu Jun 19 07:42:47 2014 Jean Fauquenot
** Last update Sat Jun 28 16:58:55 2014 Jean Fauquenot
*/

#include	"t_list.h"

#include	<stdlib.h>

void		list_remove(t_list *list,
			    t_list_iterator elem,
			    t_bool data)
{
  if (elem->prev)
    elem->prev->next = elem->next;
  if (elem->next)
    elem->next->prev = elem->prev;
  if (list->_front == elem)
    list->_front = elem->next;
  if (data)
    free(elem->data);
  free(elem);
  --list->_size;
}
