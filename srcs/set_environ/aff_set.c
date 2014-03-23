/*
** aff_env.c for minishell2 in /u/all/jorge_d/cu/MINISHELL2
**
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
**
** Started on  Mon Jan 25 21:50:33 2010 dimitri jorge
** Last update Fri May 21 14:03:20 2010 dimitri jorge
*/

#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "builtins.h"
#include "set_environ.h"

int	aff_set(t_tree *tree)
{
  t_env	*parse;

  parse = gl_st.st_set;
  while (parse)
    {
      if (xwrite(tree->fd_out, parse->var, strlen(parse->var)) == -1)
	return (EXIT_FAILURE);
      if (xwrite(tree->fd_out, "\n", 1) == -1)
	return (EXIT_FAILURE);
      parse = parse->next;
    }
  return (EXIT_SUCCESS);
}
