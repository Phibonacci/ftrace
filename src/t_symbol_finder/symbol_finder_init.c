/*
** symbolfinder_init.c for ftrace in /home/vareil_n/AUSP_ftrace
**
** Made by nicolas vareille
** Login   <vareil_n@epitech.net>
**
** Started on  Sat Jul  5 16:47:21 2014 nicolas vareille
** Last update Sat Jul  5 18:17:27 2014 paul-maxime leduc
*/

#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <gelf.h>
#include "t_symbol_finder.h"

int		symbol_finder_init(t_symbol_finder *self,
				   char const *filename)
{
  int		fd;
  struct stat	sb;
  void		*p;

  memset(self, 0, sizeof(*self));
  if (elf_version(EV_CURRENT) == EV_NONE)
    return (1);
  if ((fd = open(filename, O_RDONLY)) < 0 ||
      fstat(fd, &sb) <	0 ||
      (p = mmap(NULL, sb.st_size, PROT_READ,
		MAP_PRIVATE, fd, 0)) == MAP_FAILED)
    return (1);
  close(fd);
  if (!(self->elfhandler = elf_memory(p, sb.st_size)) ||
      elf_kind(self->elfhandler) != ELF_K_ELF ||
      (self->class = gelf_getclass(self->elfhandler)) == ELFCLASSNONE)
    {
      munmap(p, sb.st_size);
      return (1);
    }
  self->elfbase = p;
  self->elfsize = sb.st_size;
  list_init(&self->gotsymbols);
  symbol_finder_initgotsymbols(self);
  return (0);
}

int	symbol_finder_end(t_symbol_finder *self)
{
  free(self->dynsyms);
  free(self->staticsyms);
  (self->gotsymbols).ondestroy = free;
  list_destroy(&self->gotsymbols);
  elf_end(self->elfhandler);
  munmap(self->elfbase, self->elfsize);
  return (0);
}
