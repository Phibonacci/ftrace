/*
** call_finder_destroy.c for ftrace in /home/leduc_p/SysUnix/AUSP_ftrace
**
** Made by paul-maxime leduc
** Login   <leduc_p@epitech.net>
**
** Started on  Fri Jul  4 23:38:50 2014 paul-maxime leduc
** Last update Fri Jul  4 23:48:17 2014 paul-maxime leduc
*/

#include "t_call_finder.h"

void	call_finder_destroy(t_call_finder *this)
{
  while (!this->_backtrace.empty(&this->_backtrace))
    {
      free(this->_backtrace.top(&this->_backtrace));
      this->_backtrace.pop(&this->_backtrace);
    }
}
