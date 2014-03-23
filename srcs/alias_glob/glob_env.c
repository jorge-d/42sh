/*
** readstd.c for mysh in /u/all/strzel_a/cu/rendu/c/my_ls
** 
** Made by alexandre strzelewicz
** Login   <strzel_a@epitech.net>
** 
** Started on  Mon Dec  7 15:08:13 2009 alexandre strzelewicz
** Last update Sat May 22 13:41:08 2010 dimitri jorge
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "42sh.h"
#include "alias_glob.h"

int		nmatch(char *s1, char *s2)
{
  int		i;
  int		ret;

  i = 0;
  ret = 0;
  if (!*s1 && !*s2)
    return (1);
  else if (*s2 != '\0')
    {
      if (*s2 == '*')
	{
	  while (s1[i] != '\0')
	    ret += nmatch(s1 + i++, s2 + 1);
	  ret += nmatch(s1 + i, s2 + 1);
	}
      else if (*s1 == *s2)
	ret += nmatch(s1 + 1, s2 + 1);
    }
  return (ret);
}

static int	list_size(t_env *st_env)
{
  int		i;

  i = 0;
  while (st_env)
    {
      i++;
      st_env = st_env->next;
    }
  return (i);
}

char		**get_env_glob(char *seq, t_env *st_env)
{
  char		**buf;
  char		**ret;
  int		j;

  j = 0;
  ret = NULL;
  if (!(ret = xcalloc((list_size(st_env) + 2), sizeof(*ret))))
    return (NULL);
  while (st_env)
    {
      buf = parse_str(st_env->var, '=');
      if (nmatch(buf[0], seq))
	{
	  if (!(ret[j] = xcalloc((strlen(buf[1]) + 2), sizeof(*ret))))
	    return (NULL);
	  strcpy(ret[j], buf[0]);
	  j++;
	}
      free_table(buf);
      st_env = st_env->next;
    }
  ret[j] = NULL;
  return (ret);
}

static char	**modify_cmd(char **cmd, int *i, t_env *st_env)
{
  char		**buf;
  char		**new_cmd;

  if (!(buf = get_env_glob(cmd[*i], st_env)))
    return (cmd);
  if (!(new_cmd = insert_in_tab(cmd, buf, i)))
    return (NULL);
  *i += my_tablen(buf);
  free_table(buf);
  return (new_cmd);
}

char		**operate_env_globbing(char **cmd, t_env *st_env)
{
  int		i;
  char		**new_cmd;

  new_cmd = cmd;
  i = 0;
  while (new_cmd[i])
    {
      if (is_it_glob(new_cmd[i]))
	new_cmd = modify_cmd(new_cmd, &i, st_env);
      i++;
    }
  if (new_cmd)
    return (new_cmd);
  return (cmd);
}
