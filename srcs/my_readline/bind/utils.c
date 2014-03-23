/*
** utils.c for utils functions for both of interval & keys in /u/all/di-mar_j/cu/svn/VSHsvn/branches/my_readline/new/bind
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Wed May  5 18:34:46 2010 julien di-marco
** Last update Thu May  6 01:34:24 2010 julien di-marco
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	"my_readline.h"

int		db_corrupt(t_bdb *head, t_bdb **bind)
{
  fprintf(stderr, E_BDB_CORUPT);
  *bind = head;
  return (-1);
}

int		key_sub(char *key)
{
  int		i;
  int		out;

  i = 1;
  out = key[0];
  while (key[i])
    out -= key[i++];
  return (out);
}
