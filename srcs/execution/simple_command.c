/*
** simple_command.c for 42sh in /u/all/jorge_d/cu/svn/42shsvn/trunk
**
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
**
** Started on  Wed May 12 15:55:25 2010 dimitri jorge
** Last update Sat May 22 15:08:46 2010 alexandre strzelewicz
*/

#include <sys/types.h>
#include <sys/uio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include "parserll.h"
#include "42sh.h"

int		execute_simple_command(t_tree *tree, t_shell *st_shell)
{
  int           flag;
  int		statut;
  pid_t         pid;

  statut = 0;
  if (tree && (flag = prepare_command(tree, st_shell)) != EXIT_SUCCESS)
    return (flag);
  if (is_builtin(tree->args[0]))
    return (check_builtins(st_shell, tree));
  if ((pid = xfork()) == 0)
    {
      reset_line(st_shell);
      xdup2(tree->fd_in, 0);
      xdup2(tree->fd_out, 1);
      execve(tree->full_path, tree->args, st_shell->my_env);
    }
  else if (pid > 0)
    {
      if (waitpid(pid, &statut, 0) == -1)
	perror("Waitpid");
      return (write_statut(statut));
    }
  return (FATAL_ERROR);
}
