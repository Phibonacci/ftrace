/*
** new.c for  in ./
**
** Made by Jean Fauquenot
** Login   <@epitech.net>
**
** Started on  Thu Jun 19 07:37:05 2014 Jean Fauquenot
** Last update Fri Jun 27 15:52:02 2014 Jean Fauquenot
*/

#include	"t_list.h"

#include	<stdlib.h>

t_list		*list_new(void)
{
  t_list	*new;

  if ((new = malloc(sizeof(t_list))) == NULL
      || list_init(new) == FAILURE)
    return (NULL);
  return (new);
}
