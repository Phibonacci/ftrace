/*
** t_ktree.h for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sat Jul  5 16:21:40 2014 Jean Fauquenot
** Last update Sun Jul  6 20:47:16 2014 Jean Fauquenot
*/

#ifndef T_KTREE_H_
# define T_KTREE_H_

# include		"utils.h"
# include		"t_list.h"

typedef			struct s_ktree_elem t_ktree_elem;

struct s_ktree_elem
{
  bool			_passedby : 1;
  void			*data;
  t_list		next;
};

typedef			struct s_ktree t_ktree;

struct s_ktree
{
  t_ktree_elem		*root;
  t_list		elems;

  t_state		(*add)(t_ktree *this,
			       bool (*position)(void *elem,
						void *data,
						void *key),
			       void *data,
			       void *key);
  void			(*clean)(t_ktree *this);
};

t_ktree_elem	*ktree_elem_new(void *data);
t_state		ktree_elem_init(t_ktree_elem *this, void *data);
void		ktree_elem_delete(t_ktree_elem *this);
void		ktree_elem_destroy(t_ktree_elem *this);

t_ktree		*ktree_new(void);
t_state		ktree_init(t_ktree *this);
void		ktree_delete(t_ktree *this);
void		ktree_destroy(t_ktree *this);
void		ktree_clean(t_ktree *this);
t_state		ktree_add(t_ktree *this,
			  bool (*position)(void *elem, void *data, void *key),
			  void *data,
			  void *key);

#endif /* !T_KTREE_H_ */
