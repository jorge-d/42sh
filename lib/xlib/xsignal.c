/*
** xsignal.c for 42sh in /u/all/jorge_d/cu/svn/42shsvn/trunk/lib
** 
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
** 
** Started on  Sun May 23 16:05:46 2010 dimitri jorge
** Last update Sun May 23 16:05:47 2010 dimitri jorge
*/

#include <sys/types.h>
#include <dirent.h>
#include <signal.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "lib.h"

# define ERROR_SIG	"Error: signal: Error in signal()\n"

void	(*xsignal(int sig, void (*func)(int)))(int)
{
  if ((signal(sig, func)) == SIG_ERR)
    {
      fprintf(stderr, "%s\n", ERROR_SIG);
      return (SIG_ERR);
    }
  return (EXIT_SUCCESS);
}
