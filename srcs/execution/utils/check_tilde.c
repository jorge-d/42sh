/*
** check_tilde.c for 42sh in /u/all/jorge_d/cu/svn/42shsvn/trunk
** 
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
** 
** Started on  Sat May 15 10:50:53 2010 dimitri jorge
** Last update Sat May 22 13:27:48 2010 dimitri jorge
*/

#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include "parserll.h"
#include "set_environ.h"
#include "42sh.h"

int	check_tilde(char *s)
{
  if (strncmp(s, "~", 1) == 0)
    return (1);
  return (0);
}

int	concat_tilde(char **args, t_tree *tree, int i)
{
  char	*buf;
  char	*home;
  int	len;

  home = get_env_from_list("HOME");
  if (!home)
    home = get_set_from_list("HOME");
  if (!home)
    return (EXIT_FAILURE);
  len = my_strlen(args[i]) + my_strlen(home);
  buf = xcalloc((len + 1), sizeof(*buf));
  if (!buf)
    return (FATAL_ERROR);
  buf = strcpy(buf, home);
  buf = strcat(buf, args[i] + 1);
  free(tree->args[i]);
  tree->args[i] = buf;
  return (EXIT_SUCCESS);
}
