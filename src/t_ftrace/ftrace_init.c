/*
** ftrace_init.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sat Jun 28 17:56:17 2014 Jean Fauquenot
** Last update Sun Jul  6 20:02:01 2014 Jean Fauquenot
*/

#include "t_ftrace.h"

#include <string.h>

t_state		ftrace_init(t_ftrace *this, int argc, char *argv[])
{
  memset(this, 0, sizeof(*this));
  ktree_init(&this->_tree);
  this->_parser = ftrace_parser;
  this->start = ftrace_start;
  this->_fork = ftrace_fork;
  this->_child = ftrace_child;
  this->_attach = ftrace_attach;
  this->_trace = ftrace_trace;
  this->_last_signal = ftrace_last_signal;
  this->_init_signal = ftrace_init_signal;
  this->_break_signal = ftrace_break_signal;
  this->_break = ftrace_break;
  this->_syscall = ftrace_syscall;
  this->_call = ftrace_call;
  this->_call_inlist = ftrace_call_inlist;
  this->_syscall_inlist = ftrace_syscall_inlist;
  this->_ktree_link = ftrace_ktree_link;
  this->_call_exist = ftrace_call_exist;
  this->_getlib_name = ftrace_getlib_name;
  call_finder_init(&this->_call_finder);
  symbol_finder_cache_init(&this->_cache);
  if (this->_parser(this, argc, argv) == FAILURE)
    return (FAILURE);
  return (SUCCESS);
}
