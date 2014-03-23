/*
** simple_key.c for Header in /u/all/di-mar_j/cu/svn/VSHsvn/branches/my_readline/new/bind
**
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
**
** Started on  Wed May  5 18:27:18 2010 julien di-marco
** Last update Sun May 23 03:22:20 2010 julien di-marco
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	"lib.h"
#include	"my_readline.h"

/*
** Key Search - Call compare key - NOT USER
** Key search search for matching bind in the bind database
** compare to key. it return a value, an inportant value
**-1  : When error occurs
** 0  : When there is no match (key do not exist)
** 1  : When the key already exist (key match in the databases)
** 2  : The key make part of an interval.
*/

static int	compare_key(char *key, t_bind *bind)
{
  if (bind && key)
    {
      if (CHCK(bind->flags, INTER) && bind->key && bind->key2)
	{
	  if ((strcmh(key, bind->key) == 0) && \
	      (strcml(key, bind->key2) == 0))
	    return (2);
	}
      else if (key && bind->key && !strcmp(bind->key, key))
	return (1);
      return (0);
    }
  return (-1);
}

int		key_search(char *key, t_bdb **bind)
{
  t_bdb		*head;
  t_bind	*info;
  int		value;

  head = *bind;
  while (*bind)
    {
      if ((info = (*bind)->keybind) && ((value = compare_key(key, info)) > 0))
	{
	  if ((CHCK(info->flags, LOCK)))
	    {
	      fprintf(stderr, "Key is locked\n");
	      *bind = head;
	      return (-1);
	    }
	  return (value);
	}
      else if (!info || (value == -1))
	return (db_corrupt(head, bind));
      if (!(*bind)->next)
	return (0);
      *bind = (*bind)->next;
    }
  return (0);
}

/*
** Create Key - Call by simple Key - NOT USER
** Create key create the key in the database (at the end of it)
** This function do not take care of the database it create it
** this function rewind (reverse) the database
*/

int		create_key(char *key, t_bind *bind, t_bdb **foot)
{
  if ((*foot) && (*foot)->next)
    fprintf(stderr, "Error, not at the end of the bind keys database\n");
  else
    {
      if (!(bind->key = strdup(key)))
	fprintf(stderr, "Error allocate memory\n");
      else
	{
	  bind->key2 = NULL;
	  bind->flags = 0;
	  if (!(add_list(foot, bind)))
	      xfree(bind->key);
	  else
	    return (EXIT_SUCCESS);
	}
    }
  xfree(bind);
  rev_list(foot);
  return (EXIT_FAILURE);
}

/*
** Mod Key - Call by Simple Key - NOT UERR
** mod key modify the bind in the actual bind database [maille]
** by the key given.
** This function rewind the bind database
*/

int		mod_key(char *key, t_bind *bind, t_bdb **foot)
{
  t_bind	*old;

  if ((*foot) && (old = (*foot)->keybind))
    {
      if (!(bind->key = strdup(key)))
	fprintf(stderr, "Error allocate memory\n");
      else
	{
	  xfree(old->key);
	  xfree(old);
	  bind->key2 = NULL;
	  bind->flags = 0;
	  (*foot)->keybind = bind;
	  rev_list(foot);
	  return (EXIT_SUCCESS);
	}
    }
  else
    fprintf(stderr, E_BDB_CORUPT);
  xfree(bind);
  rev_list(foot);
  return (EXIT_FAILURE);
}

/*
** Split Inter - Call by simple Key - NOT USER --> See ./simple_inter
** Inportant function, assure the conflit between new key
** & interval !
** if the key is one of the oposite of the interval
**   -> Call Merge_left_inter
**   -> Or Call Merge_right_inter
** otherwise it a complicated situation we need to split everything
**   -> Call Complicated Inter
*/

int		split_inter(char *key, t_bind *new, t_bdb **foot)
{
  t_bind	*inter;

  if ((*foot) && (inter = (*foot)->keybind))
    {
      if (inter->key && key && !(strcmp(inter->key, key)))
	merge_left_inter(key, new, foot);
      else if (inter->key2 && key && !(strcmp(inter->key2, key)))
	merge_right_inter(key, new, foot);
      else
	complicated_inter(key, new, foot);
    }
  else
    {
      xfree(new);
      rev_list(foot);
      return (EXIT_FAILURE);
    }
  rev_list(foot);
  return (EXIT_SUCCESS);
}
