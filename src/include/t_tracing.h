/*
** t_tracing.h for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sat Jul  5 16:21:28 2014 Jean Fauquenot
** Last update Sun Jul  6 19:36:04 2014 nicolas vareille
*/

#ifndef T_TRACING_H_
# define T_TRACING_H_

# include "t_ftrace.h"

typedef enum		s_calltype
  {
    SYSCALL,
    FUNCALL,
    EXTERNCALL
  }			t_calltype;

typedef struct		s_tracing
{

  char const		*name;
  char			*libname;
  t_reg			address;
  int			syscall_id;
  unsigned int		call_nbr;
  t_calltype		type;
}			t_tracing;

#endif /* !T_TRACING_H_ */
