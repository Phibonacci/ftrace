/*
** pop_back.c for  in ./
**
** Made by Jean Fauquenot
** Login   <@epitech.net>
**
** Started on  Thu Jun 19 07:38:36 2014 Jean Fauquenot
** Last update Thu Jun 19 07:39:02 2014 Jean Fauquenot
*/

#include	"t_list.h"

#include	<stdlib.h>

t_state		list_pop_back(t_list *list)
{
  t_list_elem	*to_free;

  if (list->_front == NULL)
    return (FAILURE);
  to_free = list->_back;
  list->_back = list->_back->prev;
  if (list->_back != NULL)
    list->_back->next = NULL;
  else
    list->_front = NULL;
  free(to_free);
  --list->_size;
  return (SUCCESS);
}
