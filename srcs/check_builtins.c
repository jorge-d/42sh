/*
** check_builtins.c for 42sh in /u/all/jorge_d/cu/svn/42shsvn/trunk/srcs
** 
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
** 
** Started on  Fri May  7 18:11:08 2010 dimitri jorge
** Last update Fri May 21 13:25:32 2010 julien di-marco
*/

#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "42sh.h"
#include "builtins.h"
#include "alias_glob.h"

t_builtins	gl_builtin_ptr[] = {
  {"cd", chdir_ptr},
  {"chdir", chdir_ptr},
  {"env", aff_env_ptr},
  {"setenv", setenv_ptr},
  {"export", setenv_ptr},
  {"unsetenv", unsetenv_ptr},
  {"exit", exit_ptr},
  {"quit", exit_ptr},
  {"echo", echo_ptr},
  {"history", hist_ptr},
  {"set", set_ptr},
  {"unset", unset_ptr},
  {"alias", alias_ptr},
  {"unalias", unset_alias_ptr},
#ifdef	__HREACT_ON__
  {"hreact", hreact_ptr},
#endif	/* !__HREACT_ON__ */
#ifdef	__BINDKEY_ON__
  {"bindkey", bindkey_ptr},
#endif	/* !__BINDKEY_ON__ */
  {NULL, 0}
};

int	check_builtins(t_shell *ptr, t_tree *tree)
{
  char	**args;
  int	i;

  i = 0;
  args = tree->args;
  while (gl_builtin_ptr[i].builtin_cmd)
    {
      if (!(my_strcmp(gl_builtin_ptr[i].builtin_cmd, args[0])))
	return (gl_builtin_ptr[i].ptr_func(tree, ptr));
      i++;
    }
  return (EXIT_FAILURE);
}

int	is_builtin(char *cmd)
{
  int	i;

  i = 0;
  if (cmd)
    while (gl_builtin_ptr[i].builtin_cmd)
      {
	if (!(my_strcmp(gl_builtin_ptr[i].builtin_cmd, cmd)))
	  return (1);
	i++;
      }
  return (0);
}
