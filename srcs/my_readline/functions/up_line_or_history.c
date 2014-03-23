/*
** up_line_or_history.c for asdfs in /u/epitech_2014/strzel_a/cu
** 
** Made by alexandre strzelewicz
** Login   <strzel_a@epitech.net>
** 
** Started on  Wed May 12 14:47:34 2010 alexandre strzelewicz
** Last update Sun May 23 15:34:47 2010 julien di-marco
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	"42sh.h"
#include	"my_readline.h"

static int		backup_line(t_rl *base)
{
  base->tmp.i = base->info.i;
  base->tmp.nb = base->info.nb;
  base->tmp.buffer = strdup(base->info.buffer);
  return (1);
}

int		up_line_or_history(t_shell *shell, t_rl *base, \
				   UNUSED char *read)
{
  if (shell && shell->st_hist && base->info.buffer)
    {
      if (!shell->st_hist->next && (shell->st_hist->aff == 0))
	backup_line(base);
      if (shell->st_hist && shell->st_hist->line)
	{
	  if (((!shell->st_hist->next && (shell->st_hist->aff == 4)) &&
	       shell->st_hist->prev) || (shell->st_hist->prev && \
					 shell->st_hist->next))
	    {
	      shell->st_hist->aff = 0;
	      shell->st_hist = shell->st_hist->prev;
	    }
	  if (shell->st_hist && (shell->st_hist->aff != 4))
	    {
	      shell->st_hist->aff = 4;
	      clear_line(shell, base, read);
	      self_insert_command(shell, base, shell->st_hist->line);
	    }
	}
    }
  return (1);
}
