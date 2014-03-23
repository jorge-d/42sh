/*
** xstat.c for 42sh in /u/all/jorge_d/cu/svn/42shsvn/trunk/lib
** 
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
** 
** Started on  Sun May 23 16:05:41 2010 dimitri jorge
** Last update Sun May 23 16:05:41 2010 dimitri jorge
*/

#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "lib.h"

int	xstat(char *file, struct stat *sts)
{
  if (stat(file, sts) == -1)
    {
      fprintf(stderr, "Error in stat function.\n");
      return (-1);
    }
  return (0);
}
