/*
** xtgetstr.c for 42sh in /u/all/jorge_d/cu/svn/42shsvn/trunk/lib
** 
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
** 
** Started on  Sun May 23 16:05:27 2010 dimitri jorge
** Last update Sun May 23 16:05:28 2010 dimitri jorge
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"terminal.h"

char		*xtgetstr(char *id, char **area)
{
  char		*buf;

  if ((buf = tgetstr(id, area)) == NULL)
    return (NULL);
  return (buf);
}
