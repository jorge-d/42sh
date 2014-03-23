/*
** execute_pipes.c for 42sh in /u/all/jorge_d/cu/svn/parserll/trunk
** 
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
** 
** Started on  Thu May  6 16:47:25 2010 dimitri jorge
** Last update Sat May 22 13:25:14 2010 dimitri jorge
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

int	execute_last_command(t_tree *tree, t_shell *st_shell)
{
  int	statut;
  pid_t	pid;

  if (is_builtin(tree->args[0]))
    return (check_builtins(st_shell, tree));
  if ((pid = xfork()) == 0)
    {
      xdup2(tree->fd_in, 0);
      xdup2(tree->fd_out, 1);
      xexecve(tree->full_path, tree->args, st_shell->my_env);
    }
  else if (pid > 0)
    {
      if (waitpid(pid, &statut, 0) == -1)
	perror("Waitpid() :");
      else
	return (write_statut(statut));
    }
  return (FATAL_ERROR);
}

int	execution_chain(t_tree *tree, t_shell *st_shell)
{
  if (tree->type == IS_PIPE)
    return (execute_simple_pipe(tree, st_shell));
  else if (tree->type == IS_CMD)
    return (execute_last_command(tree, st_shell));
  else if (tree->type == IS_D_RIGHT || tree->type == IS_RIGHT)
    return (execute_right_redir_spe(tree, st_shell));
  return (0);
}

int	execute_pipe_start(t_tree *tree, t_shell *st_shell)
{
  int	flag;
  int	statut;
  int	fd[2];
  pid_t	pid;

  if ((flag = prepare_all_commands(tree, st_shell)) != EXIT_SUCCESS)
    return (flag);
  if ((pid = xfork()) == 0)
    {
      if (xpipe(fd) == -1)
	exit(EXIT_FAILURE);
      reset_line(st_shell);
      set_fd_out(tree->right, fd[1]);
      set_fd_in(tree->left, fd[0]);
      if (tree->right->type == IS_CMD)
	init_first_pipe(tree, st_shell, fd);
      init_first_pipe_spe(tree, st_shell, fd);
    }
  else if (pid > 0)
    {
      if (waitpid(-1, &statut, 0) == -1)
	perror("Waitpid() :");
      return (write_statut(statut));
    }
  return (FATAL_ERROR);
}
