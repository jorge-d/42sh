/*
** readstd.c for mysh in /u/all/strzel_a/cu/rendu/c/my_ls
**
** Made by alexandre strzelewicz
** Login   <strzel_a@epitech.net>
**
** Started on  Mon Dec  7 15:08:13 2009 alexandre strzelewicz
** Last update Sat May 22 20:01:58 2010 dimitri jorge
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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
#include "set_environ.h"

#define HOME	"HOME"

static t_list	*_close_and_return(t_list *st_list, DIR *dir, struct dirent *d)
{
  xclosedir(dir);
  xfree(d);
  return (st_list);
}

t_list		*file_completion(char *command)
{
  t_list	*tmp;

  if (strncmp(command, "~", 1) == 0)
    tmp = tilde_completion(command);
  else if (command[0] == '/')
    tmp = slash_completion(command);
  else
    tmp = current_file_completion(command);
  return (tmp);
}

t_list		*current_file_completion(char *cmd)
{
  char		*path;
  char		buf[MAXPATHLEN];
  char		buf_2[MAXPATHLEN];
  char		path_copy[MAXPATHLEN];
  DIR		*dir;
  t_list	*st_list;
  struct dirent	*d;

  st_list = NULL;
  if (!(path = NULL) && !(path = getcwd(path, MAXPATHLEN)))
    return (NULL);
  memset(path_copy, '\0', MAXPATHLEN);
  strcpy(path_copy, path);
  if (!(_file_completion_2(buf, buf_2, path, cmd)) || !(dir = opendir(buf_2)))
    return (NULL);
  if (path[strlen(path) - 1] != '/')
    strcat(path, "/");
  while ((d = readdir(dir)))
    {
      _file_completion_1(buf, d->d_name, cmd, buf_2);
      add_slash_to_buf_if_dir(buf_2, buf, path);
      if (my_strncmp(cmd, buf_2, my_strlen(cmd)) == 0 && d->d_name[0] != '.')
	put_in_list(buf, &st_list, 0);
    }
  return (_close_and_return(st_list, dir, d));
}

t_list		*tilde_completion(char *cmd)
{
  char		*path;
  char		buf[MAXPATHLEN];
  char		buf_2[MAXPATHLEN];
  char		path_copy[MAXPATHLEN];
  DIR		*dir;
  t_list	*st_list;
  struct dirent	*d;

  st_list = NULL;
  if (!(path = get_env_from_list(HOME)) && !(path = get_set_from_list(HOME)))
    return (NULL);
  strcpy(path_copy, path);
  if (!(_file_completion_tilde(buf_2, path, cmd)) || !(dir = opendir(buf_2)))
    return (NULL);
  if (path[strlen(path) - 1] != '/')
    strcat(path, "/");
  while ((d = readdir(dir)))
    {
      _file_completion_1(buf, d->d_name, cmd + 2, buf_2);
      add_slash_to_buf_if_dir(buf_2, buf, path);
      if (strncmp(cmd + 2, buf_2, strlen(cmd) - 2) == 0 && d->d_name[0] != '.')
	put_in_list(buf, &st_list, 0);
    }
  return (_close_and_return(st_list, dir, d));
}

t_list		*slash_completion(char *cmd)
{
  char		path[MAXPATHLEN];
  char		buf[MAXPATHLEN];
  char		buf_2[MAXPATHLEN];
  char		path_copy[MAXPATHLEN];
  DIR		*dir;
  t_list	*st_list;
  struct dirent	*d;

  st_list = NULL;
  strcpy(path, cmd);
  one_gap_modification(path);
  strcpy(path_copy, path);
  if (!(_file_completion_3(buf, buf_2, path, cmd)) || !(dir = opendir(buf_2)))
    return (NULL);
  if (path[strlen(path) - 1] != '/')
    strcat(path, "/");
  while ((d = readdir(dir)))
    {
      _file_completion_1(buf, d->d_name, cmd, buf_2);
      add_slash_to_buf_if_dir_without_conc(buf, buf_2);
      if (strncmp(cmd, buf_2, strlen(cmd)) == 0 && d->d_name[0] != '.')
	put_in_list(buf, &st_list, 0);
    }
  return (_close_and_return(st_list, dir, d));
}
