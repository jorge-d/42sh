/*
** prepare_command.c for 42sh in /u/all/jorge_d/cu/svn/parserll/trunk/src/execution
**
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
**
** Started on  Mon May 10 12:41:48 2010 dimitri jorge
** Last update Fri May 21 13:41:28 2010 dimitri jorge
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "parserll.h"
#include "42sh.h"
#include "set_environ.h"
#include "alias_glob.h"

static char	*get_bin_path(char *bin)
{
  char		*path;

  path = NULL;
  if (strncmp(bin, "/", 1) == 0 || strncmp(bin, ".", 1) == 0)
    path = get_absolute_path(bin);
  else
    {
      path = get_full_path(get_env_from_list("PATH"), bin);
      if (!path)
	path = get_full_path(get_set_from_list("PATH"), bin);
    }
  if (!path || (path && access(path, F_OK) == -1))
    fprintf(stderr, "%s: Command not found.\n", bin);
  else if (access(path, X_OK) == -1 || is_directory(path))
    fprintf(stderr, "%s: Permission denied.\n", bin);
  else
    return (path);
  xfree(path);
  return (NULL);
}

static int	prepare_command_2(t_tree *cmd, t_shell *st_shell)
{
  if (!cmd->args)
    return (EXIT_FAILURE);
  remove_sequence_quote(cmd->args, cmd);
  if ((cmd->args = expend_alias(cmd->args, st_shell->st_alias)))
    {
      if (cmd->args && cmd->args[0] && \
	  !strncmp(cmd->args[0], "unsetenv", strlen(cmd->args[0])))
	cmd->args = operate_env_globbing(cmd->args, gl_st.st_env);
      else if (cmd->args)
	cmd->args = operate_globbing(cmd->args);
    }
  else
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int		prepare_command(t_tree *cmd, t_shell *st_shell)
{
  int		flag;

  if ((flag = check_var_on_env(cmd->args, cmd)) != EXIT_SUCCESS)
    return (flag);
  if ((flag = prepare_command_2(cmd, st_shell)) != EXIT_SUCCESS)
    return (flag);
  if (!is_builtin(cmd->args[0]) &&
      !(cmd->full_path = get_bin_path(cmd->args[0])))
    return (EXIT_FAILURE);
  return (0);
}

int		prepare_all_commands(t_tree *tree, t_shell *st_shell)
{
  int		flag;

  if (tree && (tree->type == IS_CMD))
    {
      if ((flag = prepare_command(tree, st_shell)) != EXIT_SUCCESS)
	return (flag);
    }
  else if (tree)
    {
      if ((flag = prepare_all_commands(tree->right, st_shell)) != EXIT_SUCCESS)
	return (flag);
      if ((flag = prepare_all_commands(tree->left, st_shell)) != EXIT_SUCCESS)
	return (flag);
    }
  return (EXIT_SUCCESS);
}
