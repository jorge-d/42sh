/*
** builtin_ptr_2.c for 42sh in /u/all/jorge_d/cu/svn/42shsvn/trunk/srcs/builtins
** 
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
** 
** Started on  Thu Apr 22 16:36:57 2010 dimitri jorge
** Last update Thu May 20 21:36:59 2010 dimitri jorge
*/

#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "42sh.h"
#include "hreact.h"
#include "set_environ.h"
#include "builtins.h"
#include "alias_glob.h"

int	alias_ptr(t_tree *tree, t_shell *shell)
{
  return (add_new_alias(tree->args, shell));
}

int	unset_alias_ptr(t_tree *tree, t_shell *shell)
{
  return (unset_alias(tree->args, shell));
}

#ifdef	__HREACT_ON__

int	hreact_ptr(t_tree *tree, t_shell *shell)
{
  if (!tree->args[1])
    {
      usage_hreact();
      return (EXIT_FAILURE);
    }
  return (hreact_config(tree->args, shell));
}

#endif	/* !__HREACT_ON__ */
