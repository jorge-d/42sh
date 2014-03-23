/*
** xread.c for 42sh in /u/all/jorge_d/cu/svn/42shsvn/trunk/lib
** 
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
** 
** Started on  Fri Apr 23 14:45:24 2010 dimitri jorge
** Last update Fri Apr 23 14:46:07 2010 dimitri jorge
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "lib.h"

int	xread(int fd, char *buff, int len)
{
  int	nb_read;

  if ((nb_read = read(fd, buff, len)) == -1)
    fprintf(stderr, "Couldn't read on filedescriptor %d.\n", fd);
  return (nb_read);
}
