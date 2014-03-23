/*
** backward_char.c for BackWard char in /Users/lifely/Developer/project/VSHsvn/branches/my_readline/new
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu May  6 03:11:16 2010 julien di-marco
** Last update Sat May 22 20:19:41 2010 julien di-marco
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	"42sh.h"
#include	"my_readline.h"

int		backward_char(UNUSED t_shell *shell, UNUSED t_rl *base, \
			      UNUSED char *read)
{
  if (base && base->info.i > 0)
    {
      if (base->info.buffer && base->info.buffer[base->info.i - 1] == '\t')
	move_cursor(base, -7);
      else
	move_cursor(base, -1);
    }
  return (1);
}

int		forward_char(UNUSED t_shell *shell, UNUSED t_rl *base, \
			     UNUSED char *read)
{
  if (base && base->info.i >= 0)
    {
      if (base->info.buffer && base->info.buffer[base->info.i + 1] == '\t')
	move_cursor(base, 6);
      else
	move_cursor(base, 1);
    }
  return (1);
}
