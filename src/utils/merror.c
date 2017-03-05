/*
** merror.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Wed May  7 15:20:56 2014 Jean Fauquenot
** Last update Sat Jun 28 19:41:12 2014 Jean Fauquenot
*/

#include "merror.h"

#include <errno.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>

/*
** Print a message on the error output of the following form:
** "a.out: error: error message: errno message\n"
** if errno if not set then merror only prints:
** "a.out: error: error message\n"
**
** The generic error message should be DEFINE in merror.h
**
** If you want to use any more parameter than the error message, please
** be careful to your output (file name etc...).
**
** e.g.:
**  "a.out: error: could not write in the file: toto.txt: \
** Insufficient permission\n"
**  should be called with :
**  char *filename = "toto.txt";
**
**  merror("%s: %s", E_WRFILE, filename);
*/
t_state		merror(char *format, ...)
{
  va_list	ap;

  fprintf(stderr, "%s", EHEADER);
  va_start(ap, format);
  vfprintf(stderr, format, ap);
  va_end(ap);
  if (errno)
    fprintf(stderr, ": %s", strerror(errno));
  fprintf(stderr, "\n");
  errno = 0;
  return (FAILURE);
}
