/*
** ktree_delete.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sat Jul  5 17:08:28 2014 Jean Fauquenot
** Last update Sat Jul  5 17:09:14 2014 Jean Fauquenot
*/

#include "t_ktree.h"

#include <stdlib.h>

void		ktree_delete(t_ktree *this)
{
  ktree_destroy(this);
  free(this);
}
