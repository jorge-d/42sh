/*
** alias_funcs.c for sdf in /u/epitech_2014/strzel_a/cu
**
** Made by alexandre strzelewicz
** Login   <strzel_a@epitech.net>
**
** Started on  Wed May 12 15:52:58 2010 alexandre strzelewicz
** Last update Sat Jun 12 13:31:50 2010 julien di-marco
*/

#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "42sh.h"
#include "set_environ.h"
#include "alias_glob.h"

int		put_alias_in_list(t_alias **begin, char *alias, char *cmd)
{
  t_alias	*new;
  t_alias	*parse;

  if (alias && cmd && (new = xcalloc(1, sizeof(*new))))
    {
      if ((new->alias = strdup(alias)) && (new->cmd = strdup(cmd)))
	{
	  new->next = NULL;
	  if (!(parse = *begin))
	    {
	      new->prev = NULL;
	      *begin = new;
	    }
	  else
	    {
	      while (parse->next)
		parse = parse->next;
	      parse->next = new;
	      new->prev = parse;
	    }
	}
      else
	free(new);
    }
  return (EXIT_FAILURE);
}

int		remove_alias_from_list(t_alias **st_alias)
{
  t_alias	*back;

  if (st_alias && (back = *st_alias))
    {
      xfree(back->cmd);
      xfree(back->alias);
      if (back->prev)
	back->prev->next = back->next;
      if (back->next)
	back->next->prev = back->prev;
      if (back->prev)
	*st_alias = back->prev;
      else
	*st_alias = back->next;
      return (EXIT_SUCCESS);
    }
  return (EXIT_FAILURE);
}
