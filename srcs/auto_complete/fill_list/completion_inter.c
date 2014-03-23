/*
** readstd.c for mysh in /u/all/strzel_a/cu/rendu/c/my_ls
**
** Made by alexandre strzelewicz
** Login   <strzel_a@epitech.net>
**
** Started on  Mon Dec  7 15:08:13 2009 alexandre strzelewicz
** Last update Tue May 11 23:27:22 2010 alexandre strzelewicz
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

int	concatenate_file(char *dest_str, char *src_str, char *to_add)
{
  memset(dest_str, '\0', MAXPATHLEN - 1);
  strcpy(dest_str, src_str);
  my_strcat(dest_str, to_add);
  return (0);
}

int	xfree_completion(char *st1, char *st2, char *st3, \
			 t_list **st_list)
{
  xfree(st1);
  xfree(st2);
  xfree(st3);
  free_st_list(*st_list);
  return (0);
}

int	free_st_list(t_list *st_list)
{
  while (st_list)
    {
      xfree(st_list->data);
      st_list = st_list->previous;
    }
  xfree(st_list);
  return (0);
}
