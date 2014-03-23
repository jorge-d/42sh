/*
** readstd.c for mysh in /u/all/strzel_a/cu/rendu/c/my_ls
**
** Made by alexandre strzelewicz
** Login   <strzel_a@epitech.net>
**
** Started on  Mon Dec  7 15:08:13 2009 alexandre strzelewicz
** Last update Tue May 11 23:21:06 2010 alexandre strzelewicz
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/param.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "42sh.h"
#include "auto_complete.h"

int		add_slash_to_buf_if_dir(char *buf, char *destbuf, char *path)
{
  struct stat	f_stat;
  char		bufconc[MAXPATHLEN];

  sprintf(bufconc, "%s%s", path, buf);
  if (lstat(bufconc, &f_stat) == -1)
    return (RT_FAILURE);
  if ((S_IFMT & f_stat.st_mode) == S_IFDIR ||
      (S_IFMT & f_stat.st_mode) == S_IFLNK)
    strcat(destbuf, "/");
  return (RT_SUCCESS);
}

int		add_slash_to_buf_if_dir_without_conc(char *buf, char *buf2)
{
  struct stat	f_stat;

  if (lstat(buf2, &f_stat) == -1)
    return (RT_FAILURE);
  if ((S_IFMT & f_stat.st_mode) == S_IFDIR ||
      (S_IFMT & f_stat.st_mode) == S_IFLNK)
    strcat(buf, "/");
  return (RT_SUCCESS);
}
