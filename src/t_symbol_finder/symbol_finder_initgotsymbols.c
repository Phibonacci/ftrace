/*
** symbol_finder_initgotsymbols.c for ftrace in /home/vareil_n/AUSP_ftrace
**
** Made by nicolas vareille
** Login   <vareil_n@epitech.net>
**
** Started on  Sat Jul  5 16:48:12 2014 nicolas vareille
** Last update Sun Jul  6 20:45:54 2014 Jean Fauquenot
*/

#include <stdio.h>
#include <gelf.h>
#include "t_symbol_finder.h"

static int	retrieve_symtab(t_symbol_finder *self, GElf_Shdr *shdr,
				Elf_Scn *scn)
{
  Elf_Data	*edata;
  GElf_Sym	sym;
  int		i;
  int		symbol_count;

  if ((shdr->sh_type == SHT_SYMTAB))
    {
      edata = elf_getdata(scn, NULL);
      symbol_count = shdr->sh_size / shdr->sh_entsize;
      if (!(self->staticsyms =
	    malloc(sizeof(*self->staticsyms) * symbol_count)))
	return (1);
      self->staticsymcount = symbol_count;
      for (i = 0; i < symbol_count; i++)
	{
	  gelf_getsym(edata, i, &sym);
	  self->staticsyms[i].value = sym.st_value;
	  self->staticsyms[i].symbol = elf_strptr(self->elfhandler,
						  shdr->sh_link, sym.st_name);
	}
    }
  return (0);
}

static int	retrieve_dynsym(t_symbol_finder *self, GElf_Shdr *shdr,
				Elf_Scn *scn)
{
  Elf_Data	*edata;
  GElf_Sym	sym;
  int		i;
  int		symbol_count;

  if ((shdr->sh_type == SHT_DYNSYM))
    {
      edata = elf_getdata(scn, NULL);
      symbol_count = shdr->sh_size / shdr->sh_entsize;
      if (!(self->dynsyms = malloc(sizeof(*self->dynsyms) * symbol_count)))
	return (1);
      self->dynsymcount = symbol_count;
      self->dynoffset = shdr->sh_addr - shdr->sh_offset;
      for (i = 0; i < symbol_count; i++)
	{
	  gelf_getsym(edata, i, &sym);
	  self->dynsyms[i].value = sym.st_value;
	  self->dynsyms[i].symbol = elf_strptr(self->elfhandler,
					       shdr->sh_link, sym.st_name);
	}
    }
  return (0);
}

static t_gotsymbol	*new_gotsymbol(size_t offset, int index)
{
  t_gotsymbol		*rt;

  if ((rt = malloc(sizeof(*rt))))
    {
      rt->offset = offset;
      rt->index = index;
    }
  return (rt);
}

static int	retrieve_rela(t_symbol_finder *self, GElf_Shdr *shdr,
				      Elf_Scn *scn)
{
  Elf_Data	*edata;
  GElf_Rela	rela;
  int		symbol_count;
  int		i;
  t_gotsymbol	*got;

  if ((shdr->sh_type == SHT_RELA))
    {
      edata = elf_getdata(scn, NULL);
      symbol_count = shdr->sh_size / shdr->sh_entsize;
      for (i = 0; i < symbol_count; i++)
	{
	  gelf_getrela(edata, i, &rela);
	  got = new_gotsymbol(rela.r_offset, ELF64_R_SYM(rela.r_info));
	  self->gotsymbols.push_front(&self->gotsymbols, got);
	}
    }
  return (0);
}

int		symbol_finder_initgotsymbols(t_symbol_finder *self)
{
  GElf_Shdr	shdr;
  Elf_Scn	*scn;

  scn = NULL;
  while ((scn = elf_nextscn(self->elfhandler, scn)) != NULL)
    {
      gelf_getshdr(scn, &shdr);
      retrieve_rela(self, &shdr, scn);
      retrieve_dynsym(self, &shdr, scn);
      retrieve_symtab(self, &shdr, scn);
    }
  return (0);
}
