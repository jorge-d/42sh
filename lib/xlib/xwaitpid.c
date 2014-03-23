/*
** xwaitpid.c for 42sh in /u/all/jorge_d/cu/svn/42shsvn/trunk/lib
** 
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
** 
** Started on  Sun May 23 16:05:08 2010 dimitri jorge
** Last update Sun May 23 16:05:09 2010 dimitri jorge
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include "lib.h"

pid_t	xwaitpid(pid_t wpid, int *status, int option)
{
  pid_t	val;

  if ((val = waitpid(wpid, status, option)) == -1)
    fprintf(stderr, "Problem in waitpid function.\n");
  return (val);
}
