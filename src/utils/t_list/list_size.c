/*
** size.c for  in ./
**
** Made by Jean Fauquenot
** Login   <@epitech.net>
**
** Started on  Thu Jun 19 07:40:22 2014 Jean Fauquenot
** Last update Sun Jul  6 21:08:37 2014 Jean Fauquenot
*/

#include "t_list.h"

#include <stddef.h>

size_t			list_size(t_list *list)
{
  return (list->_size);
}
