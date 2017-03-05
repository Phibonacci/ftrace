/*
** stack_delete.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sat Jun 28 16:40:25 2014 Jean Fauquenot
** Last update Sat Jun 28 16:52:44 2014 Jean Fauquenot
*/

#include "t_stack.h"

#include <stdlib.h>

void		stack_delete(t_stack *this)
{
  stack_destroy(this);
  free(this);
}
