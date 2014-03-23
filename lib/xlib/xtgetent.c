/*
** xtgetent.c for 42sh in /u/all/jorge_d/cu/svn/42shsvn/trunk/lib
** 
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
** 
** Started on  Sun May 23 16:05:33 2010 dimitri jorge
** Last update Sun May 23 16:05:33 2010 dimitri jorge
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"terminal.h"
#include	"lib.h"

int		xtgetent(char *bp, char *name)
{
  int		c;

  if ((c = tgetent(bp, name)) != 1)
      perror("Error in tgetent: ");
  return (c);
}
