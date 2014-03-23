/*
** show_bind.c for Show Bind list in /u/all/di-mar_j/cu/svn/VSHsvn/branches/my_readline/new
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Apr 22 15:13:44 2010 julien di-marco
** Last update Sat May 22 20:40:16 2010 julien di-marco
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	"my_readline.h"

int		show_bind(t_bdb *head)
{
  t_bind	*info;

  if (head && !(head->prev))
    {
      while (head)
	{
	  if ((info = head->keybind))
	    {
	      if (info->key && info->key2 && info->func)
		fprintf(stdout, "\"%s\" to \"%s\"\t %s\n", info->key, \
			info->key2,info->func->name);
	      else if (info->key && info->func)
		fprintf(stdout, "\"%s\"\t\t %s\n", info->key, info->func->name);
	      head = head->next;
	    }
	  else
	    {
	      fprintf(stderr, E_BDB_CORUPT);
	      return (EXIT_FAILURE);
	    }
	}
    }
  else if (!head)
    fprintf(stderr, "bind Database empty !\n");
  return (EXIT_SUCCESS);
}
