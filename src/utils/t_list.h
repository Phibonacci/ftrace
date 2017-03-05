/*
** t_list.h for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Mon Jun 16 17:33:40 2014 Jean Fauquenot
** Last update Sat Jun 28 17:13:14 2014 Jean Fauquenot
*/

/**
** @file	t_list.h
** @brief	The t_list Class
*/

#ifndef T_LIST_H_
# define T_LIST_H_

# include "utils.h"

typedef struct		s_list_elem
{
  void			*data;
  struct s_list_elem	*prev;
  struct s_list_elem	*next;
}			t_list_elem;

typedef			t_list_elem * t_list_iterator;

typedef struct s_list	t_list;

/**
** @brief	t_list Class
**
** A C list implementation object oriented
*/
struct			s_list
{
  size_t		_size;
  t_list_elem		*_front;
  t_list_elem		*_back;
  void			(*ondestroy)(void *data);

  t_state		(*push_front)(t_list *this, void *data);
  t_state		(*push_back)(t_list *this, void *data);
  t_state		(*pop_front)(t_list *this);
  t_state		(*pop_back)(t_list *this);
  t_bool		(*empty)(t_list *this);
  size_t		(*size)(t_list *this);
  void			*(*front)(t_list *this);
  void			*(*back)(t_list *this);
  void			(*assign)(t_list *this,
				  t_list_iterator it,
				  void *data);
  t_state		(*insert)(t_list *this,
				  t_list_iterator it,
				  void *data);
  void			(*remove)(t_list *this,
				  t_list_iterator it,
				  t_bool data);
  void			(*clear)(t_list *this);
  t_list_iterator	(*begin)(t_list *this);
  t_list_iterator	(*end)(t_list *this);
};

/**
** @brief	list constructor
** @see		t_list
** @return	a t_list object initialized
**
** This function allocates memory and can fail.
*/
t_list		*list_new(void);

t_state		list_init(t_list *this);

void		list_delete(t_list *this);

void		list_destroy(t_list *this);


/**
** @brief	push_front method
** @param	this the t_list object
** @param	data a void * pointer to store in the list
** @return	a t_state state of the function
**
** This function allocates memory and can fail.
*/
t_state		list_push_front(t_list *this, void *data);

/**
** @brief	push_back method
** @param	this the t_list object
** @param	data a void * pointer to store in the list
** @return	a t_state state of the function
**
** This function allocates memory and can fail.
*/
t_state		list_push_back(t_list *this, void *data);

/**
** @brief	pop_front method
** @param	this the t_list object
** @return	a t_state state of the function
**
** This function allocates memory and can fail.
*/
t_state		list_pop_front(t_list *this);

/**
** @brief	pop_back method
** @param	this the t_list object
** @return	a t_state state of the function
**
** This function allocates memory and can fail.
*/
t_state		list_pop_back(t_list *this);

/**
** @brief	empty method
** @param	this the t_list object
** @return	a t_bool value
*/
t_bool		list_empty(t_list *this);

/**
** @brief	size method
** @param	this the t_list object
** @return	a size_t value
*/
size_t		list_size(t_list *this);

/**
** @brief	front method
** @param	this the t_list object
** @return	a void * pointer to the data
*/
void		*list_front(t_list *this);

/**
** @brief	back method
** @param	this the t_list object
** @return	a void * pointer to the data
*/
void		*list_back(t_list *this);

/**
** @brief	assign method
** @param	this the t_list object
** @param	it is a t_list_iterator to an element of the list
** @param	data is a void * pointer to store
**
** The previous *data, if any, we'll be replaced.
*/
void		list_assign(t_list *this,
			    t_list_iterator it,
			    void *data);

/**
** @brief	assign method
** @param	this the t_list object
** @param	it is a t_list_iterator to an element of the list
** @param	data is a void * pointer to store
**
** The *data will be stored in a new node before the *it node.
*/
t_state		list_insert(t_list *this,
			    t_list_iterator it,
			    void *data);

/**
** @brief	remove method
** @param	this the t_list object
** @param	it is a t_list_iterator to an element of the list
** @param	data is a t_bool value, if TRUE *data will be free
*/
void		list_remove(t_list *this,
			    t_list_iterator it,
			    t_bool data);

/**
** @brief	clear method
** @param	this the t_list object
** @param	data is a t_bool value, if TRUE all nodes *data will be free
*/
void		list_clear(t_list *this);


/**
** @brief	begin method
** @param	this the t_list object
** @return	a t_list_iterator to the node
*/
t_list_iterator	list_begin(t_list *this);

/**
** @brief	end method
** @param	this the t_list object
** @return	a t_list_iterator to the node
*/
t_list_iterator	list_end(t_list *this);

#endif /* !T_LIST_H_ */
