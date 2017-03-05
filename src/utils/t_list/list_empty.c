/*
** empty.c for  in ./
**
** Made by Jean Fauquenot
** Login   <@epitech.net>
**
** Started on  Thu Jun 19 07:39:39 2014 Jean Fauquenot
** Last update Thu Jun 19 07:40:02 2014 Jean Fauquenot
*/

#include	"t_list.h"

#include	<stddef.h>

t_bool		list_empty(t_list *list)
{
  if (list->_front == NULL)
    return (TRUE);
  return (FALSE);
}
