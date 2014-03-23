/*
** bindkey.c for Bind Key in /u/all/di-mar_j/cu/svn/VSHsvn/branches/my_readline/new/bind
**
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
**
** Started on  Sat May  1 14:35:17 2010 julien di-marco
** Last update Sat Jun 12 13:30:44 2010 julien di-marco
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	"lib.h"
#include	"my_readline.h"

/*
** Key Interval - Call by Function - Not USER
** Perform the bind of an interval.
** Example:
** "A" to "x" with funct : self-insert-command
*/

static int	key_interval(char *key, char *key2, \
				     t_bind_funct *func, t_bdb **head)
{
  t_bind	*new;
  int		value = 0;

  if ((new = xcalloc(1, sizeof(*new))) && (new->func = func))
    {
      if (key && key2)
	{
	  if ((value = key_inter_search(key, key2, head)) == 0)
	    return (create_inter(key, key2, new, head));
	}
      else
	fprintf(stderr, "42sh: Interval key must be only one caracter long\n");
      xfree(new);
    }
  return (EXIT_FAILURE);
}

/*
** Simple Key - Call by function - Not USER
** Perform a basic bind of one key.
** Example:
** "^L" with funct: clear-screen
*/

static int	simple_key(char *key, t_bind_funct *func, t_bdb **head)
{
  t_bind	*new;
  int		value;

  value = 0;
  new = NULL;
  if ((new = xcalloc(1, sizeof(*new))) && (new->func = func))
    {
      if ((value = key_search(key, head)) == 0)
	return (create_key(key, new, head));
      else if (value == 1)
	return (mod_key(key, new, head));
      else if (value == 2)
	return (split_inter(key, new, head));

    }
  xfree(new);
  return (EXIT_FAILURE);
}

/*
** Bind Key - Call by user or function
** Function to use to bind a key or a key interval, she choose wether it's a
** Simple Key or and interval.
** Example:
** bind_key("^L", NULL, "clean-screen", &database); -> call simple key
** bind_key("A", "x", "self-insert", &database); -> cal Key Interval
*/

int		bind_key(char *key, char *key2, char *name, t_bdb **head)
{
  t_bind_funct	*func;

  if ((func = get_func(name)))
    {
      if (key && key2)
	return (key_interval(key, key2, func, head));
      else if (key && !(key2))
	return (simple_key(key, func, head));
      else
	fprintf(stderr, "Enter Valid Key Please.\n");
    }
  return (EXIT_FAILURE);
}
