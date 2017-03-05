/*
** push_front.c for  in ./
**
** Made by Jean Fauquenot
** Login   <@epitech.net>
**
** Started on  Thu Jun 19 07:37:33 2014 Jean Fauquenot
** Last update Thu Jun 19 07:37:56 2014 Jean Fauquenot
*/

#include	"t_list.h"

#include	<stdlib.h>

t_state		list_push_front(t_list *list, void *data)
{
  t_list_elem	*new;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (FAILURE);
  new->data = data;
  new->prev = NULL;
  new->next = list->_front;
  if (list->_front != NULL)
    list->_front->prev = new;
  else
    list->_back = new;
  list->_front = new;
  ++list->_size;
  return (SUCCESS);
}
