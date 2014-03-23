/*
** readstd.c for mysh in /u/all/strzel_a/cu/rendu/c/my_ls
**
** Made by alexandre strzelewicz
** Login   <strzel_a@epitech.net>
**
** Started on  Mon Dec  7 15:08:13 2009 alexandre strzelewicz
** Last update Sun May 23 15:43:27 2010 dimitri jorge
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/param.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "42sh.h"
#include "auto_complete.h"

int		my_put_in_list_disp(t_list **st_list, char *data,
				    int type)
{
  t_list	*the_previous;
  t_list	*new;
  t_list	*the_next;

  new = NULL;
  the_next = NULL;
  the_previous = *st_list;
  if (the_previous != NULL)
    the_next = the_previous->next;
  if (!(new = xcalloc(1, sizeof(*new))))
    {
      xfree(data);
      return (0);
    }
  new->data = data;
  new->type = type;
  new->next = the_next;
  if (the_next != NULL)
    the_next->previous = new;
  new->previous = the_previous;
  if (the_previous != NULL)
    the_previous->next = new;
  *st_list = new;
  return (0);
}

int		put_in_list(char *file, t_list **st_list, int type)
{
  char		*new_elem;

  new_elem = xcalloc((my_strlen(file) + 5), sizeof(*new_elem));
  if (!new_elem)
    return (0);
  strncpy(new_elem, file, my_strlen(file) + 1);
  my_put_in_list_disp(st_list, new_elem, type);
  return (0);
}
