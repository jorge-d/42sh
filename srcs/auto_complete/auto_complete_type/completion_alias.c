/*
** readstd.c for mysh in /u/all/strzel_a/cu/rendu/c/my_ls
**
** Made by alexandre strzelewicz
** Login   <strzel_a@epitech.net>
**
** Started on  Mon Dec  7 15:08:13 2009 alexandre strzelewicz
** Last update Tue May 18 18:26:23 2010 dimitri jorge
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "42sh.h"
#include "my_readline.h"
#include "auto_complete.h"
#include "alias_glob.h"
#include "set_environ.h"

int	alias_completion(char *cmd, t_list **st_list, t_alias *st_alias)
{
  while (st_alias)
    {
      if (!strncmp(cmd, st_alias->alias, strlen(cmd)))
	put_in_list(st_alias->alias, st_list, 0);
      st_alias = st_alias->next;
    }
  return (TRUE);
}
