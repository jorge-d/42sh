/*
** get_env.c for minishell in /u/all/jorge_d/cu/MINISHELL2
** 
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
** 
** Started on  Mon Jan 25 18:56:12 2010 dimitri jorge
** Last update Sat May 22 13:32:53 2010 dimitri jorge
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "42sh.h"

char	*set_value(char *var, char *value)
{
  char	*res;
  int	len;

  len = my_strlen(var) + my_strlen(value) + 3;
  res = xcalloc(len, sizeof(*res));
  if (!res)
    return (NULL);
  res = my_strcpy(res, var);
  res = my_strcat(res, "=");
  if (value)
    res = my_strcat(res, value);
  return (res);
}

char	*get_env_from_list(char *var)
{
  char	*value;
  t_env	*tmp;

  tmp = gl_st.st_env;
  while ((tmp) && my_strcmp(tmp->var, var) != '=')
    tmp = tmp->next;
  if (tmp == NULL)
    return (NULL);
  value = tmp->var;
  return (&value[my_strlen(var) + 1]);
}
