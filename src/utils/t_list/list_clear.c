/*
** clear.c for  in ./
**
** Made by Jean Fauquenot
** Login   <@epitech.net>
**
** Started on  Thu Jun 19 07:43:30 2014 Jean Fauquenot
** Last update Sun Jul  6 21:08:48 2014 Jean Fauquenot
*/

#include "t_list.h"

#include <stdlib.h>

void			list_clear(t_list *this)
{
  t_list_iterator	it;
  t_list_elem		*to_free;

  it = this->_front;
  while (it != NULL)
    {
      to_free = it;
      it = it->next;
      if (this->ondestroy != NULL)
	this->ondestroy(to_free->data);
      free(to_free);
    }
  this->_size = 0;
  this->_front = NULL;
  this->_back = NULL;
}
