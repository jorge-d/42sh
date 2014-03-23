/*
** move_cursor.c for Header in /Users/lifely/Developer/project/42shsvn/trunk
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Sun May 16 18:03:53 2010 julien di-marco
** Last update Fri May 21 14:30:51 2010 julien di-marco
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	"42sh.h"
#include	"my_readline.h"

int		beginning_of_line(UNUSED t_shell *shell, UNUSED t_rl *base, \
				  UNUSED char *read)
{
  move_cursor(base, (base->info.i * -1));
  return (1);
}

int		end_of_line(UNUSED t_shell *shell, UNUSED t_rl *base, \
			    UNUSED char *read)
{
  move_cursor(base, (base->info.nb - base->info.i));
  return (1);
}


