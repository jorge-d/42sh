/*
** readstd.c for mysh in /u/all/strzel_a/cu/rendu/c/my_ls
** 
** Made by alexandre strzelewicz
** Login   <strzel_a@epitech.net>
** 
** Started on  Mon Dec  7 15:08:13 2009 alexandre strzelewicz
** Last update Thu May 20 00:57:27 2010 alexandre strzelewicz
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <glob.h>
#include "42sh.h"
#include "alias_glob.h"

int		is_it_glob(char *seq)
{
  while (*seq)
    {
      if (*seq && (*seq == '*' ||
		   *seq == '[' ||
		   *seq == '{' ||
		   *seq == '?'))
	return (RT_SUCCESS);
      seq++;
    }
  return (RT_FAILURE);
}

static char	**modify_cmd(char **cmd, int *i)
{
  glob_t	st_glob;
  char		**new_cmd;

  st_glob.gl_offs = 0;
  if (glob(cmd[*i], GLOB_MARK | GLOB_QUOTE, NULL, &st_glob) != 0)
    return (cmd);
  if (!(new_cmd = insert_in_tab(cmd, st_glob.gl_pathv, i)))
    return (NULL);
  *i += my_tablen(st_glob.gl_pathv) - 1;
  globfree(&st_glob);
  return (new_cmd);
}

char		**operate_globbing(char **cmd)
{
  int		i;
  char		**new_cmd;

  i = 0;
  new_cmd = cmd;
  while (new_cmd[i])
    {
      if (is_it_glob(new_cmd[i]))
	if (!(new_cmd = modify_cmd(new_cmd, &i)))
	  return (NULL);
      i++;
    }
  if (new_cmd)
    return (new_cmd);
  return (cmd);
}
