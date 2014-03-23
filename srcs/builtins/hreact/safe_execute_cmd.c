/*
** safe_execute_cmd.c for  in /u/epitech_2014/strzel_a/svn/42shsvn/trunk
**
** Made by alexandre strzelewicz
** Login   <strzel_a@epitech.net>
**
** Started on  Sat May 22 16:20:44 2010 alexandre strzelewicz
** Last update Sat May 22 19:41:01 2010 dimitri jorge
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/param.h>
#include <sys/types.h>
#include <dirent.h>
#include "42sh.h"
#include "parserll.h"
#include "builtins.h"
#include "set_environ.h"
#include "my_readline.h"
#include "hreact.h"

#ifdef		__HREACT_ON__

static int	execute_simple_command2(t_tree *tree, t_shell *st_shell)
{
  int		flag;
  int		statut;
  pid_t		pid;

  statut = 0;
  if (tree && (flag = prepare_command(tree, st_shell)) != EXIT_SUCCESS)
    return (flag);
  if (is_builtin(tree->args[0]))
    return (check_builtins(st_shell, tree));
  if ((pid = xfork()) == 0)
    {
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

void		safe_exec_line(char *cmd, t_shell *st_shell)
{
  lexor_and_parsor(cmd, st_shell);
  execute_simple_command2(st_shell->st_tree, st_shell);
}

#endif		/* !__HREACT_ON__ */
