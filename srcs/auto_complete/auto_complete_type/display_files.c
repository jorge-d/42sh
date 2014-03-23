/*
** readstd.c for mysh in /u/all/strzel_a/cu/rendu/c/my_ls
**
** Made by alexandre strzelewicz
** Login   <strzel_a@epitech.net>
**
** Started on  Mon Dec  7 15:08:13 2009 alexandre strzelewicz
** Last update Sat May 22 13:50:45 2010 alexandre strzelewicz
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/param.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include "42sh.h"
#include "auto_complete.h"

t_list		*display_file(void)
{
  struct dirent	*d;
  char		*path;
  DIR		*directory;
  char		buffer[BUFF_SIZE];
  t_list	*st_list;

  st_list = NULL;
  memset(buffer, '\0', BUFF_SIZE);
  path = NULL;
  if (!(path = getcwd(path, MAXPATHLEN)))
    return (NULL);
  if (!(directory = opendir(path)))
    return (NULL);
  xfree(path);
  while ((d = readdir(directory)))
    if (d->d_name[0] != '.')
      put_in_list(d->d_name, &st_list, 0);
  xclosedir(directory);
  xfree(d);
  return (st_list);
}
