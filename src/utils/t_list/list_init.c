/*
** list_init.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Fri Jun 27 15:50:15 2014 Jean Fauquenot
** Last update Sat Jun 28 17:10:43 2014 Jean Fauquenot
*/

#include	"t_list.h"

#include	<stddef.h>

t_state		list_init(t_list *this)
{
  this->_size = 0;
  this->_front = NULL;
  this->_back = NULL;
  this->ondestroy = NULL;
  this->push_front = list_push_front;
  this->push_back = list_push_back;
  this->pop_front = list_pop_front;
  this->pop_back = list_pop_back;
  this->empty = list_empty;
  this->size = list_size;
  this->front = list_front;
  this->back = list_back;
  this->assign = list_assign;
  this->insert = list_insert;
  this->remove = list_remove;
  this->clear = list_clear;
  this->begin = list_begin;
  this->end = list_end;
  return (SUCCESS);
}
