/*
** ftrace_signal.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sat Jun 28 22:26:48 2014 Jean Fauquenot
** Last update Sat Jun 28 22:32:38 2014 Jean Fauquenot
*/

#include "t_ftrace.h"
#include "merror.h"

#include <sys/signal.h>

static int	g_signal;

static void	signal_interrupt(int signum)
{
  g_signal = signum;
}

int			ftrace_init_signal(void)
{
  struct sigaction	action;

  action.sa_handler = signal_interrupt;
  sigemptyset(&action.sa_mask);
  action.sa_flags = 0;
  if (sigaction(SIGINT, &action, NULL) == -1)
    {
      merror(E_SIGNAL, SIGINT);
      return (-1);
    }
  return (0);
}

int	ftrace_last_signal(void)
{
  int	sig;

  sig = g_signal;
  g_signal = 0;
  return (sig);
}
