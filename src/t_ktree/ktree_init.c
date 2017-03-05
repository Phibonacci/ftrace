/*
** ktree_init.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sat Jul  5 16:51:02 2014 Jean Fauquenot
** Last update Sat Jul  5 17:45:25 2014 Jean Fauquenot
*/

#include "t_ktree.h"

#include <string.h>

t_state		ktree_init(t_ktree *this)
{
  memset(this, 0, sizeof(*this));
  list_init(&this->elems);
  this->add = ktree_add;
  this->clean = ktree_clean;
  return (SUCCESS);
}
