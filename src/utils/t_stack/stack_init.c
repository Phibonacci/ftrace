/*
** stack_init.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sat Jun 28 16:36:23 2014 Jean Fauquenot
** Last update Sat Jun 28 17:14:43 2014 Jean Fauquenot
*/

#include "t_stack.h"

t_state		stack_init(t_stack *this)
{
  this->_size = 0;
  this->_top = NULL;
  this->push = stack_push;
  this->pop = stack_pop;
  this->size = stack_size;
  this->empty = stack_empty;
  this->top = stack_top;
  this->clear = stack_clear;
  return (SUCCESS);
}
