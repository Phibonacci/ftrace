/*
** symbol_finder_findsymbol.c for ftrace in /home/vareil_n/AUSP_ftrace
**
** Made by nicolas vareille
** Login   <vareil_n@epitech.net>
**
** Started on  Sat Jul  5 16:45:34 2014 nicolas vareille
** Last update Sun Jul  6 12:03:45 2014 paul-maxime leduc
*/

#include <stdio.h>
#include <gelf.h>
#include "t_symbol_finder.h"

static char const	*retrieve_fromgot(t_symbol_finder *self,
					  size_t offset,
					  size_t foffset)
{
  int			jmpoffset;
  int			instruction;
  t_list_iterator	it;
  t_gotsymbol		*data;

  if (foffset >= self->elfsize)
    return (0);
  instruction = *(int*)(self->elfbase + foffset);
  if (((instruction & 0xFFFF) ^ PLT_JMP_CHECK) != 0)
    return (NULL);
  jmpoffset = *(int*)(self->elfbase + foffset + 2);
  offset += (jmpoffset + 6);
  it = self->gotsymbols.begin(&self->gotsymbols);
  while (it)
    {
      data = it->data;
      if (data->offset == offset && data->index < self->dynsymcount)
	{
	  return (self->dynsyms[data->index].symbol);
	}
      it = it->next;
    }
  return (NULL);
}

static char const	*retrieve_fromstatic(t_symbol_finder *self,
					     size_t offset)
{
  size_t		i;

  i = 0;
  while (i < self->dynsymcount && self->dynsyms)
    {
      if (self->dynsyms[i].value == offset)
	{
	  return (self->dynsyms[i].symbol);
	}
      ++i;
    }
  i = 0;
  while (i < self->staticsymcount && self->staticsyms)
    {
      if (self->staticsyms[i].value == offset)
	{
	  return (self->staticsyms[i].symbol);
	}
      ++i;
    }
  return (NULL);
}

char const		*symbol_finder_findsymbol(t_symbol_finder *self,
						  size_t offset)
{
  char const		*rt;

  if (!(rt = retrieve_fromgot(self, offset + self->dynoffset, offset)))
    {
      offset += self->dynoffset;
      rt = retrieve_fromstatic(self, offset);
    }
  return (rt);
}
