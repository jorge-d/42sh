/*
** left_redirection.c for 42sh in /u/all/jorge_d/cu/svn/parserll/trunk/src/execution
** 
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
** 
** Started on  Thu May  6 16:48:18 2010 dimitri jorge
** Last update Thu May 13 17:46:21 2010 dimitri jorge
*/

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include "parserll.h"
#include "42sh.h"

static int	_open_file(char *name)
{
  int		fd;

  if (access(name, F_OK) == -1 || access(name, R_OK) == -1)
    {
      if (access(name, F_OK) == -1)
	fprintf(stderr, "%s: no such file or directory.\n", name);
      else
	fprintf(stderr, "%s: don't have the permission to read file.\n", name);
      return (-1);
    }
  fd = open(name, O_RDONLY);
  if (fd == -1)
    fprintf(stderr, "%s: Error : maybe targeted"
	    "directory doesn't exist.\n", name);
  return (fd);
}

int		spe_left(t_tree *tree, t_shell *st_shell)
{
  int		fd;
  char		**args;

  (void)st_shell;
  args = tree->right->args;
  if (!args || !args[0] || (fd = _open_file(args[0])) == -1)
    return (EXIT_FAILURE);
  set_fd_in(tree->left, fd);
  return (EXIT_SUCCESS);
}

int		left_redirection(t_tree *tree, t_shell *st_shell)
{
  int		fd;
  char		**args;

  args = tree->right->args;
  if (!args || !args[0] || (fd = _open_file(args[0])) == -1)
    return (EXIT_FAILURE);
  set_fd_in(tree->left, fd);
  return (execute_it(tree->left, st_shell));
}

