/*
** complicated_inter.c for Complicated range colision in /u/all/di-mar_j/cu/svn/VSHsvn/branches/my_readline/bind
**
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
**
** Started on  Sat May  8 14:39:54 2010 julien di-marco
** Last update Sun May 23 03:20:44 2010 julien di-marco
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	"my_readline.h"
#include	"lib.h"

/*
** Those fonctions help destructing the old interval,
** building the new interval, and building the new key !
**
*/

static int	separe_inter2(t_bind *new, t_bind_funct *func, t_bdb **foot)
{
  if (func && new)
    {
      new->func = func;
      new->flags = INTER;
      if (insert_list(foot, new))
	return (1);
    }
  return (0);
}

static int	reduce(t_bind *inter, t_bind *new, char *key)
{
  int		size;

  if (key)
    {
      xfree(inter->key2);
      if ((inter->key2 = strdup(key)) && (size = (strlen(key))))
	{
	  size -= 1;
	  if (key[size] > 0)
	    {
	      inter->key2[size] = key[size] - 1;
	      new->key[size] = key[size] + 1;
	      return (1);
	    }
	}
    }
  return (0);
}

static int	separe_inter(char *key, t_bdb **foot)
{
  t_bind	*inter;
  t_bind	*new;

  if ((*foot) && (inter = (*foot)->keybind))
    {
      if ((new = xcalloc(1, sizeof(*new))) && (new->func = inter->func))
	{
	  new->key = NULL;
	  new->key2 = NULL;
	  if ((new->key = strdup(key)) && \
	      (new->key2 = strdup(inter->key2)) && inter->key2)
	    {
	      if (reduce(inter, new, key) == 1)
		{
		  if (separe_inter2(new, inter->func, foot))
		    return (EXIT_SUCCESS);
		}
	    }
	  xfree(new->key);
	  xfree(new->key2);
	  xfree(new);
	}
    }
  return (EXIT_FAILURE);
}

/*
** Complicated inter - Call by Split INTER - NOT USER
** This functions take place when you wantto bind a key that is
** include in a bind range define early. So this fonction
** this the old range into two range and then bind the new key !
*/

int		complicated_inter(char *key, t_bind *bind, t_bdb **foot)
{
  t_bind	*inter;

  if ((*foot) && (inter = (*foot)->keybind))
    {
      if (!(bind->key = strdup(key)))
	fprintf(stderr, "Error allocate memory\n");
      else
	{
	  if (separe_inter(key, foot) == EXIT_SUCCESS)
	    {
	      bind->key2 = NULL;
	      bind->flags = 0;
	      if (!(insert_list(foot, bind)))
		xfree(bind->key);
	      else
		return (EXIT_SUCCESS);
	    }
	}
    }
  xfree(bind);
  return (EXIT_FAILURE);
}

