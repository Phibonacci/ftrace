/*
** end.c for  in ./
**
** Made by Jean Fauquenot
** Login   <@epitech.net>
**
** Started on  Thu Jun 19 07:44:05 2014 Jean Fauquenot
** Last update Sat Jun 28 16:58:40 2014 Jean Fauquenot
*/

#include	"t_list.h"

#include	<stdlib.h>

t_list_iterator	list_end(t_list *list)
{
  return (list->_back);
}
