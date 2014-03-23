/*
** xexecve.c for 42sh in /u/all/sabbag_a/svn/VSHsvn/trunk/src/functions
**
** Made by fares sabbagh
** Login   <sabbag_a@epitech.net>
**
** Started on  Mon Apr  5 21:43:33 2010 fares sabbagh
** Last update Sat May 15 14:13:44 2010 dimitri jorge
*/

#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include "lib.h"

void	xexecve(const char *path, char **const argv, char **const envp)
{
  if (execve(path, argv, envp) == -1)
    perror("Error in execve() : ");
  exit(EXIT_FAILURE);
}
