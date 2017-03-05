/*
** ftrace.h for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sat Jun 28 17:30:20 2014 Jean Fauquenot
** Last update Sun Jul  6 21:04:46 2014 Jean Fauquenot
*/

#ifndef T_FTRACE_H_
# define T_FTRACE_H_

# include "utils.h"
# include "t_memory_map.h"
# include "t_symbol_finder.h"
# include "t_stack.h"
# include "t_call_finder.h"
# include "t_ktree.h"
# include "t_tracing.h"

typedef			struct s_ftrace t_ftrace;

struct			s_ftrace
{
  bool			_isrunning;
  bool			_isattached;
  pid_t			_pid;
  char			*_bin;
  char			**_opt;
  bool			_is32bits;
  unsigned int		_syscall_id;
  int			_sys_index;

  t_call_finder		_call_finder;
  t_symbol_finder_cache	_cache;
  t_ktree		_tree;

  t_state		(*_parser)(t_ftrace *, int, char **);
  t_state		(*_fork)(t_ftrace *);
  void			(*_child)(char *, char **);
  t_state		(*_attach)(t_ftrace *);
  t_state		(*_trace)(t_ftrace *);
  int			(*_last_signal)(void);
  int			(*_init_signal)(void);
  int			(*_break_signal)(t_ftrace *, int);
  t_state		(*_break)(t_ftrace *, int);
  t_state		(*_syscall)(t_ftrace *, t_reg);
  t_state		(*_call)(t_ftrace *, t_reg, t_reg);
  bool			(*_call_inlist)(t_ftrace *, t_reg,
					t_list *);
  bool			(*_syscall_inlist)(t_ftrace *, int,
				   t_list *);
  t_ktree_elem		*(*_call_exist)(t_ftrace *, t_reg);
  t_state		(*_ktree_link)(t_ftrace *, t_ktree_elem *,
			       t_reg);
  char			*(*_getlib_name)(t_ftrace *, const char *);

  t_state		(*start)(t_ftrace *);
};

t_state		ftrace_init(t_ftrace *this, int argc, char *argv[]);
t_ftrace	*ftrace_new(int argc, char **argv);
void		ftrace_destroy(t_ftrace *this);
void		ftrace_delete(t_ftrace *this);

t_state		ftrace_parser(t_ftrace *this, int argc, char *argv[]);
t_state		ftrace_start(t_ftrace *this);
t_state		ftrace_fork(t_ftrace *this);
void		ftrace_child(char *process, char **argv);
t_state		ftrace_trace(t_ftrace *this);

int		ftrace_last_signal(void);
int		ftrace_init_signal(void);
int		ftrace_break_signal(t_ftrace *this, int signal);
t_state		ftrace_break(t_ftrace *this, int signal);
t_state		ftrace_syscall(t_ftrace *this, t_reg parent);
t_state		ftrace_call(t_ftrace *this, t_reg parent, t_reg addr);
t_state		ftrace_attach(t_ftrace *this);
bool		ftrace_call_inlist(t_ftrace *this, t_reg addr,
				   t_list *elem);
bool		ftrace_syscall_inlist(t_ftrace *this, int id,
				      t_list *elem);
t_ktree_elem	*ftrace_call_exist(t_ftrace *this, t_reg addr);
t_state		ftrace_ktree_link(t_ftrace *this, t_ktree_elem *elem,
				  t_reg parent);
char		*ftrace_getlib_name(t_ftrace *this, const char *path);

#endif /* !T_FTRACE_H_ */
