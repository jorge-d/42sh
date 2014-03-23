/*
** xreadlink.c for 42sh in /u/all/jorge_d/cu/svn/42shsvn/trunk/lib
** 
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
** 
** Started on  Sun May 23 16:05:54 2010 dimitri jorge
** Last update Sun May 23 16:05:55 2010 dimitri jorge
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "lib.h"

int	xreadlink(char *path, char *buff, int bufsiz)
{
  int	count;

  if ((count = readlink(path, buff, bufsiz)) == -1)
    fprintf(stderr, "Error in function readlink.\n");
  buff[count] = '\0';
  return (count);
}
