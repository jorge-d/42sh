/*
** xwrite.c for 42sh in /u/all/jorge_d/cu/svn/42shsvn/trunk/lib
** 
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
** 
** Started on  Sun May 23 16:05:03 2010 dimitri jorge
** Last update Sun May 23 16:05:03 2010 dimitri jorge
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "lib.h"

int	xwrite(int fd, char *buf, int nbytes)
{
  int	nb;

  if ((nb = write(fd, buf, nbytes)) == -1)
    perror("42sh:");
  return (nb);
}
