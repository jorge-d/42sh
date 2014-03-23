/*
** delete_char_or_list_or_eof.c for Control D : D  in /u/all/di-mar_j/cu/svn/VSHsvn/branches/my_readline/new
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu May  6 16:42:39 2010 julien di-marco
** Last update Sun May 23 03:18:21 2010 julien di-marco
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	"42sh.h"
#include	"my_readline.h"

int		delete_char_or_lt_or_eof(UNUSED t_shell *shell, \
					 UNUSED t_rl *base, UNUSED char *read)
{
  xfree(base->info.buffer);
  end_of_line(shell, base, read);
  write(1, "\n", 1);
  base->info.buffer = NULL;
  return (0);
}
