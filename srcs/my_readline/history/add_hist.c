/*
** add_hist.c for History FUCK ERASE MAGIC O.o in /u/all/di-mar_j/cu/svn/42shsvn/trunk
**
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
**
** Started on  Tue May 18 19:26:18 2010 julien di-marco
** Last update Sun May 23 16:13:43 2010 dimitri jorge
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	"my_readline.h"
#include	"42sh.h"
#include	"set_environ.h"

static void	_free_old_(t_hist *back)
{
  xfree(back->line);
  xfree(back);
}

int		hist_limit(t_hist **hist)
{
  t_hist	*back;
  char		*ret;
  int		i;

  i = 0;
  back = NULL;
  while (*hist && (*hist)->next)
    *hist = (*hist)->next;
  if ((*hist) && (ret = get_set_from_list("HISTSIZE")))
    {
      if (((i = atoi(ret)) > 0) && (i < (*hist)->i))
	{
	  while (*hist && (*hist)->prev)
	    *hist = (*hist)->prev;
	  back = *hist;
	  *hist = (*hist)->next;
	  (*hist)->prev = NULL;
	  _free_old_(back);
	  while (*hist && (*hist)->next)
	    *hist = (*hist)->next;
	}
      else if ((i == 0))
	return (-1);
    }
  return (0);
}

int		put_in_hist_list(t_hist **hist, char *line)
{
  t_hist	*new;

  if (hist && line && (hist_limit(hist) != -1) \
      && (new = xcalloc(1, sizeof(*new))))
    {
      if ((new->line = strdup(line)))
	{
	  new->next = NULL;
	  new->i = 1;
	  new->aff = H_UNDEFINE;
	  if (!(*hist))
	    new->prev = NULL;
	  else
	    {
	      new->prev = *hist;
	      if ((new->i = ((*hist)->i + 1)) < 0)
		new->i = 0;
	      (*hist)->next = new;
	    }
	  *hist = new;
	  return (1);
	}
      xfree(new);
    }
  return (0);
}
