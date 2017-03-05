/*
** pop_front.c for  in ./
**
** Made by Jean Fauquenot
** Login   <@epitech.net>
**
** Started on  Thu Jun 19 07:38:29 2014 Jean Fauquenot
** Last update Thu Jun 19 07:38:43 2014 Jean Fauquenot
*/

#include	"t_list.h"

#include	<stdlib.h>

t_state		list_pop_front(t_list *list)
{
  t_list_elem	*to_free;

  if (list->_front == NULL)
    return (FAILURE);
  to_free = list->_front;
  list->_front = list->_front->next;
  if (list->_front != NULL)
    list->_front->prev = NULL;
  else
    list->_back = NULL;
  free(to_free);
  --list->_size;
  return (SUCCESS);
}
