/*
** readstd.c for mysh in /u/all/strzel_a/cu/rendu/c/my_ls
**
** Made by alexandre strzelewicz
** Login   <strzel_a@epitech.net>
**
** Started on  Mon Dec  7 15:08:13 2009 alexandre strzelewicz
** Last update Mon May 17 15:27:34 2010 alexandre strzelewicz
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/param.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "42sh.h"
#include "auto_complete.h"

int		memset_cpy_n_modif(char *path, char *command)
{
  memset(path, '\0', MAXPATHLEN - 1);
  strncpy(path, command, MAXPATHLEN);
  one_gap_modification(path);
  return (0);
}

int		one_gap_modification(char *command)
{
  char		buffer[MAXPATHLEN];
  int		count;
  int		count_2;

  count_2 = count = 0;
  count = strlen(command);
  if (command == NULL)
    return (0);
  memset(buffer, 0, MAXPATHLEN);
  strncpy(buffer, command, MAXPATHLEN);
  while (buffer[count - 1] != '/' && count > 0)
    {
      count_2++;
      count--;
    }
  memset(command, '\0', MAXPATHLEN);
  strncpy(command, buffer, strlen(buffer) - count_2);
  return (0);
}

int		optimise_completion(char *command, UNUSED int *count)
{
  struct stat	f_stat;

  if (lstat(command, &f_stat) == -1)
    return (0);
  if (command != NULL)
    if (command[my_strlen(command) - 1] != '/')
      if ((S_IFMT & f_stat.st_mode) == S_IFDIR ||
	  (S_IFMT & f_stat.st_mode) == S_IFLNK)
	my_strcat(command, "/");
  return (0);
}

int		optimise_completion_2(char *buffer, char *command,
			 UNUSED int *count)
{
  struct stat	f_stat;

  if (lstat(buffer, &f_stat) == -1)
    return (0);
  if (command != NULL)
    if (command[my_strlen(command) - 1] != '/')
      if ((S_IFMT & f_stat.st_mode) == S_IFDIR ||
	  (S_IFMT & f_stat.st_mode) == S_IFLNK)
	my_strcat(command, "/");
  return (0);
}

int		is_there_a_slash(char *str)
{
  int		count;

  count = 0;
  while (*str)
    {
      if (*str == '/')
	count++;
      str++;
    }
  return (count);
}
