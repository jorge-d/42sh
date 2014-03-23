/*
** close_fds.c for 42sh in /u/all/jorge_d/cu/svn/parserll/trunk/src/execution
** 
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
** 
** Started on  Sun May  9 22:32:48 2010 dimitri jorge
** Last update Thu May 13 18:52:00 2010 dimitri jorge
*/

#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include "parserll.h"
#include "42sh.h"


void		close_trees_fd(t_tree *begin)
{
  if (begin)
    {
      if (begin->fd_in != 0)
	{
	  xclose(begin->fd_in);
	  begin->fd_in = 0;
	}
      if (begin->fd_out != 1)
	{
	  xclose(begin->fd_out);
	  begin->fd_out = 0;
	}
      close_trees_fd(begin->left);
      close_trees_fd(begin->right);
    }
}
