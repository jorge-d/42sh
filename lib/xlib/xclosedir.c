/*
** xclosedir.c for 42sh in /u/all/jorge_d/cu/svn/42shsvn/trunk/lib
** 
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
** 
** Started on  Sun May 23 16:06:50 2010 dimitri jorge
** Last update Sun May 23 16:06:50 2010 dimitri jorge
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"lib.h"

void		xclosedir(DIR *dir)
{
  if (dir && closedir(dir) == -1)
    perror("Error in xclosedir : ");
}
