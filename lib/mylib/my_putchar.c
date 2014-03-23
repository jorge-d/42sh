/*
** my_putchar.c for 42sh in /u/all/jorge_d/svn/VSHsvn/trunk/lib
** 
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
** 
** Started on  Wed Apr  7 14:42:31 2010 dimitri jorge
** Last update Tue May 18 16:37:14 2010 julien di-marco
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"lib.h"

void		my_putchar(char c)
{
  xwrite(STDOUT_FILENO, &c, 1);
}

void		my_putfd(int fd, char c)
{
  xwrite(fd, &c, 1);
}


int		my_fdstr(int fd, char *str)
{
  return (xwrite(fd, str, my_strlen(str)));
}
