/*
** begin.c for  in ./
**
** Made by Jean Fauquenot
** Login   <@epitech.net>
**
** Started on  Thu Jun 19 07:43:51 2014 Jean Fauquenot
** Last update Sat Jun 28 16:57:40 2014 Jean Fauquenot
*/

#include	"t_list.h"

#include	<stdlib.h>

t_list_iterator	list_begin(t_list *list)
{
  return (list->_front);
}
