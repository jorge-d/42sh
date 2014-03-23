/*
** xlstat.c for 42sh in /u/all/jorge_d/cu/svn/42shsvn/trunk/lib
** 
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
** 
** Started on  Sun May 23 16:06:17 2010 dimitri jorge
** Last update Sun May 23 16:06:19 2010 dimitri jorge
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "lib.h"

int	xlstat(char *av, struct stat *buf)
{
  if (lstat(av, buf) == -1)
    {
      fprintf(stderr, "Error in lstat function.\n");
      return (-1);
    }
  return (0);
}
