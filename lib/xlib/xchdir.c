/*
** xchdir.c for 42sh in /u/all/jorge_d/svn/VSHsvn/trunk/lib
** 
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
** 
** Started on  Sun Apr  4 20:34:01 2010 dimitri jorge
** Last update Tue May 18 18:47:49 2010 dimitri jorge
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<stdio.h>
#include	"lib.h"

int		xchdir(char *path)
{
  if (access(path, F_OK) == -1)
    fprintf(stderr, "%s : No such file or directory\n", path);
  else if (access(path, X_OK) == -1)
    fprintf(stderr, "%s : Permission denied\n", path);
  else if (chdir(path) == -1)
    perror("Problem in chdir() function :");
  else
    return (0);
  return (-1);
}
