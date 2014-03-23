/*
** free_struct.c for dsf in /u/epitech_2014/strzel_a/cu
** 
** Made by alexandre strzelewicz
** Login   <strzel_a@epitech.net>
** 
** Started on  Sat May 15 11:33:52 2010 alexandre strzelewicz
** Last update Thu May 20 23:04:49 2010 julien di-marco
*/

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include "42sh.h"
#include "parserll.h"
#include "lib.h"

void		free_alias(t_alias *st_alias)
{
  t_alias	*tmp;

  while (st_alias)
    {
      tmp = st_alias;
      st_alias = st_alias->next;
      xfree(tmp->alias);
      xfree(tmp->cmd);
      xfree(tmp);
    }
}

void		free_history(t_hist *st_hist)
{
  t_hist	*tmp;

  while (st_hist)
    {
      tmp = st_hist;
      st_hist = st_hist->prev;
      xfree(tmp->line);
      xfree(tmp);
    }
}

void		free_hreact(t_hreact *st_hreact)
{
  int		i;
  t_hreact_cmd	tmp;

  i = 0;
  while (st_hreact && st_hreact->cmd && st_hreact->cmd[i].spe_cmd)
    {
      tmp = st_hreact->cmd[i];
      xfree(tmp.spe_cmd);
      i++;
    }
  if (st_hreact && st_hreact->cmd)
    xfree(st_hreact->cmd);
  if (st_hreact)
    xfree(st_hreact);
}
