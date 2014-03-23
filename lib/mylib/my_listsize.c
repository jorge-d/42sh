/*
** my.h for my_printf in /u/all/strzel_a/cu/rendu/c/my_printf
** 
** Made by alexandre strzelewicz
** Login   <strzel_a@epitech.net>
** 
** Started on  Mon Nov  9 11:50:26 2009 alexandre strzelewicz
** Last update Thu Apr 15 22:45:28 2010 julien di-marco
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"lib.h"

int		list_size(t_list *f_store)
{
  int		count;

  count = 0;
  while (f_store)
    {
      count++;
      f_store = f_store->next;
    }
  return (count);
}
