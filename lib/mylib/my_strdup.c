/*
** my_strdup.c for my_strdup.C in /u/all/jorge_d/cu/rendu/c/minishell1/lib
**
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
**
** Started on  Tue Jan  5 20:29:59 2010 dimitri jorge
** Last update Sat May 22 14:40:08 2010 fares sabbagh
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include "lib.h"

char	*my_strdup(char *dest, char *src)
{
  int	i;

  i = 0;
  if (src == NULL)
    return (0);
  if (src)
    dest = xcalloc((my_strlen(src) + 1), sizeof(*dest));
  return (dest);
}
