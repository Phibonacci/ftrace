/*
** new.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Thu Jun 19 09:28:05 2014 Jean Fauquenot
** Last update Sat Jun 28 16:40:15 2014 Jean Fauquenot
*/

#include	"t_stack.h"

#include	<stdlib.h>

t_stack		*stack_new(void)
{
  t_stack	*new;

  if ((new = malloc(sizeof(*new))) == NULL
      || stack_init(new) == FAILURE)
    return (NULL);
  return (new);
}
