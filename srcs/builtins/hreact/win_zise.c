/*
** win_zise.c for 42sh in /u/all/jorge_d/cu/svn/42shsvn/trunk/srcs
** 
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
** 
** Started on  Thu May 20 20:50:59 2010 dimitri jorge
** Last update Thu May 20 22:24:06 2010 dimitri jorge
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include "42sh.h"
#include "builtins.h"
#include "set_environ.h"
#include "my_readline.h"
#include "hreact.h"

#ifdef			__HREACT_ON__

int			win_size(t_shell *st_shell)
{
  struct winsize	w;

  if (st_shell->st_hreact)
    {
      if (ioctl(0, TIOCGWINSZ, &w) < 0)
	return (RT_FAILURE);
      st_shell->st_hreact->x = w.ws_col;
      st_shell->st_hreact->y = w.ws_row;
    }
  return (RT_SUCCESS);
}

#endif			/* !__HREACT_ON__ */
