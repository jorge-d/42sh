/*
** bindkey.c for bindkey Builtins in /u/all/di-mar_j/cu/svn/42shsvn/trunk
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Fri May 21 13:09:52 2010 julien di-marco
** Last update Sun May 23 03:48:20 2010 julien di-marco
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	"42sh.h"
#include	"my_readline.h"
#include	"builtins.h"

#ifdef		__BINDKEY_ON__

int		bindkey_ptr(t_tree *tree, t_shell *shell)
{
  t_rl		*rl;
  char		**args;

  if (tree && (args = tree->args) && shell && (rl = &shell->rl))
    {
      if (args[0] && !args[1])
	return (show_bind(rl->bind));
      else if (args[1] && (strcmp(args[1], "-l") == 0))
	return (show_funcs());
      else if (args[1] && !args[2])
	fprintf(stderr, "42sh: bindkey: Syntax Error\n");
      else if (args[1] && args[2])
	return (bind_key(args[1], NULL, args[2], &rl->bind));
    }
  return (EXIT_FAILURE);
}

#endif		/* __BINDKEY_ON__ */
