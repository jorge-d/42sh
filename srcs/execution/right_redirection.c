/*
** right_redirection.c for 42sh in /u/all/jorge_d/cu/svn/parserll/trunk
** 
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
** 
** Started on  Thu May  6 16:46:50 2010 dimitri jorge
** Last update Sat May 22 13:24:26 2010 dimitri jorge
*/

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include "parserll.h"
#include "42sh.h"

static int	_open_file(char *name, int type)
{
  int		fd;

  fd = -1;
  if (type == IS_D_RIGHT)
    fd = open(name, O_WRONLY | O_CREAT | O_APPEND, 0644);
  else if (type == IS_RIGHT)
    fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if (fd == -1)
    perror("42sh : open");
  return (fd);
}

int		execute_right_redir_spe(t_tree *tree, t_shell *st_shell)
{
  int		fd;
  t_tree	*file;
  t_tree	*cmd;

  file = tree->right;
  cmd = tree->left;
  if (!file || !cmd)
    return (EXIT_FAILURE);
  if ((fd = _open_file(file->args[0], tree->type)) == -1)
    return (EXIT_FAILURE);
  set_fd_out(cmd, fd);
  return (execute_last_command(tree->left, st_shell));
}

int		right_redirection(t_tree *tree, t_shell *st_shell)
{
  int		fd;
  t_tree	*file;
  t_tree	*cmd;

  file = tree->right;
  cmd = tree->left;
  if (!file || !cmd)
    return (FATAL_ERROR);
  if ((fd = _open_file(tree->right->args[0], tree->type)) == -1)
    return (EXIT_FAILURE);
  set_fd_out(tree->left, fd);
  return (execute_it(tree->left, st_shell));
}
