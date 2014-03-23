/*
** xfree.c for 42sh in /u/all/jorge_d/cu/svn/42shsvn/trunk/lib
** 
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
** 
** Started on  Sun May 23 16:06:26 2010 dimitri jorge
** Last update Sun May 23 16:06:26 2010 dimitri jorge
*/

#include <unistd.h>
#include <stdlib.h>
#include "lib.h"

void	xfree(void *p)
{
  if (p)
    {
      free(p);
      p = NULL;
    }
}
