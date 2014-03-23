/*
** set_fds.c for 42sh in /u/all/jorge_d/cu/svn/parserll/trunk/src/execution
** 
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
** 
** Started on  Mon May 10 12:27:19 2010 dimitri jorge
** Last update Tue May 11 19:14:21 2010 dimitri jorge
*/

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "parserll.h"
#include "42sh.h"

void	set_fd_out(t_tree *begin, int fd)
{
  if (begin && begin->type != IS_CMD)
    {
      if (begin->right->type == IS_CMD)
	set_fd_out(begin->right, fd);
      else
	set_fd_out(begin->left, fd);
    }
  else if (begin && begin->type == IS_CMD)
    begin->fd_out = fd;
}

void	set_fd_in(t_tree *begin, int fd)
{
  if (begin && begin->type != IS_CMD)
    {
      if (begin->right->type == IS_CMD)
	set_fd_in(begin->right, fd);
      else
	set_fd_in(begin->left, fd);
    }
  else if (begin && begin->type == IS_CMD)
    begin->fd_in = fd;
}
