/*
** readstd.c for mysh in /u/all/strzel_a/cu/rendu/c/my_ls
**
** Made by alexandre strzelewicz
** Login   <strzel_a@epitech.net>
**
** Started on  Mon Dec  7 15:08:13 2009 alexandre strzelewicz
** Last update Thu Jun  3 12:18:17 2010 dimitri jorge
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "42sh.h"
#include "alias_glob.h"

static void	fuse(char **cmd, char **new_cmd, int *j)
{
  int		i;

  i = 0;
  while (cmd[i])
    {
      if (!(new_cmd[*j] = xcalloc((strlen(cmd[i]) + 2), sizeof(*new_cmd))))
	return ;
      strcpy(new_cmd[(*j)++], cmd[i++]);
    }
}

static char	**forge_processing(char **cmd, char **to_insert,
				   char **end, int *i)
{
  char		**new_cmd;
  int		j;
  int		k;

  j = 0;
  k = 0;
  while (to_insert[k++]);
  while (cmd[j++]);
  if (!(new_cmd = xcalloc((k + j + 2), sizeof(*new_cmd))))
    return (NULL);
  k = 0;
  while (cmd[k] && k < *i)
    {
      if (!(new_cmd[k] = xcalloc((my_strlen(cmd[k]) + 2), sizeof(*new_cmd))))
	return (NULL);
      strcpy(new_cmd[k], cmd[k]);
      k++;
    }
  j = k;
  fuse(to_insert, new_cmd, &j);
  fuse(end, new_cmd, &j);
  new_cmd[j] = NULL;
  return (new_cmd);
}

char		**insert_in_tab(char **cmd, char **to_insert, int *i)
{
  char		**end;
  char		**new_cmd;
  int		j;
  int		k;

  k = 0;
  j = *i;
  while (cmd[j++]);
  if (!(end = xcalloc((j + 2), sizeof(*end))))
    return (NULL);
  j = *i + 1;
  while (cmd[j])
    {
      if (!(end[k] = xcalloc((strlen(cmd[j]) + 2), sizeof(*end))))
	{
	  free_table(end);
	  return (NULL);
	}
      strcpy(end[k++], cmd[j++]);
    }
  end[k] = NULL;
  new_cmd = forge_processing(cmd, to_insert, end, i);
  free_table(end);
  free_table(cmd);
  return (new_cmd);
}
