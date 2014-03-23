/*
** my.h for my_printf in /u/all/strzel_a/cu/rendu/c/my_printf
**
** Made by alexandre strzelewicz
** Login   <strzel_a@epitech.net>
**
** Started on  Mon Nov  9 11:50:26 2009 alexandre strzelewicz
** Last update Sat May 22 16:24:01 2010 alexandre strzelewicz
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/param.h>
#include <sys/types.h>
#include <dirent.h>
#include "42sh.h"
#include "parserll.h"
#include "builtins.h"
#include "set_environ.h"
#include "my_readline.h"
#include "hreact.h"

#ifdef		__HREACT_ON__

int		check_if_too_much_files(void)
{
  char		*path;
  DIR		*dir;
  int		i;
  struct dirent *d;

  i = 0;
  path = NULL;
  if (!(path = getcwd(path, MAXPATHLEN)))
    return (FALSE);
  if (!(dir = opendir(path)))
    return (FALSE);
  while ((d = readdir(dir)) && i < MAX_FILE_DISP)
    if (d->d_name && d->d_name[0] != '.')
      i++;
  xclosedir(dir);
  xfree(path);
  if (i >= MAX_FILE_DISP)
    return (FALSE);
  xfree(d);
  return (TRUE);
}

#endif		/* !__HREACT_ON__ */
