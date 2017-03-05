/*
** memory_map_addressat.c for ftrace in /home/leduc_p/AUSP_ftrace
**
** Made by paul-maxime leduc
** Login   <leduc_p@epitech.net>
**
** Started on  Sat Jul  5 16:40:48 2014 paul-maxime leduc
** Last update Sun Jul  6 12:12:31 2014 paul-maxime leduc
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "t_memory_map.h"

static void	parse_line(t_memorymap *self, size_t offset,
			   char **rt, size_t bound[2])
{
  bound[1] = strtol(*rt + 1, NULL, 16);
  if ((*rt = strstr(*rt, " /")) && bound[0] <= offset && bound[1] > offset)
    {
      self->memoryoff = bound[0];
      *rt = strndup(*rt + 1, strlen(*rt + 1) - 1);
    }
  else
    *rt = NULL;
}

char		*memory_map_addressat(t_memorymap *self, size_t offset)
{
  FILE		*stream;
  char		*line;
  char		*rt;
  size_t	bound[2];

  if (!(stream = fopen(self->mapfile, "r")))
    return (NULL);
  line = NULL;
  rt = NULL;
  while (!rt && (getline(&line, bound, stream)) > 0 && line)
    {
      bound[0] = strtol(line, NULL, 16);
      if ((rt = strchr(line, '-')))
	parse_line(self, offset, &rt, bound);
      free(line);
      line = NULL;
    }
  free(line);
  line = NULL;
  fclose(stream);
  return (rt);
}
