/*
** ktree_elem_init.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sat Jul  5 18:53:38 2014 Jean Fauquenot
** Last update Sat Jul  5 19:02:12 2014 Jean Fauquenot
*/

#include "t_ktree.h"

#include <string.h>

t_state		ktree_elem_init(t_ktree_elem *this, void *data)
{
  memset(this, 0, sizeof(*this));
  if (list_init(&this->next) == FAILURE)
    return (FAILURE);
  this->data = data;
  return (SUCCESS);
}
