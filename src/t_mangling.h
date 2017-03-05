/*
** t_mangling.h for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sun Jul  6 21:06:16 2014 Jean Fauquenot
** Last update Sun Jul  6 21:06:17 2014 Jean Fauquenot
*/

#ifndef UNMANGLE_H_
# define UNMANGLE_H_

typedef struct	s_unmangle
{
  char const	*name;
  char		outputbuf[128];
  unsigned int	outputend;
  char		*lastclassname;
}		t_unmangle;

char		*unmangle(char const *name);
char const	*unmangle_handleprefix(t_unmangle *data, char const *);

#endif /* !UNMANGLE_H_ */
