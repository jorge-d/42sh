/*
** down_line_or_history.c for asd in /u/epitech_2014/strzel_a/cu
**
** Made by alexandre strzelewicz
** Login   <strzel_a@epitech.net>
**
** Started on  Wed May 12 14:47:30 2010 alexandre strzelewicz
** Last update Sun May 23 03:18:44 2010 julien di-marco
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	"42sh.h"
#include	"my_readline.h"

int		down_line_or_history(UNUSED t_shell *shell, UNUSED t_rl *base, \
				     UNUSED char *read)
{
  if (shell && (shell->st_hist))
    {
      if (!shell->st_hist->next && (shell->st_hist->aff == 4))
	{
	  clear_line(shell, base, read);
	  self_insert_command(shell, base, base->tmp.buffer);
	  xfree(base->tmp.buffer);
	  move_cursor(base, -(base->tmp.nb - base->tmp.i));
	  base->tmp.buffer = NULL;
	  shell->st_hist->aff = 0;
	}
      else if (shell->st_hist->next && shell->st_hist->line \
	       && (shell->st_hist->aff == 4))
	{
	  shell->st_hist->aff = 0;
	  shell->st_hist = shell->st_hist->next;
	  clear_line(shell, base, read);
	  self_insert_command(shell, base, shell->st_hist->line);
	  shell->st_hist->aff = 4;
	}
    }
  return (1);
}
