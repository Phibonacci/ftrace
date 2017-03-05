/*
** t_symbol_finder.h for ftrace in /home/leduc_p/AUSP_ftrace/src
**
** Made by paul-maxime leduc
** Login   <leduc_p@epitech.net>
**
** Started on  Sat Jul  5 17:41:41 2014 paul-maxime leduc
** Last update Sun Jul  6 21:37:21 2014 nicolas vareille
*/

#ifndef T_SYMBOL_FINDER_H_
# define T_SYMBOL_FINDER_H_

# include <libelf.h>
# include "t_list.h"

# define	PLT_JMP_CHECK	0x25ff

typedef struct		s_gotsymbol
{
  size_t		offset;
  size_t		index;
}			t_gotsymbol;

typedef struct		s_staticsymbol
{
  size_t		value;
  char const		*symbol;
}			t_staticsymbol;

typedef struct		s_symbol_finder
{
  void			*elfbase;
  size_t		elfsize;
  Elf			*elfhandler;
  int			class;
  t_list		gotsymbols;
  t_staticsymbol	*dynsyms;
  size_t		dynsymcount;
  size_t		dynoffset;
  t_staticsymbol	*staticsyms;
  size_t		staticsymcount;
}			t_symbol_finder;

typedef struct		s_cachepair
{
  char			*key;
  t_symbol_finder	data;
}			t_cachepair;

typedef struct		s_symbol_finder_cache
{
  t_list		cache;
}			t_symbol_finder_cache;

int		symbol_finder_init(t_symbol_finder *self,
				   char const *filename);
int		symbol_finder_initgotsymbols(t_symbol_finder *self);
char const	*symbol_finder_findsymbol(t_symbol_finder *self,
					  size_t offset);
int		symbol_finder_end(t_symbol_finder *self);
int		symbol_finder_cache_init(t_symbol_finder_cache *);
t_symbol_finder	*symbol_finder_cache_finder(t_symbol_finder_cache *,
					    char *filename);
int		symbol_finder_cache_end(t_symbol_finder_cache *);

#endif /* !T_SYMBOL_FINDER_H_ */
