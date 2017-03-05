/*
** t_stack.h for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Mon Jun 16 16:42:42 2014 Jean Fauquenot
** Last update Sat Jun 28 17:16:02 2014 Jean Fauquenot
*/

#ifndef T_STACK_H_
# define T_STACK_H_

# include "utils.h"

typedef struct		s_stack_elem
{
  void			*data;
  struct s_stack_elem	*next;
}			t_stack_elem;

typedef struct		s_stack t_stack;

struct			s_stack
{
  size_t		_size;
  t_stack_elem		*_top;

  t_state		(*push)(t_stack *this, void *data);
  t_state		(*pop)(t_stack *this);
  size_t		(*size)(t_stack *this);
  t_bool		(*empty)(t_stack *this);
  void			*(*top)(t_stack *this);
  void			(*clear)(t_stack *this);
};

/**
** @brief	t_stack class constructor
** @see		t_stack
** @return	a t_stack allocated and initialized
**
** This function allocates memory and can fail.
*/
t_stack		*stack_new(void);
t_state		stack_init(t_stack *this);
void		stack_delete(t_stack *this);
void		stack_destroy(t_stack *this);

/**
** @brief	allocates a new member of the stack and store data in it
** @param	this the t_stack object
** @param	a pointer to anything you want to store in the stack
** @return	a t_state SUCCESS or FAILURE
**
** This function allocates memory and can fail.
*/
t_state		stack_push(t_stack *this, void *data);

/**
** @brief	removes and free the top element of the stack (data not free)
** @param	this the t_stack object
** @return	a t_state SUCCESS or FAILURE if *stack is NULL
*/
t_state		stack_pop(t_stack *this);

/**
** @brief	returns the size of the stack
** @param	this the t_stack object
** @return	a size_t with the size of the stack
*/
size_t		stack_size(t_stack *this);

/**
** @brief	returns the state of the stack
** @param	this the t_stack object
** @return	a t_bool TRUE if the stack is empty, false otherwise
*/
t_bool		stack_empty(t_stack *this);

/**
** @brief	returns the data of the top element of the stack
** @param	this the t_stack object
** @return	the void *data of the top element or NULL if stack is NULL
*/
void		*stack_top(t_stack *this);

/**
** @brief	clear the stack
** @param	this the t_stack object
*/
void		stack_clear(t_stack *this);

#endif /* !T_STACK_H_ */
