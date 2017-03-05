/*
** pop.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Thu Jun 19 09:29:16 2014 Jean Fauquenot
** Last update Thu Jun 19 09:29:23 2014 Jean Fauquenot
*/

#include	"t_stack.h"

#include	<stdlib.h>

t_state		stack_pop(t_stack *this)
{
  t_stack_elem	*to_free;

  if (this->top == NULL)
    return (FAILURE);
  to_free = this->_top;
  this->_top = this->_top->next;
  free(to_free);
  --this->_size;
  return (SUCCESS);
}
