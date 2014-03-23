/*
** xdup2.c for 42sh in /u/all/jorge_d/cu/svn/42shsvn/trunk/lib
** 
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
** 
** Started on  Sun May 23 16:06:44 2010 dimitri jorge
** Last update Sun May 23 16:06:45 2010 dimitri jorge
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"lib.h"

int		xdup2(int oldd, int newd)
{
  if (dup2(oldd, newd) == -1)
    {
      perror("Error in dup2() : ");
      return (-1);
    }
  return (EXIT_SUCCESS);
}
