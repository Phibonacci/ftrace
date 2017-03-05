/*
** list_delete.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Fri Jun 27 15:53:47 2014 Jean Fauquenot
** Last update Fri Jun 27 15:54:24 2014 Jean Fauquenot
*/

#include	"t_list.h"

#include	<stdlib.h>

void		list_delete(t_list *this)
{
  list_destroy(this);
  free(this);
}
