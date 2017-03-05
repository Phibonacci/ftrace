/*
** usual.h for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sat Apr 19 19:55:26 2014 Jean Fauquenot
** Last update Sat Jun 28 17:58:39 2014 Jean Fauquenot
*/

/**
** @file	utils.h
** @brief	Basic
*/

#ifndef UTILS_H_
# define UTILS_H_

# include	<stdbool.h>
# include	<stdlib.h>

/**
** Usefull in case you would have to read an array.
** e.g. :
**  int *toto = {1, 2, 3, 4}
**  for (i = 0; i < LEN(toto); i++);
*/
# define LEN(x)			(sizeof(x) / sizeof(*x))

/**
** Usefull in case of function pointer.
** Instead of using a not so convenient void cast on a variable you don't need
** to use in the function, you can use the UNUSED() macro.
**
** e.g.:
**  We have a function pointer somewhere but we don't need arg1 in this
**  particular function.
**  int	function_used_as_ptr(int UNUSED(arg1), int arg2, int arg3) {}
**  The arg1 will not be be considered during the compilation and you will not
**  either be able to use it in the scope of the function (obviously).
**
** Explain the macro:
**  - ifdef UNUSED		: if the UNUSED macro has been defined before.
**  - elif defined(__GNUC__)	: else if we are using the GNUC licence of GCC.
**  - define UNUSED(x) UNUSED_ ## x __attribute__((unused)) :
**				  then UNUSED(x) used the gcc specific defined
**				  macro that ignore x variable declaration.
**  - elif defined(__LCLINT__)
**     define UNUSED(x)		/ *@unused@* / x :
**				  same thing for LCLINT licence of GCC
**  - else
**     define UNUSED(x)		x :
**				  else (if another licence or compilater),
**				  ignore the define
*/
# ifdef UNUSED
# elif defined(__GNUC__)
#  define UNUSED(x)		UNUSED_ ## x __attribute__((unused))
# elif defined(__LCLINT__)
#  define UNUSED(x)		/*@unused@*/ x
# else
#  define UNUSED(x)		x
# endif

/**
** Used for t_state so we limit the risk of overwriting an existing value of
** EXIT_SUCCESS, EXIT_FAILURE on any system.
*/
# define STATE_ID	5748

/**
** Return state of functions
** You should only need SUCCESS and FAILURE unless you have to handle different
** level of failure.
** e.g.: server could not read on client → we have to disconnect the client but
**       the server must not stop.
*/
typedef enum		e_state
  {
    SUCCESS = EXIT_SUCCESS,
    FAILURE = EXIT_FAILURE,
    FAILURE_L1 = STATE_ID + 1,
    FAILURE_L2 = STATE_ID + 2
  }			t_state;

/**
** Simple boolean implementation
*/
typedef enum		e_bool
  {
    FALSE,
    TRUE
  }			t_bool;

#endif /* !UTILS_H_ */
