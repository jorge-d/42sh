/*
** xpipe.c for 42sh in /u/all/jorge_d/cu/svn/42shsvn/trunk/lib
** 
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
** 
** Started on  Fri Apr 23 14:46:36 2010 dimitri jorge
** Last update Sat May 15 14:12:42 2010 dimitri jorge
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "lib.h"

int	xpipe(int *p)
{
  if (pipe(p) == -1)
    {
      perror("Error in pipe() function: ");
      return (-1);
    }
  return (0);
}
