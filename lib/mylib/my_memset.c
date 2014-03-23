/*
** my_memset.c for My Memset in /u/all/di-mar_j/svn/my_ls/xlib
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Dec 17 22:27:37 2009 julien di-marco
** Last update Sat Apr 17 18:21:58 2010 julien di-marco
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<sys/types.h>
#include	"lib.h"

void		*my_memset(void *b, int c, size_t len)
{
  unsigned int	i;

  i = 0;
  while (i < len)
    {
      ((char *)b)[i] = c;
      i++;
    }
  return (b);
}
