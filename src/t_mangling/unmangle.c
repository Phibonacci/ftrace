/*
** unmangle.c for  in /home/hengrui/project/SystemUnix/AUSP_ftrace
**
** Made by hengrui
** Login   <hengrui@epitech.net>
**
** Started on  Sun Jul  6 19:57:15 2014 hengrui
** Last update Sun Jul  6 19:57:32 2014 hengrui
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "t_mangling.h"

static char const	*decode_onename(t_unmangle *data, char const *start)
{
  char const		*format;
  long int		len;
  char			*end;
  int			rt;

  len = strtol(start, &end, 10);
  if (data->outputend == 0)
    format = "%s";
  else
    format = "::%s";
  start = end;
  end = strndup(end, len);
  if ((rt = snprintf(data->outputbuf + data->outputend,
		     sizeof(data->outputbuf) - data->outputend,
		     format, end)))
    {
      data->outputend += rt;
    }
  free(data->lastclassname);
  data->lastclassname = end;
  return (start + len);
}

static char	*unmangle_process(t_unmangle *data)
{
  char const	*name;

  name = data->name + strlen("Z");
  while (name[0] && name[0] != 'E')
    {
      name = unmangle_handleprefix(data, name);
      if (name[0] >= '0' && name[0] <= '9')
	name = decode_onename(data, name);
    }
  free(data->lastclassname);
  return (strdup(data->outputbuf));

}

char		*unmangle(char const *name)
{
  t_unmangle	data;

  memset(&data, 0, sizeof(data));
  data.name = name;
  if (strncmp(name, "_Z", 2) != 0)
    return (strdup(name));
  return (unmangle_process(&data));
}
