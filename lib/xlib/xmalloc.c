/*
** xmalloc.c for 42sh in /u/all/jorge_d/cu/svn/42shsvn/trunk/lib
**
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
**
** Started on  Fri Apr 23 14:55:14 2010 dimitri jorge
** Last update Sat May 22 21:19:20 2010 dimitri jorge
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lib.h"

void	*xmalloc(size_t size)
{
  void	*p;

  if (!(p = malloc(size)))
    perror("42sh: malloc() : ");
  else
    memset(p, 0, size);
  return (p);
}
