/*
** t_memory_map.h for ftrace in /home/leduc_p/AUSP_ftrace/src/memorymap
**
** Made by paul-maxime leduc
** Login   <leduc_p@epitech.net>
**
** Started on  Sat Jul  5 16:37:18 2014 paul-maxime leduc
** Last update Sun Jul  6 20:46:43 2014 Jean Fauquenot
*/

#ifndef T_MEMORY_MAP_H_
# define T_MEMORY_MAP_H_

# include	<stddef.h>

typedef		struct s_memorymap t_memorymap;

struct		s_memorymap
{
  char		*mapfile;
  size_t	memoryoff;
  char		*(*addressat)(t_memorymap *self, size_t offset);
};

int		memory_map_init(t_memorymap *, char *file);
void		memory_map_destroy(t_memorymap *);
char		*memory_map_addressat(t_memorymap *self, size_t offset);

#endif /* !T_MEMORY_MAP_H_ */
