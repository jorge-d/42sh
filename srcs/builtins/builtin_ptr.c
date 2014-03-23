/*
** builtin_ptr.c for 42sh in /u/all/jorge_d/cu/svn/42shsvn/trunk
** 
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
** 
** Started on  Wed Apr 21 16:29:15 2010 dimitri jorge
** Last update Fri May 21 13:38:00 2010 dimitri jorge
*/

#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "builtins.h"

int	chdir_ptr(t_tree *tree, t_shell *shell)
{
  char	**args;

  args = tree->args;
  (void)shell;
  if (my_tablen(args) > 2)
    fprintf(stderr, "%s : Too many arguments\n", args[0]);
  else if (my_tablen(args) == 1)
    return (my_cd("~", tree));
  else
    return (my_cd(args[1], tree));
  return (EXIT_FAILURE);
}

int	aff_env_ptr(t_tree *tree, t_shell *shell)
{
  (void)shell;
  return (aff_env(tree));
}

int	setenv_ptr(t_tree *tree, t_shell *shell)
{
  if (my_setenv(tree->args, tree) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  xfree(shell->my_env);
  shell->my_env = list_to_table(gl_st.st_env);
  return (EXIT_SUCCESS);
}

int	unsetenv_ptr(t_tree *tree,  t_shell *shell)
{
  if (my_unsetenv(tree->args) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  xfree(shell->my_env);
  shell->my_env = list_to_table(gl_st.st_env);
  return (EXIT_SUCCESS);
}

int	exit_ptr(t_tree *tree, t_shell *shell)
{
  (void)tree;
  shell->flag = ~SH_EXIT;
  return (FATAL_ERROR);
}
