/*
** overwrite_mode.c for overwrite Mode - Switch to Overwrite Mode or Insert Mode in /Users/lifely/Developer/project/42shsvn/trunk
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Mon May 17 02:37:04 2010 julien di-marco
** Last update Mon May 17 02:47:47 2010 julien di-marco
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	"42sh.h"
#include	"my_readline.h"

int		overwrite_mode(UNUSED t_shell *shell, UNUSED t_rl *base, \
			       UNUSED char *read)
{
  if (base && base->info.insert_m)
    base->info.insert_m = 0;
  else if (base && (base->info.insert_m == 0))
    base->info.insert_m = 1;
  return (1);
}
