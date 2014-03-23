/*
** restore.c for Restore Term conf in /u/all/di-mar_j/svn/minishell2/termcap
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Mar  4 16:24:46 2010 julien di-marco
** Last update Sat May 22 19:36:51 2010 julien di-marco
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"42sh.h"
#include	"my_readline.h"

void		reset_readline(t_rl *info)
{
  xfree(info->prompt);
  if (&info->terminal && CHCK(info->flags, 0x01))
    if (ioctl(STDIN_FILENO, TIOCSETA, &info->terminal) == -1)
      fprintf(stderr, E_RESET);
}
