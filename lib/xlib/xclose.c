/*
** xclose.c for 42sh in /u/all/jorge_d/cu/svn/42shsvn/trunk/lib
** 
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
** 
** Started on  Sun May 23 16:06:56 2010 dimitri jorge
** Last update Sun May 23 16:06:56 2010 dimitri jorge
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"lib.h"

void		xclose(int fd)
{
  if (close(fd) == -1)
    perror("Error in close()");
}
