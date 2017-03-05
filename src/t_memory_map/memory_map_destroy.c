/*
** memory_map_destroy.c for ftrace in /home/leduc_p/AUSP_ftrace
**
** Made by paul-maxime leduc
** Login   <leduc_p@epitech.net>
**
** Started on  Sat Jul  5 16:42:11 2014 paul-maxime leduc
** Last update Sat Jul  5 16:49:11 2014 paul-maxime leduc
*/

#include <stdlib.h>
#include "t_memory_map.h"

void	memory_map_destroy(t_memorymap *self)
{
  free(self->mapfile);
}
