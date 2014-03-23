/*
** unset_quotes.c for 42sh in /u/all/jorge_d/cu/svn/parserll/trunk/src/execution
** 
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
** 
** Started on  Mon May 10 16:05:58 2010 dimitri jorge
** Last update Sat May 22 13:27:06 2010 dimitri jorge
*/

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "parserll.h"
#include "42sh.h"

static int	there_are_quotes(char *s)
{
  int		i;

  i = 0;
  while (s[i])
    {
      if (s[i] == '\'' || s[i] == '\"' || s[i] == '`')
	return (1);
      i++;
    }
  return (0);
}

static char	*unset_quotes(char *old)
{
  char		*new;
  int		flag;
  int		i;
  int		j;

  i = 0;
  j = 0;
  flag = 0;
  if (!(new = xcalloc((my_strlen(old) + 1), sizeof(*new))))
    return (NULL);
  while (old[i])
    {
      if (old[i] == '\'' || old[i] == '`' || old[i] == '\"')
	flag = check_quote_flag(old[i], flag);
      if ((flag == 0 && old[i] != '\'' && old[i] != '\"' && old[i] != '`') ||
	  (flag == 1 && old[i] != '\'') || (flag == 2 && old[i] != '\"') ||
	  (flag == 3 && old[i] != '`'))
	new[j++] = old[i];
      i++;
    }
  new[j] = '\0';
  return (new);
}

void	remove_sequence_quote(char **cmd, t_tree *tree)
{
  int	i;
  char	*tmp;

  i = 0;
  tmp = NULL;
  while (cmd[i])
    {
      if (there_are_quotes(cmd[i]))
	{
	  if ((tmp = unset_quotes(cmd[i])))
	    {
	      free(cmd[i]);
	      cmd[i] = tmp;
	    }
	}
      i++;
    }
  tree->args = cmd;
}
