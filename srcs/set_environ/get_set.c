/*
** get_env.c for minishell in /u/all/jorge_d/cu/MINISHELL2
**
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
**
** Started on  Mon Jan 25 18:56:12 2010 dimitri jorge
** Last update Sat May 22 14:36:24 2010 fares sabbagh
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "42sh.h"
#include "set_environ.h"

static char	*concat_path(char *p1, char *p2)
{
  char		*new_val;

  if (!(new_val = xcalloc((strlen(p1) + strlen(p2) + 4), sizeof(*new_val))))
    return (NULL);
  strcpy(new_val, p1);
  strcat(new_val, p2);
  return (new_val);
}

static char	*transform_full_path(char *val)
{
  char		*path;
  char		*new_val;

  new_val = NULL;
  path = NULL;
  if (val && *val && *val == '~')
    {
      if ((path = get_env_from_list("HOME")))
	new_val = concat_path(path, val + 1);
    }
  else if (val && *val && *val == '.')
    {
      if ((path = get_env_from_list("PWD")))
	new_val = concat_path(path, val + 1);
    }
  if (new_val)
    return (new_val);
  return (NULL);
}

char		*set_it(char *var, char *val)
{
  char		*res;
  int		len;
  char		*new_val;
  int		flag;

  flag = 0;
  new_val = NULL;
  if (*val && (*val == '~' || *val == '.'))
    new_val = transform_full_path(val);
  if (!(new_val))
    {
      flag = 1;
      new_val = val;
    }
  len = my_strlen(var) + my_strlen(new_val) + 3;
  if (!(res = xcalloc(len, sizeof(*res))))
    return (NULL);
  res = my_strcpy(res, var);
  res = my_strcat(res, "=");
  if (new_val)
    res = my_strcat(res, new_val);
  if (flag == 0)
    xfree(new_val);
  return (res);
}

char		*get_set_from_list(char *var)
{
  char		*value;
  t_env		*tmp;

  tmp = gl_st.st_set;
  while ((tmp) && my_strcmp(tmp->var, var) != '=')
    tmp = tmp->next;
  if (tmp == NULL)
    return (NULL);
  value = tmp->var;
  return (&value[my_strlen(var) + 1]);
}
