/*
** t_call_finder.h for ftrace in /home/leduc_p/SysUnix/AUSP_ftrace
**
** Made by paul-maxime leduc
** Login   <leduc_p@epitech.net>
**
** Started on  Fri Jul  4 21:00:46 2014 paul-maxime leduc
** Last update Fri Jul  4 23:57:38 2014 paul-maxime leduc
*/

#ifndef T_CALL_FINDER_H_
# define T_CALL_FINDER_H_

# include <sys/user.h>
# include <sys/types.h>

# include "t_stack.h"

# define ASM_SYSCALL	0x050f	/**< x86_64 syscall instruction */
# define ASM_SYSENTER	0x340f	/**< x86 enter instruction */
# define ASM_INT80	0x80cd	/**< x86 int $80 instruction */

# define ASM_RET	0xc3	/**< x86 ret instruction */
# define ASM_REPZRET	0xc3f3	/**< x86 repz ret instruction */
# define ASM_CALL	0xe8	/**< x86 relative call */
# define ASM_ABSCALL	0x9a	/**< x86 absolute call */

typedef struct	user_regs_struct	t_regs;
typedef		unsigned long long int	t_reg;
typedef		unsigned long long int	t_addr;
typedef struct	s_called_function	t_called_function;
typedef struct	s_call_finder		t_call_finder;

struct	s_called_function
{
  t_addr	base_address;
  t_addr	return_address;
};

struct	s_call_finder
{
  t_stack	_backtrace;
  bool		_insyscall;
  bool		_incall;
  bool		is_syscall;
  int		syscall_id;
  bool		is_call;
  t_addr	call_parent;
  t_addr	call_address;
  t_state	(*step)(t_call_finder *, t_regs *regs, pid_t pid);
};

t_state		call_finder_init(t_call_finder *this);
void		call_finder_destroy(t_call_finder *this);

t_state		call_finder_step(t_call_finder *this,
				 t_regs *regs,
				 pid_t pid);

#endif /* !T_CALL_FINDER_H_ */
