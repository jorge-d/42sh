/*
** execute_pipes_2.c for 42sh in /u/all/jorge_d/cu/svn/42shsvn/trunk/srcs/execution
** 
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
** 
** Started on  Thu May 13 15:06:44 2010 dimitri jorge
** Last update Tue May 18 23:01:06 2010 dimitri jorge
*/

#include <sys/types.h>
#include <sys/uio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include "parserll.h"
#include "42sh.h"

int		execute_simple_pipe(t_tree *tree, t_shell *st_shell)
{
  int		fd[2];
  t_tree	*cmd;
  pid_t		pid;

  cmd = tree->right;
  if (xpipe(fd) == -1)
    return (FATAL_ERROR);
  set_fd_out(tree->right, fd[1]);
  set_fd_in(tree->left, fd[0]);
  if ((pid = xfork()) < 0)
    return (FATAL_ERROR);
  if (pid == 0)
    {
      if (is_builtin(cmd->args[0]))
	exit(check_builtins(st_shell, cmd));
      xclose(fd[0]);
      if (xdup2(cmd->fd_in, 0) == -1 || xdup2(cmd->fd_out, 1) == -1)
	exit(EXIT_FAILURE);
      xexecve(cmd->full_path, cmd->args, st_shell->my_env);
    }
  xclose(fd[1]);
  cmd->fd_out = 1;
  return (execution_chain(tree->left, st_shell));
}

void		init_first_pipe(t_tree *tree, t_shell *st_shell, int *fd)
{
  t_tree	*cmd;
  pid_t		pid;

  cmd = tree->right;
  if ((pid = xfork()) < 0)
    exit(EXIT_FAILURE);
  if (pid == 0)
    {
      if (is_builtin(cmd->args[0]))
	exit(check_builtins(st_shell, cmd));
      close(fd[0]);
      if (xdup2(cmd->fd_in, 0) == -1 || xdup2(cmd->fd_out, 1) == -1)
	exit(EXIT_FAILURE);
      xexecve(cmd->full_path, cmd->args, st_shell->my_env);
    }
  close(fd[1]);
  cmd->fd_out = 1;
  if (execution_chain(tree->left, st_shell) != EXIT_SUCCESS)
    exit(EXIT_FAILURE);
  exit(EXIT_SUCCESS);
}

void		init_first_pipe_spe(t_tree *tree, t_shell *st_shell, int *fd)
{
  t_tree	*cmd;
  pid_t		pid;

  if (spe_left(tree->right, st_shell) == EXIT_FAILURE || (pid = xfork()) == -1)
    exit(EXIT_FAILURE);
  cmd = tree->right->left;
  if (pid == 0)
    {
      if (is_builtin(cmd->args[0]))
	exit(check_builtins(st_shell, cmd));
      close(fd[0]);
      if (xdup2(cmd->fd_in, 0) == -1 || xdup2(cmd->fd_out, 1) == -1)
	exit(EXIT_FAILURE);
      xexecve(cmd->full_path, cmd->args, st_shell->my_env);
    }
  close(fd[1]);
  cmd->fd_out = 1;
  if (execution_chain(tree->left, st_shell) != EXIT_SUCCESS)
    exit(EXIT_FAILURE);
  exit(EXIT_SUCCESS);
}
