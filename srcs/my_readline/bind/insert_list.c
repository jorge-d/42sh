/*
** insert_list.c for Insert in middle of list ! in /u/all/di-mar_j/cu/svn/VSHsvn/branches/my_readline/new
**
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
**
** Started on  Mon May  3 13:52:55 2010 julien di-marco
** Last update Sat May 22 14:43:53 2010 fares sabbagh
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	"my_readline.h"
#include	"lib.h"

int		insert_list(t_bdb **foot, t_bind *bind)
{
  t_bdb		*new;
  t_bdb		*prev;

  prev = NULL;
  if ((new = xcalloc(1, sizeof(*new))))
    {
      if (!(*foot))
	{
	  new->next = NULL;
	  new->prev = NULL;
	}
      else
	{
	  new->prev = (*foot)->prev;
	  new->next = (*foot);
	  if ((prev = (*foot)->prev))
	    prev->next = new;
	  (*foot)->prev = new;
	}
      new->keybind = bind;
      *foot = new;
      return (1);
    }
  fprintf(stderr, "Error allocate memory\n");
  return (0);
}
