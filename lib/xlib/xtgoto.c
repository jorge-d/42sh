/*
** xtgoto.c for 42sh in /u/all/jorge_d/cu/svn/42shsvn/trunk/lib
** 
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
** 
** Started on  Sun May 23 16:05:20 2010 dimitri jorge
** Last update Sun May 23 16:05:21 2010 dimitri jorge
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"terminal.h"

char		*xtgoto(char *cap, int col, int row)
{
  char		*buf;

  if ((buf = tgoto(cap, col, row)) == 0)
    perror("Error in tgoto: ");
  return (buf);
}
