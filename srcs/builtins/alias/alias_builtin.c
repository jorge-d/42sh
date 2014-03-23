/*
** alias_funcs.c for sdf in /u/epitech_2014/strzel_a/cu
**
** Made by alexandre strzelewicz
** Login   <strzel_a@epitech.net>
**
** Started on  Wed May 12 15:52:58 2010 alexandre strzelewicz
** Last update Thu Jun  3 12:14:53 2010 dimitri jorge
*/

#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "42sh.h"
#include "set_environ.h"
#include "parserll.h"
#include "alias_glob.h"

static void	disp_alias(t_alias *st_alias)
{
  while (st_alias)
    {
      printf("%-15s %s\n", st_alias->alias, st_alias->cmd);
      st_alias = st_alias->next;
    }
}

static void	find_remove_alias(char *alias, t_alias **st_alias)
{
  t_alias	*truc;
  t_alias	*tmp;

  tmp = *st_alias;
  if (alias && tmp)
    {
      if (strcmp(tmp->alias, alias) == 0)
	{
	  truc = (*st_alias);
	  (*st_alias) = (*st_alias)->next;
	  xfree(truc->cmd);
	  xfree(truc->alias);
	  xfree(truc);
	  return ;
	}
      while (tmp)
	{
	  if (strcmp(tmp->alias, alias) == 0)
	    {
	      remove_alias_from_list(&tmp);
	      return ;
	    }
	  tmp = tmp->next;
	}
    }
}

int		start_alias(char **cmd, t_shell *st_shell)
{
  if (cmd && !cmd[1] && st_shell)
    {
      disp_alias(st_shell->st_alias);
      return (EXIT_SUCCESS);
    }
  else if (cmd && cmd[1] && (strcmp(cmd[1], "-h") == 0))
    {
      fprintf(stderr, "Usage: which-command=whence\n");
      return (EXIT_SUCCESS);
    }
  return (EXIT_FAILURE);
}

int		add_new_alias(char **cmd, t_shell *st_shell)
{
  char		**wordtab;
  char		buf[MAX_ALIAS_NAME + 2];
  char		buf2[MAX_ALIAS_SIZE + 2];
  int		i;

  if ((i = start_alias(cmd, st_shell)) == EXIT_SUCCESS)
    return (i);
  if (st_shell && cmd && (wordtab = parse_str(cmd[1], '=')))
    {
      if (!wordtab[1])
	{
	  fprintf(stderr, "Usage: which-command=whence\n");
	  return (EXIT_FAILURE);
	}
      if (st_shell->st_alias)
	find_remove_alias(wordtab[0], &(st_shell->st_alias));
      memset(buf, 0, MAX_ALIAS_NAME + 2);
      memset(buf2, 0, MAX_ALIAS_SIZE + 2);
      strncpy(buf, wordtab[0], MAX_ALIAS_NAME);
      strncpy(buf2, wordtab[1], MAX_ALIAS_SIZE);
      put_alias_in_list(&(st_shell->st_alias), buf, buf2);
      free_table(wordtab);
      return (EXIT_SUCCESS);
    }
  return (EXIT_FAILURE);
}

int		unset_alias(char **cmd, t_shell *st_shell)
{
  if (!cmd[1])
    {
      fprintf(stderr, "Usage = unset alias \"alias\"\n");
      return (EXIT_FAILURE);
    }
  find_remove_alias(cmd[1], &(st_shell->st_alias));
  return (EXIT_FAILURE);
}
