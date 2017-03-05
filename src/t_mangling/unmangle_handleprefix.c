/*
** unmangle_handleprefix.c for ftrace in /home/leduc_p/AUSP_ftrace/src
**
** Made by paul-maxime leduc
** Login   <leduc_p@epitech.net>
**
** Started on  Sun Jul  6 19:13:17 2014 paul-maxime leduc
** Last update Sun Jul  6 19:13:24 2014 paul-maxime leduc
*/

#include <string.h>
#include <stdio.h>
#include "t_mangling.h"

char const	*unmangle_handleprefix(t_unmangle *data, char const *start)
{
  char const	*rt;

  rt = start;
  while (rt[0])
    {
      if (rt[0] == 'D')
	{
	  snprintf(data->outputbuf + data->outputend,
		   sizeof(data->outputbuf) - data->outputend,
		   "::~%s", data->lastclassname);
	  return ("");
	}
      if (rt[0] == 'C')
	{
	  snprintf(data->outputbuf + data->outputend,
		   sizeof(data->outputbuf) - data->outputend,
		   "::%s", data->lastclassname);
	  return ("");
	}
      if ((rt[0] >= '0' && rt[0] <= '9') || rt[0] == 'E')
	return (rt);
      ++rt;
    }
  return (rt);
}
