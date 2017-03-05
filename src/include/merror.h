/*
** merror.h for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Wed May  7 15:20:52 2014 Jean Fauquenot
** Last update Sun Jun 29 21:57:57 2014 Jean Fauquenot
*/

#ifndef MERROR_H_
# define MERROR_H_

# include		"utils.h"

# define BIN		"ftrace"

# define USAGE		"Usage : ./" BIN

# define EHEADER	BIN ": error: "

# define E_PROTO	"Could not get protocol datas"
# define E_ARGC		"Invalid arguments"
# define E_ARGC_U	"Not enough arguments"
# define E_ARGC_O	"Too many arguments"
# define E_SEND		"Could not send data to the socket"
# define E_RECV		"Client disconnection"
# define E_CLOSE	"Could not close the file"
# define E_SELECT	"Could not get the state of the file descriptors"
# define E_ACCEPT	"Could not accept the new client"
# define E_ALLOC	"Could not allocate memory"
# define E_OPEN		"Could not open the file"
# define E_WRFILE	"Could not write in the file"
# define E_SOCKET	"Could not open the socket"
# define E_BIND		"Could not bind the name to the socket"
# define E_LISTEN	"Could not listen to the socket"
# define E_NOTINLIST	"Could not find the element in the list (ignored)"
# define E_READ		"Could not read"
# define E_EXECVP	"Could not execute binary"
# define E_FORK		"Could not fork"
# define E_KILL		"Could not send signal"
# define E_SIGNAL	"Could not handle the signal"
# define E_PTRACE_TRACEME	"Could not trace process"
# define E_PTRACE_GETREGS	"Could not get registers"
# define E_PTRACE_SINGLESTEP	"Could not move a single step"
# define E_PTRACE_ATTACH	"Could not attach to the process"
# define E_PTRACE_DETACH	"Could not detach the process"

t_state		merror(char *, ...);

#endif /* !MERROR_H_ */
