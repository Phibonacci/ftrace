/*
** push_back.c for  in ./
**
** Made by Jean Fauquenot
** Login   <@epitech.net>
**
** Started on  Thu Jun 19 07:37:47 2014 Jean Fauquenot
** Last update Thu Jun 19 07:38:00 2014 Jean Fauquenot
*/

#include	"t_list.h"

#include	<stdlib.h>

t_state		list_push_back(t_list *list, void *data)
{
  t_list_elem	*new;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (FAILURE);
  new->data = data;
  new->prev = list->_back;
  new->next = NULL;
  if (list->_back != NULL)
    list->_back->next = new;
  else
    list->_front = new;
  list->_back = new;
  ++list->_size;
  return (SUCCESS);
}
