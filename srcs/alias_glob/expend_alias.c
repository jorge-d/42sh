/*
** readstd.c for mysh in /u/all/strzel_a/cu/rendu/c/my_ls
** 
** Made by alexandre strzelewicz
** Login   <strzel_a@epitech.net>
** 
** Started on  Mon Dec  7 15:08:13 2009 alexandre strzelewicz
** Last update Thu Jun  3 12:35:05 2010 dimitri jorge
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "42sh.h"
#include "alias_glob.h"

char	**expend_alias(char **cmd, t_alias *st_alias)
{
  int	i;
  char	**new_cmd;
  char	**buf;

  new_cmd = cmd;
  while (st_alias)
    {
      i = 0;
      if (st_alias->alias && cmd && cmd[0] &&
	  strcmp(st_alias->alias, cmd[0]) == 0)
	{
	  if (!(buf = parse_str(st_alias->cmd, ' ')))
	    return (cmd);
	  if (!(new_cmd = insert_in_tab(cmd, buf, &i)))
	    return (NULL);
	  free_table(buf);
	  return (new_cmd);
	}
      st_alias = st_alias->next;
    }
  return (new_cmd);
}
