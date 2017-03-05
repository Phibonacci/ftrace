/*
** list_destroy.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Fri Jun 27 15:52:23 2014 Jean Fauquenot
** Last update Sat Jun 28 17:11:18 2014 Jean Fauquenot
*/

#include	"t_list.h"

#include	<stdlib.h>

void		list_destroy(t_list *this)
{
  this->clear(this);
}
