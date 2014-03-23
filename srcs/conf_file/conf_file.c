/*
** conf_file.c for 42sh in /u/all/jorge_d/cu/svn/42shsvn/trunk
** 
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
** 
** Started on  Tue May 18 22:27:13 2010 dimitri jorge
** Last update Thu May 20 18:51:14 2010 julien di-marco
*/

#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "42sh.h"
#include "builtins.h"
#include "set_environ.h"
#include "alias_glob.h"

void		exec_line(char *cmd, t_shell *st_shell)
{
  lexor_and_parsor(cmd, st_shell);
  main_execution(st_shell);
}

static int	access_conf(const char *path)
{
  int		a;

  a = 0;
  if ((a = access(path, F_OK)) == -1)
    return (a);
  else if ((a = access(path, R_OK)) == -1)
    return (a);
  return (a);
}

int		read_file(t_shell *stShell)
{
  int		fd;
  char		*buffer;
  char		*filepath;

  buffer = NULL;
  if (!(filepath = get_set_from_list("CONF_FILE")))
    return (RT_FAILURE);
  if (access_conf(filepath) != -1 && (fd = open(filepath, O_RDONLY)) != -1)
    {
      while ((buffer = get_next_line(fd)))
	{
	  if (buffer[0] && buffer[strlen(buffer)] == '\0' && buffer[0] != '#')
	      exec_line(buffer, stShell);
	  else
	    xfree(buffer);
	}
      xclose(fd);
      return (RT_SUCCESS);
    }
  return (RT_FAILURE);
}
