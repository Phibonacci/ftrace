/*
** ktree_new.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sat Jul  5 16:43:12 2014 Jean Fauquenot
** Last update Sat Jul  5 16:50:52 2014 Jean Fauquenot
*/

#include "t_ktree.h"

t_ktree		*ktree_new(void)
{
  t_ktree	*new;

  if ((new = malloc(sizeof(*new))) == NULL
      || ktree_init(new) == FAILURE)
    return (NULL);
  return (new);
}
