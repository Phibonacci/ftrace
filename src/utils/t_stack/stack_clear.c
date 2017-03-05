/*
** stack_clean.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sat Jun 28 16:43:59 2014 Jean Fauquenot
** Last update Sat Jun 28 17:17:21 2014 Jean Fauquenot
*/

#include "t_stack.h"

#include <stdlib.h>

void		stack_clear(t_stack *this)
{
  while (!this->empty(this))
    this->pop(this);
}
