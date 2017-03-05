/*
** ktree_elem_new.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sat Jul  5 18:52:37 2014 Jean Fauquenot
** Last update Sat Jul  5 18:55:54 2014 Jean Fauquenot
*/

#include "t_ktree.h"

t_ktree_elem	*ktree_elem_new(void *data)
{
  t_ktree_elem	*new;

  if ((new = malloc(sizeof(*new))) == NULL
      || ktree_elem_init(new, data) == FAILURE)
    return (NULL);
  return (new);
}
