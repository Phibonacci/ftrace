/*
** stack_destroy.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sat Jun 28 16:41:17 2014 Jean Fauquenot
** Last update Sat Jun 28 17:16:28 2014 Jean Fauquenot
*/

#include "t_stack.h"

void		stack_destroy(t_stack *this)
{
  this->clear(this);
}
