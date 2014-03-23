/*
** get_full_path.c for 42sh in /u/all/jorge_d/cu/svn/42shsvn/trunk/srcs
** 
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
** 
** Started on  Fri May  7 18:10:55 2010 dimitri jorge
** Last update Sat May 22 13:29:57 2010 dimitri jorge
*/

#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "42sh.h"

static void	concat_path_and_bin(char *path, char *binary, int i)
{
  path[i++] = '/';
  path[i] = '\0';
  path = my_strcat(path, binary);
}

char		*get_absolute_path(char *binary)
{
  char		*full_path;

  full_path = xcalloc((my_strlen(binary) + 1), sizeof(*full_path));
  if (!full_path)
    return (NULL);
  full_path = my_strcpy(full_path, binary);
  return (full_path);
}

char		*get_full_path(char *path, char *binary)
{
  int		i;
  int		len;
  char		*full_path;

  i = 0;
  full_path = NULL;
  len = my_strlen(path) + my_strlen(binary) + 2;
  while (path && *path)
    {
      if (i == 0 && !(full_path = xcalloc(len, sizeof(*full_path))))
	return (NULL);
      full_path[i++] = *path++;
      if (*path == ':' || *path == '\0')
	{
	  concat_path_and_bin(full_path, binary, i);
	  if (access(full_path, F_OK) == 0)
	    return (full_path);
	  xfree(full_path);
	  i = 0;
	  if (*path == ':')
	    path++;
	}
    }
  return (0);
}
