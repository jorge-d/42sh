/*
** readstd.c for mysh in /u/all/strzel_a/cu/rendu/c/my_ls
**
** Made by alexandre strzelewicz
** Login   <strzel_a@epitech.net>
**
** Started on  Mon Dec  7 15:08:13 2009 alexandre strzelewicz
** Last update Tue May 11 23:26:49 2010 alexandre strzelewicz
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/param.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "42sh.h"
#include "auto_complete.h"

int	_file_completion_1(char *buffer, char *file, char *command,
			   char *buffer_2)
{
  strcpy(buffer, file);
  strcpy(buffer_2, command);
  one_gap_modification(buffer_2);
  my_strcat(buffer_2, file);
  return (TRUE);
}

int	_file_completion_2(char *buffer, char *buffer_2, char *path,
				   char *command)
{
  memset(buffer, '\0', MAXPATHLEN);
  memset(buffer_2, '\0', MAXPATHLEN);
  strncpy(buffer_2, path, ENV_VAR_SIZE);
  if (buffer_2[my_strlen(buffer_2) - 1] != '/')
    my_strcat(buffer_2, "/");
  my_strcat(buffer_2, command);
  one_gap_modification(buffer_2);
  if (strcmp(buffer_2, buffer) == 0)
    return (FALSE);
  return (TRUE);
}

int	_file_completion_tilde(char *buffer_2, char *path, char *command)
{
  memset(buffer_2, '\0', MAXPATHLEN);
  strncpy(buffer_2, path, ENV_VAR_SIZE);
  if (buffer_2[my_strlen(buffer_2) - 1] != '/')
    my_strcat(buffer_2, "/");
  my_strcat(buffer_2, command + 2);
  one_gap_modification(buffer_2);
  if (buffer_2[my_strlen(buffer_2) - 1] != '/')
    my_strcat(buffer_2, "/");
  return (TRUE);
}

int	_file_completion_3(char *buffer, char *buffer_2, char *path, char *cmd)
{
  (void)cmd;
  memset(buffer, '\0', MAXPATHLEN);
  memset(buffer_2, '\0', MAXPATHLEN);
  strncpy(buffer_2, path, ENV_VAR_SIZE);
  one_gap_modification(buffer_2);
  if (strcmp(buffer_2, buffer) == 0)
    return (0);
  return (1);
}
