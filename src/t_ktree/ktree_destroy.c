/*
** ktree_destroy.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sat Jul  5 17:07:33 2014 Jean Fauquenot
** Last update Sat Jul  5 17:48:44 2014 Jean Fauquenot
*/

#include "t_ktree.h"

void		ktree_destroy(t_ktree *this)
{
  list_destroy(&this->elems);
  ktree_clean(this);
}
