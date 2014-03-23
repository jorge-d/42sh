/*
** builtin_ptr_2.c for 42sh in /u/all/jorge_d/cu/svn/42shsvn/trunk/srcs/builtins
**
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
**
** Started on  Thu Apr 22 16:36:57 2010 dimitri jorge
** Last update Sat May 22 13:34:47 2010 dimitri jorge
*/

#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "builtins.h"
#include "set_environ.h"

int		echo_ptr(t_tree *tree, t_shell *shell)
{
  int		i;
  char		**args;

  (void)shell;
  args = tree->args;
  i = 1;
  if (args[1])
    i = ((!strcmp(args[1], "-n")) ? 2 : 1);
  while (args[i])
    {
      if (args[i + 1])
	{
	  if ((write(tree->fd_out, args[i], strlen(args[i])) == -1)
	      || (write(tree->fd_out, " ", 1) == -1))
	    return (EXIT_FAILURE);
	}
      else if (write(tree->fd_out, args[i], strlen(args[i])) == -1)
	return (EXIT_FAILURE);
      i++;
    }
  if (!args[1] || (args[1] && strcmp(args[1], "-n")))
    if (write(tree->fd_out, "\n", 1) == -1)
      return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int		hist_ptr(t_tree *tree, t_shell *shell)
{
  t_hist	*st_hist;
  char		*buffer;

  st_hist = shell->st_hist;
  while (st_hist && st_hist->prev)
    st_hist = st_hist->prev;
  while (st_hist)
    {
      if (!(buffer = xcalloc((strlen(st_hist->line) + 128), sizeof(*buffer))))
	return (EXIT_FAILURE);
      sprintf(buffer, "    %d  %s\n", st_hist->i, st_hist->line);
      if ((write(tree->fd_out, buffer, strlen(buffer)) == -1))
	return (EXIT_FAILURE);
      free(buffer);
      st_hist = st_hist->next;
    }
  return (EXIT_SUCCESS);
}

int		set_ptr(t_tree *tree, t_shell *shell)
{
  (void)shell;
  return (set_new(tree->args, tree));
}

int		unset_ptr(t_tree *tree, t_shell *shell)
{
  (void)shell;
  return (unset_new(tree->args));
}
