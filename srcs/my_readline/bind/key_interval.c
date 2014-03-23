/*
** key_interval.c for Key Interval Functions in /u/all/di-mar_j/cu/svn/VSHsvn/branches/my_readline/new/bind
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Wed May  5 18:28:50 2010 julien di-marco
** Last update Sun May 23 03:22:29 2010 julien di-marco
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	"lib.h"
#include	"my_readline.h"

/*
** Key inter search - call by key inter - Not user
** -> i call compare_inter
** give me 2 (key[,2]), and i check if those exist in (bind)
** i return:
** -1 : when error occurs
** 0  : When no match find
** 1  : when a basic (1 key) bind match with this interval (key[,2])
** 2  : When a key interval match with this interval (key[,2])
**
*/

static int		compare_inter(char *key, char *key2, t_bind *bind)
{
  if (bind && key && key2)
    {
      if (CHCK(bind->flags, INTER) && bind->key && bind->key2)
	{
	  if (((strcmh(key, bind->key) == 0) && \
	       (strcml(key, bind->key2) == 0)) \
	      || ((strcmh(key2, bind->key) == 0) && \
		  (strcml(key2, bind->key2) == 0)))
	    return (2);
	}
      else if (bind->key && ((strcmh(bind->key, key) == 0) && \
			     (strcml(bind->key, key2) == 0)))
	return (1);
      return (0);
    }
  return (-1);
}

int		key_inter_search(char *key, char *key2, t_bdb **bind)
{
  t_bdb		*head;
  t_bind	*info;
  int		value;

  head = *bind;
  while (*bind)
    {
      if ((info = (*bind)->keybind) && \
	  ((value = compare_inter(key, key2, info)) > 0))
	{
	  if ((CHCK(info->flags, LOCK)))
	    {
	      fprintf(stderr, "INTER is locked\n");
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
** Create_inter - Call by Key Interal - Not USER
** Key interval call me if Key_inter_search return 0.
** create a new interval at the end of the database,
** i do not make sure that the key do not exist, it the role of key_inter &
** key_inter_search. - Yeah i'am idiot.
*/

int		create_inter(char *key, char *key2, t_bind *bind, t_bdb **foot)
{
  if ((*foot) && (*foot)->next)
    fprintf(stderr, "Error, not at the end of the bind keys database\n");
  else
    {
      if (!(bind->key = strdup(key)) || !(bind->key2 = strdup(key2)))
	fprintf(stderr, "Error allocate memory\n");
      else
	{
	  bind->flags = INTER;
	  if (!(add_list(foot, bind)))
	    {
	      xfree(bind->key);
	      xfree(bind->key2);
	    }
	  else
	    return (EXIT_SUCCESS);
	}
    }
  xfree(bind);
  rev_list(foot);
  return (EXIT_FAILURE);
}

