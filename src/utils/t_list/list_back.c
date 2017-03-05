/*
** back.c for  in ./
**
** Made by Jean Fauquenot
** Login   <@epitech.net>
**
** Started on  Thu Jun 19 07:41:14 2014 Jean Fauquenot
** Last update Thu Jun 19 07:41:22 2014 Jean Fauquenot
*/

#include	"t_list.h"

#include	<stddef.h>

void		*list_back(t_list *list)
{
  if (list->_back == NULL)
    return (NULL);
  return (list->_back->data);
}
