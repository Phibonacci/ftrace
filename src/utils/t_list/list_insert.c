/*
** insert.c for  in ./
**
** Made by Jean Fauquenot
** Login   <@epitech.net>
**
** Started on  Thu Jun 19 07:41:28 2014 Jean Fauquenot
** Last update Sat Jun 28 16:58:48 2014 Jean Fauquenot
*/

#include	"t_list.h"

#include	<stddef.h>

t_state		list_insert(t_list *list,
			    t_list_iterator position,
			    void *data)
{
  t_list_elem	*new;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (FAILURE);
  new->data = data;
  new->next = position;
  new->prev = position->prev;
  position->prev = new;
  if (new->prev != NULL)
    new->prev->next = new;
  if (position == list->_front)
    list->_front = new;
  ++list->_size;
  return (SUCCESS);
}
