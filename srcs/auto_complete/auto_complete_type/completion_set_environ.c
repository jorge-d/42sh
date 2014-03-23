/*
** readstd.c for mysh in /u/all/strzel_a/cu/rendu/c/my_ls
**
** Made by alexandre strzelewicz
** Login   <strzel_a@epitech.net>
**
** Started on  Mon Dec  7 15:08:13 2009 alexandre strzelewicz
** Last update Mon May 17 01:50:16 2010 alexandre strzelewicz
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

static void	get_value_before_equal(char *cmd, char *res)
{
  if (!cmd || !res)
    {
      fprintf(stderr, "Weird error in get_value_before_equal\n");
      return ;
    }
  while (*cmd && *cmd != '=')
    {
      *res = *cmd;
      res++;
      cmd++;
    }
  *res = 0;
}

int		set_environ_completion(char *cmd, t_list **st_list)
{
  char		buf[MAX_SET_SIZE];
  t_env		*tmp;

  tmp = gl_st.st_set;
  while (tmp)
    {
      get_value_before_equal(tmp->var, buf);
      if (!strncmp(cmd, buf, strlen(cmd)))
	put_in_list(buf, st_list, 0);
      tmp = tmp->next;
    }
  return (TRUE);
}
