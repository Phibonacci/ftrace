/*
** size.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Thu Jun 19 09:29:32 2014 Jean Fauquenot
** Last update Thu Jun 19 09:29:48 2014 Jean Fauquenot
*/

#include	"t_stack.h"

size_t		stack_size(t_stack *this)
{
  return (this->_size);
}
