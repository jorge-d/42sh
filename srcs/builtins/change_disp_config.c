/*
** select_command.c for mysh in /u/all/strzel_a/cu/rendu/c/my_ls
**
** Made by alexandre strzelewicz
** Login   <strzel_a@epitech.net>
**
** Started on  Mon Dec  7 16:31:10 2009 alexandre strzelewicz
** Last update Sat May 22 20:00:06 2010 julien di-marco
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "42sh.h"
#include "alias_glob.h"
#include "builtins.h"
#include "set_environ.h"
#include "my_readline.h"
#include "hreact.h"

#ifdef		__HREACT_ON__

void		usage_hreact(void)
{
  printf("\n\t\t\033[1;31;1m-V-\033[0m \033[1mHreact bar\033[0m");
  printf("\033[1;31;1m-V-\033[0m\n\n");
  printf("\t\033[1mUSAGE\033[0m = hreact [1ARG] [2ARG] ...\n");
  printf("\t\033[1;4mSize\033[0m :\n");
  printf("\t\033[1mx width \033[0m: set width\n");
  printf("\t\033[1my lenght \033[0m: set max lenght\n\n");
  printf("\t\033[1;4mSwitching\033[0m :\n");
  printf("\t\033[1mps\033[0m : switch between navigation & ps\n\n");
}

static void	_b_change_size(char **args, t_shell *st_shell)
{
  int		tmp;

  tmp = 0;
  if (!my_strcmp(args[1], "x") && args[2])
    {
      tmp = atoi(args[2]);
      if (tmp >= 30 && tmp <= 100)
	st_shell->st_hreact->x_width_window = tmp;
      else
	fprintf(stderr, "X must be between 100 && 30.\n");
    }
  else if (!my_strcmp(args[1], "y") && args[2])
    {
      tmp = atoi(args[2]);
      if (tmp <= 70 && tmp >= 20)
	st_shell->st_hreact->y_lenght_window = tmp;
      else
	fprintf(stderr, "Y must be between 70 && 20.\n");
    }
}

static void	_b_top_app(t_shell *st_shell)
{
  static char	which;

  if (!which)
    {
      xfree(st_shell->st_hreact->cmd[0].spe_cmd);
      xfree(st_shell->st_hreact->cmd[1].spe_cmd);
      strcpy(st_shell->st_hreact->cmd[0].comment, "+- MONITOR -+\n");
      st_shell->st_hreact->cmd[0].spe_cmd = strdup("ps -uc");
      st_shell->st_hreact->cmd[1].spe_cmd = NULL;
      which = 1;
    }
  else
    {
      xfree(st_shell->st_hreact->cmd[0].spe_cmd);
      strcpy(st_shell->st_hreact->cmd[0].comment, "+- PWD -+");
      st_shell->st_hreact->cmd[0].spe_cmd = strdup("pwd");
      strcpy(st_shell->st_hreact->cmd[1].comment, "+- File listing -+");
      st_shell->st_hreact->cmd[1].spe_cmd = strdup("ls -lhtF");
      st_shell->st_hreact->cmd[2].spe_cmd = NULL;
      which = 0;
    }
}

int		hreact_config(char **args, t_shell *st_shell)
{
  if (!st_shell->st_hreact)
    return (EXIT_FAILURE);
  if (args[1] && (!strcmp(args[1], "x") || !strcmp(args[1], "y")) && args[2])
    _b_change_size(args, st_shell);
  else if (args[1] && !strcmp(args[1], "ps"))
    _b_top_app(st_shell);
  else
    usage_hreact();
  st_shell->st_hreact->flags |= DISP_REACTUALIZE;
  return (EXIT_SUCCESS);
}

#endif		/* !__HREACT_ON__ */
