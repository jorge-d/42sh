/*
** my_cd.c for 42sh in /u/all/jorge_d/cu/svn/42shsvn/trunk/srcs
**
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
**
** Started on  Fri May  7 18:11:34 2010 dimitri jorge
** Last update Sat May 22 14:39:36 2010 fares sabbagh
*/

#include <sys/types.h>
#include <sys/param.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "builtins.h"
#include "set_environ.h"
#include "42sh.h"

static char	*_apply_on_env(char *path, t_tree *tree)
{
  char		*new_pwd[4];
  char		*current;

  current = NULL;
  current = getcwd(current, MAXPATHLEN);
  if (xchdir(path) != -1)
    {
      new_pwd[0] = "setenv";
      new_pwd[1] = "PWD";
      new_pwd[2] = NULL;
      new_pwd[2] = getcwd(new_pwd[2], MAXPATHLEN);
      new_pwd[3] = NULL;
      set_new(new_pwd, tree);
      my_setenv(new_pwd, tree);
      xfree(new_pwd[2]);
      return (current);
    }
  xfree(current);
  return (NULL);
}

int		my_cd(char *path, t_tree *tree)
{
  char		*home;
  static char	*old_path = NULL;
  char		*tmp;

  tmp = NULL;
  home = get_env_from_list("HOME");
  if (!home)
    home = get_set_from_list("HOME");
  if (strcmp(path, "~") == 0 && home)
    tmp = _apply_on_env(home, tree);
  else
    {
      if (strcmp(path, "-") == 0)
	tmp = _apply_on_env(old_path, tree);
      else
	tmp = _apply_on_env(path, tree);
    }
  if (tmp == NULL)
    return (EXIT_FAILURE);
  xfree(old_path);
  old_path = tmp;
  return (EXIT_SUCCESS);
}
