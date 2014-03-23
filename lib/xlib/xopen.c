/*
** xopen.c for 42sh in /u/all/jorge_d/cu/svn/42shsvn/trunk/lib
** 
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
** 
** Started on  Sun May 23 16:06:08 2010 dimitri jorge
** Last update Sun May 23 16:06:08 2010 dimitri jorge
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "lib.h"

int	xopen(char *file, int flag, int chmod)
{
  int	fd;

  fd = 0;
  if ((chmod != -1) && file)
    {
      if ((fd = open(file, flag, chmod)) == -1)
	fprintf(stderr, "42sh: %s: %s\n", file, strerror(errno));
    }
  else if (file)
    if ((fd = open(file, flag)) == -1)
      fprintf(stderr, "42sh: error: no path to open\n");
  return (fd);
}
