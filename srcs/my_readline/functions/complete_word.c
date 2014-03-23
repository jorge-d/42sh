/*
** complete_word.c for 42sh in /u/all/jorge_d/cu/svn/42shsvn/trunk
** 
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
** 
** Started on  Thu May  6 16:42:39 2010 julien di-marco
** Last update Sun May 23 16:17:37 2010 dimitri jorge
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	"42sh.h"
#include	"my_readline.h"
#include	"auto_complete.h"

int		redraw(UNUSED t_shell *shell, t_rl *base, \
		       char *read)
{
  int		i;

  if (base)
    {
      if (read)
	xwrite(STDOUT_FILENO, "\n", 1);
      print_prompt(base, NULL);
      i = 0;
      if (base->info.buffer)
	{
	  while (base->info.buffer[i])
	    write(1, &base->info.buffer[i++], 1);
	  i = base->info.nb - base->info.i;
	  base->info.i += i;
	  move_cursor(base, (-i));
	}
    }
  return (1);
}

int		complete_word(UNUSED t_shell *shell, \
			      t_rl *base, UNUSED char *read)
{
  int		i;
  char		*out;

  i = 0;
  out = NULL;
  if (base && shell && !(out = auto_complete(base, shell)))
    redraw(shell, base, "1");
  else
    {
      if ((i = base->info.nb - base->info.i))
	i += 1;
      xwrite(STDOUT_FILENO, "\n", 1);
      clear_line(shell, base, read);
      print_prompt(base, NULL);
      self_insert_command(shell, base, out);
      move_cursor(base, -i);
      xfree(out);
    }
  return (1);
}
