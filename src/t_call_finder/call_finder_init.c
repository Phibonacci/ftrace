/*
** call_finder_init.c for ftrace in /home/leduc_p/SysUnix/AUSP_ftrace
**
** Made by paul-maxime leduc
** Login   <leduc_p@epitech.net>
**
** Started on  Fri Jul  4 23:35:40 2014 paul-maxime leduc
** Last update Sat Jul  5 00:12:10 2014 paul-maxime leduc
*/

#include <string.h>
#include "t_call_finder.h"

t_state		call_finder_init(t_call_finder *this)
{
  memset(this, 0, sizeof(*this));
  stack_init(&this->_backtrace);
  this->step = call_finder_step;
  return (SUCCESS);
}
