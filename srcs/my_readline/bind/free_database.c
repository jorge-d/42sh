/*
** free_database.c for Free Bind Database in /u/all/di-mar_j/cu/svn/VSHsvn/branches/my_readline/bind
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Tue May 11 13:40:36 2010 julien di-marco
** Last update Sun May 23 03:21:55 2010 julien di-marco
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"lib.h"
#include	"my_readline.h"

int		free_database(t_bdb **head)
{
  t_bind	*bind;
  t_bdb		*tmp;

  tmp = NULL;
  while (*head)
    {
      if ((bind = (*head)->keybind))
	{
	  xfree(bind->key);
	  if (bind->key2)
	    xfree(bind->key2);
	  xfree(bind);
	}
      tmp = (*head)->next;
      xfree(*head);
      (*head) = tmp;
    }
  *head = NULL;
  return (1);
}
