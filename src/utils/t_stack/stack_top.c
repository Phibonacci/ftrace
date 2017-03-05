/*
** top.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Thu Jun 19 09:30:05 2014 Jean Fauquenot
** Last update Thu Jun 19 09:30:24 2014 Jean Fauquenot
*/

#include	"t_stack.h"

#include	<stdlib.h>

void		*stack_top(t_stack *this)
{
  return (this->_top->data);
}
