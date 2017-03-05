/*
** front.c for  in ./
**
** Made by Jean Fauquenot
** Login   <@epitech.net>
**
** Started on  Thu Jun 19 07:40:41 2014 Jean Fauquenot
** Last update Thu Jun 19 07:40:53 2014 Jean Fauquenot
*/

#include	"t_list.h"

#include	<stddef.h>

void		*list_front(t_list *list)
{
  if (list->_front == NULL)
    return (NULL);
  return (list->_front->data);
}
