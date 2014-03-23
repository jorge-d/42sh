/*
** my_put_in_list.c for 42sh in /u/all/jorge_d/cu/svn/42shsvn/trunk/srcs/initialisation
**
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
**
** Started on  Fri May  7 18:01:13 2010 dimitri jorge
** Last update Sat May 22 14:41:18 2010 fares sabbagh
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "42sh.h"
#include "set_environ.h"

void		set_env_to_set(void)
{
  char		*to_set[4];

  to_set[0] = "set";
  to_set[1] = "HOME";
  to_set[2] = NULL;
  to_set[3] = NULL;
  if ((to_set[2] = get_env_from_list("HOME")))
    set_new(to_set, NULL);
  to_set[1] = "USER";
  if ((to_set[2] = get_env_from_list("USER")))
    set_new(to_set, NULL);
  to_set[1] = "PATH";
  if ((to_set[2] = get_env_from_list("PATH")))
    set_new(to_set, NULL);
  to_set[1] = "HOST";
  if ((to_set[2] = get_env_from_list("HOST")))
    set_new(to_set, NULL);
}

void		my_put_in_list(t_env **begin, char *data)
{
  t_env		*new;
  t_env		*parse;

  if (!(new = xcalloc(1, sizeof(*new))))
    return ;
  if (!(new->var = xcalloc((my_strlen(data) + 1), sizeof(*data))))
    return ;
  new->var = my_strcpy(new->var, data);
  if (*begin == NULL)
    {
      new->prev = NULL;
      new->next = *begin;
      *begin = new;
    }
  else
    {
      parse = *begin;
      while (parse->next)
	parse = parse->next;
      parse->next = new;
      new->prev = parse;
      new->next = NULL;
    }
}
