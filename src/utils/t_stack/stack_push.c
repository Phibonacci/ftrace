/*
** push.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Thu Jun 19 09:28:52 2014 Jean Fauquenot
** Last update Thu Jun 19 09:29:05 2014 Jean Fauquenot
*/

#include	"t_stack.h"

#include	<stdlib.h>

t_state		stack_push(t_stack *this, void *data)
{
  t_stack_elem	*new;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (FAILURE);
  new->data = data;
  new->next = this->_top;
  this->_top = new;
  ++this->_size;
  return (SUCCESS);
}
