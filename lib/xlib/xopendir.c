/*
** xopendir.c for 42sh in /u/all/jorge_d/cu/svn/42shsvn/trunk/lib
** 
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
** 
** Started on  Fri Apr 23 14:48:27 2010 dimitri jorge
** Last update Fri Apr 23 14:53:37 2010 dimitri jorge
*/

#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "lib.h"

DIR	*xopendir(const char *name)
{
  DIR	*open;

  if ((open = opendir(name)) == NULL)
    fprintf(stderr, "Error in opendir function.\n");
  return (open);
}
