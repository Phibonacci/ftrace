/*
** symbol_findercache_init.c for ftrace in /home/vareil_n/AUSP_ftrace
**
** Made by nicolas vareille
** Login   <vareil_n@epitech.net>
**
** Started on  Sat Jul  5 16:44:56 2014 nicolas vareille
** Last update Sun Jul  6 21:36:41 2014 nicolas vareille
*/

#include <string.h>
#include <stdlib.h>
#include "t_symbol_finder.h"

int		symbol_finder_cache_init(t_symbol_finder_cache *self)
{
  list_init(&self->cache);
  return (0);
}

void		destroy_pair(t_cachepair *pair)
{
  free(pair->key);
  symbol_finder_end(&pair->data);
}

t_symbol_finder		*symbol_finder_cache_finder(t_symbol_finder_cache *self,
						    char *filename)
{
  t_list_iterator	it;
  t_cachepair		*pair;

  it = self->cache.begin(&self->cache);
  while (it)
    {
      pair = it->data;
      if (!strcmp(pair->key, filename))
	return (&pair->data);
      it = it->next;
    }
  if ((pair = malloc(sizeof(*pair))))
    {
      pair->key = strdup(filename);
      symbol_finder_init(&pair->data, filename);
      self->cache.push_back(&self->cache, pair);
      return (&pair->data);
    }
  return (0);
}

int		symbol_finder_cache_end(t_symbol_finder_cache *self)
{
  self->cache.ondestroy = (void (*)(void*))destroy_pair;
  list_destroy(&self->cache);
  return (0);
}
