/*
** self_insert_command.c for Self Insert Command in /u/all/di-mar_j/cu/svn/VSHsvn/branches/my_readline/new
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Wed Apr 21 14:55:01 2010 julien di-marco
** Last update Sun May 23 14:03:31 2010 julien di-marco
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	"42sh.h"
#include	"my_readline.h"

int		insert_mode(t_rl *base, char *copy, int *i)
{
  int		j;

  j = 0;
  if (base->info.insert_m)
    {
      while (copy[j] != '\0')
	{
	  if ((ROW(*i, base) + 1) == gl_st.size.ts_cols)
	      write(1, "\n", 1);
	  write(STDOUT_FILENO, &copy[j], 1);
	  base->info.buffer[(*i)++] = copy[j++];
	}
      base->info.buffer[*i] = '\0';
    }
  return (j);
}

int		insert_one_charactere(t_rl *base, char c, int i)
{
  int		j;
  char		*copy;

  j = 0;
  copy = NULL;
  if (base && base->info.buffer && (copy = strdup(&base->info.buffer[i])))
    {
      if (buffer_size(base))
	{
	  base->info.buffer[i++] = c;
	  write(STDOUT_FILENO, &c, 1);
	  j = insert_mode(base, copy, &i);
	  if (base->info.insert_m || (base->info.i >= base->info.nb))
	    base->info.nb += 1;
	  if (!j && (base->info.i + i) && (ROW((base->info.i + 1), base) == 0))
	    move_cursor(base, 1);
	  base->info.i = i;
	  move_cursor(base, (j * -1));
	}
      xfree(copy);
    }
  return (EXIT_FAILURE);
}

int		self_insert_command(UNUSED t_shell *shell, UNUSED t_rl *base, \
				    UNUSED char *read)
{
  int		i;

  if (buffer_size(base) && base)
    {
      i = -1;
      while (read && read[++i])
	insert_one_charactere(base, read[i], base->info.i);
    }
  return (1);
}
