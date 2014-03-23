/*
** clear.c for Header in /u/all/di-mar_j/cu/svn/42shsvn/trunk
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu May 20 16:50:21 2010 julien di-marco
** Last update Sun May 23 03:53:08 2010 julien di-marco
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	"42sh.h"
#include	"my_readline.h"

int		clear_it(UNUSED t_shell *shell, UNUSED t_rl *base, \
			    UNUSED char *read)
{
  apply_term("cl");
  redraw(shell, base, NULL);
  return (1);
}

