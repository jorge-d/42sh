/*
** xfork.c for 42sh in /u/all/jorge_d/cu/svn/42shsvn/trunk/lib
** 
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
** 
** Started on  Sun May 23 16:06:33 2010 dimitri jorge
** Last update Sun May 23 16:06:34 2010 dimitri jorge
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "lib.h"

pid_t	xfork(void)
{
  pid_t	pid;

  if ((pid = fork()) == -1)
    {
      perror("Error in fork() :");
      return (-1);
    }
  return (pid);
}
