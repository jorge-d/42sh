/*
** xcalloc.c for 42sh in /u/all/jorge_d/cu/svn/42shsvn/trunk/lib
** 
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
** 
** Started on  Sat May 22 13:13:53 2010 dimitri jorge
** Last update Sat May 22 13:15:06 2010 dimitri jorge
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lib.h"

void	*xcalloc(size_t number, size_t size)
{
  void	*p;

  if (!(p = calloc(number, size)))
    perror("Calloc");
  return (p);
}
