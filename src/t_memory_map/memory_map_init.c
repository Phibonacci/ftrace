/*
** memorymap_init.c for ftrace in /home/leduc_p/AUSP_ftrace
**
** Made by paul-maxime leduc
** Login   <leduc_p@epitech.net>
**
** Started on  Sat Jul  5 16:37:15 2014 paul-maxime leduc
** Last update Sat Jul  5 17:14:56 2014 paul-maxime leduc
*/

#include <string.h>
#include "t_memory_map.h"

int	memory_map_init(t_memorymap *self, char *file)
{
  memset(self, 0, sizeof(*self));
  self->mapfile = strdup(file);
  self->addressat = memory_map_addressat;
  return (0);
}
