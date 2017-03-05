/*
** ftrace_call.c for ftrace in /home/leduc_p/SysUnix/AUSP_ftrace
**
** Made by paul-maxime leduc
** Login   <leduc_p@epitech.net>
**
** Started on  Fri Jul  4 20:22:50 2014 paul-maxime leduc
** Last update Sun Jul  6 20:32:36 2014 nicolas vareille
*/

#include "t_ftrace.h"
#include "t_tracing.h"
#include <stdio.h>
#include <string.h>

static bool	ftrace_ktree_aux(void *ref, void *UNUSED(data), void *key)
{
  if (((t_tracing *)ref)->address == *((t_reg *)key))
    return (true);
  return (false);
}

static bool	ftrace_ktree_true(void *UNUSED(ref),
				  void *UNUSED(data),
				  void *UNUSED(key))
{
  return (true);
}

static int	call_get_type(const char *file)
{
  int		len;

  if (!file || (len = strlen(file)) < 5)
    return (FUNCALL);
  if (!strcmp(file + len - 3, ".so") || strstr(file, ".so."))
    return (EXTERNCALL);
  return (FUNCALL);
}

t_state			ftrace_call_set(t_ftrace *this,
					t_reg addr,
					t_tracing **new)
{
  char			*file;
  t_symbol_finder	*finder;
  t_memorymap		map;
  char const		*sym;
  char			buf[32];

  snprintf(buf, sizeof(buf), "/proc/%d/maps", this->_pid);
  memory_map_init(&map, buf);
  file = map.addressat(&map, addr);
  sym = NULL;
  if ((*new = malloc(sizeof(**new))) == NULL)
    return (FAILURE);
  memset(*new, 0, sizeof(**new));
  if (file && (finder = symbol_finder_cache_finder(&this->_cache, file)))
    {
      (*new)->libname = this->_getlib_name(this, file);
      sym = symbol_finder_findsymbol(finder, addr - map.memoryoff);
      free(file);
    }
  memory_map_destroy(&map);
  (*new)->address = addr;
  (*new)->name = sym;
  (*new)->call_nbr = 0;
  (*new)->type = call_get_type((*new)->libname);
  return (SUCCESS);
}

t_state			ftrace_call(t_ftrace *this, t_reg parent, t_reg addr)
{
  t_tracing		*new;
  t_ktree_elem		*elem;

  if ((elem = ftrace_call_exist(this, addr)) != NULL)
    {
      ((t_tracing *)elem->data)->call_nbr++;
      this->_ktree_link(this, elem, parent);
    }
  else
    {
      if (ftrace_call_set(this, addr, &new) == FAILURE)
	return (FAILURE);
      if (this->_tree.add(&this->_tree,
			  ftrace_ktree_aux,
			  new, &parent) == FAILURE)
	return (this->_tree.add(&this->_tree,
				ftrace_ktree_true,
				new, &parent));

    }
  return (SUCCESS);
}
