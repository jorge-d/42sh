/*
** add_list.c for Add a maille to the list ! in /u/all/di-mar_j/cu/svn/VSHsvn/branches/my_readline/new
**
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
**
** Started on  Wed Apr 21 22:56:27 2010 julien di-marco
** Last update Sat May 22 14:43:58 2010 fares sabbagh
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	"my_readline.h"
#include	"lib.h"

int		rev_list(t_bdb **foot)
{
  while (*foot && ((*foot)->prev))
    *foot = (*foot)->prev;
  return (0);
}

int		add_list(t_bdb **foot, t_bind *bind)
{
  t_bdb		*new;

  if ((new = xcalloc(1, sizeof(*new))))
    {
      new->next = NULL;
      if (!(*foot))
	new->prev = NULL;
      else
	{
	  new->prev = *foot;
	  (*foot)->next = new;
	}
      new->keybind = bind;
      *foot = new;
      rev_list(foot);
      return (1);
    }
  rev_list(foot);
  fprintf(stderr, "Error allocate memory\n");
  return (0);
}
