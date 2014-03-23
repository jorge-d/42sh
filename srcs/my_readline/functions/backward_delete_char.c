/*
** backward_delete_char.c for BackWard Delete Char in /u/all/di-mar_j/cu/svn/VSHsvn/branches/my_readline/new
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu May  6 14:56:33 2010 julien di-marco
** Last update Sun May 23 06:00:52 2010 julien di-marco
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	"42sh.h"
#include	"my_readline.h"

static int	move_line(char *line, int i, t_rl *base)
{
  int		back;

  back = ROW(base->info.i, base);
  while (line[i] != '\0')
    {
      line[i] = line[i + 1];
      if (line[i])
	xwrite(STDOUT_FILENO, &line[i], 1);
      else
	{
	  if (!(ROW(i, base) >= (gl_st.size.ts_cols - 1)))
	    xwrite(STDOUT_FILENO, " ", 1);
	  else
	    return (i);
	}
      i++;
    }
  return (i);
}

int		backward_delete_char(UNUSED t_shell *shell, t_rl *base, \
				     UNUSED char *read)
{
  int		i;
  int		n;

  i = 0;
  n = 0;
  if (base && base->info.buffer && (base->info.i > 0))
    {
      _move_cursor(base, -1);
      apply_term("dc");
      i = move_line(base->info.buffer, base->info.i - 1, base);
      n = ((i + 1) - base->info.i);
      base->info.i = i;
      move_cursor(base, (n * -1));
      base->info.nb -= 1;
    }
  return (1);
}
