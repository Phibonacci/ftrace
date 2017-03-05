/*
** ktree_add.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sat Jul  5 17:27:09 2014 Jean Fauquenot
** Last update Sun Jul  6 19:56:58 2014 hengrui
*/

#include "t_ktree.h"

t_state			ktree_add(t_ktree *this,
				  bool (*position)(void *,
						   void *,
						   void *),
				  void *data,
				  void *key)
{
  t_list_iterator	it;
  t_ktree_elem		*new;

  if (this->root == NULL)
    {
      if ((new = ktree_elem_new(data)) == NULL)
	return (FAILURE);
      this->elems.push_back(&this->elems, new);
      this->root = new;
    }
  for (it = this->elems.begin(&this->elems); it != NULL; it = it->next)
    {
      if (position(((t_ktree_elem *)it->data)->data, data, key) == true)
	{
	  t_ktree_elem *father = ((t_ktree_elem *)it->data);

	  if ((new = ktree_elem_new(data)) == NULL)
	    return (FAILURE);
	  this->elems.push_back(&this->elems, new);
	  father->next.push_back(&father->next,
				 new);
	  return (SUCCESS);
	}
    }
  return (FAILURE);
}
