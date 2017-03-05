/*
** assign.c for  in ./
**
** Made by Jean Fauquenot
** Login   <@epitech.net>
**
** Started on  Thu Jun 19 07:41:54 2014 Jean Fauquenot
** Last update Sat Jun 28 17:05:12 2014 Jean Fauquenot
*/

#include	"t_list.h"

void		list_assign(t_list *UNUSED(list),
			    t_list_iterator it,
			    void *data)
{
  it->data = data;
}
