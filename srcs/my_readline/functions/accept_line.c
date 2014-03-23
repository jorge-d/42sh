/*
** accept_line.c for Accepte the line enter in /Users/lifely/Developer/project/VSHsvn/branches/my_readline/new
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu May  6 03:52:26 2010 julien di-marco
** Last update Tue May 18 19:05:52 2010 julien di-marco
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	"42sh.h"
#include	"my_readline.h"

int		accept_line(UNUSED t_shell *shell, UNUSED t_rl *base, \
			    UNUSED char *read)
{
  end_of_line(shell, base, read);
  write(1, "\n", 1);
  return (0);
}
