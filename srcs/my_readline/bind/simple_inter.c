/*
** simple_inter.c for Here function call by split_inter ! in /Users/lifely/Developer/project/VSHsvn/branches/my_readline/new/bind
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu May  6 01:19:16 2010 julien di-marco
** Last update Sun May 23 03:22:07 2010 julien di-marco
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	"lib.h"
#include	"my_readline.h"

/*
** Merge Left - Merge Right - call by split inter - NOT USER
** Those functions enter in action when you bind conflict with a previous
** range bind if your new bind is one of the side of this range
** Example:
** "A" - "Z" --> self-insert
** "A"       --> backward-delete
** Will be:
** "B" - "z" --> self-insert
** "A"       --> backward-delete
*/

int		merge_left_inter(char *key, t_bind *bind, t_bdb **foot)
{
  int		size;
  t_bind	*inter;

  if ((*foot) && (inter = (*foot)->keybind))
    {
      if (!(bind->key = strdup(key)))
	fprintf(stderr, "Error allocate memory\n");
      else
	{
	  if (inter->key)
	    size = strlen(inter->key) - 1;
	  if (inter->key && (inter->key[size] > 0))
	    inter->key[size] = (inter->key[size] + 1);
	  bind->key2 = NULL;
	  bind->flags = 0;
	  if (!(insert_list(foot, bind)))
	    xfree(bind->key);
	  else
	    return (EXIT_SUCCESS);
	}
    }
  xfree(bind);
  return (EXIT_FAILURE);
}

int		merge_right_inter(char *key, t_bind *bind, t_bdb **foot)
{
  int		size;
  t_bind	*inter;

  if ((*foot) && (inter = (*foot)->keybind))
    {
      if (!(bind->key = strdup(key)))
	fprintf(stderr, "Error allocate memory\n");
      else
	{
	  if (inter->key2)
	    size = strlen(inter->key2) - 1;
	  if (inter->key2 && (inter->key2[size] > 0))
	    inter->key2[size] = (inter->key2[size] - 1);
	  bind->key2 = NULL;
	  bind->flags = 0;
	  if (!(insert_list(foot, bind)))
	      xfree(bind->key);
	  else
	    return (EXIT_SUCCESS);
	}
    }
  xfree(bind);
  return (EXIT_FAILURE);
}
