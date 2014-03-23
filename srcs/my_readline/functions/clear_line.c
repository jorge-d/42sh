/*
** clear_line.c for Clear Line in /Users/lifely/Developer/project/42shsvn/trunk
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Mon May 17 04:46:03 2010 julien di-marco
** Last update Sun May 23 03:17:54 2010 julien di-marco
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	"42sh.h"
#include	"my_readline.h"

int		clear_line(UNUSED t_shell *shell, UNUSED t_rl *base, \
			   UNUSED char *read)
{
  beginning_of_line(shell, base, read);
  apply_term("cd");
  base->info.i = 0;
  base->info.insert_m = 1;
  base->info.nb = 0;
  xfree(base->info.buffer);
  base->info.buffer = NULL;
  buffer_size(base);
  return (1);
}
