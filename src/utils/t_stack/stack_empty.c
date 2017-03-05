/*
** empty.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Thu Jun 19 09:29:59 2014 Jean Fauquenot
** Last update Fri Jul  4 20:47:23 2014 paul-maxime leduc
*/

#include	"t_stack.h"

t_bool		stack_empty(t_stack *this)
{
  if (this->_size == 0)
    return (TRUE);
  return (FALSE);
}
