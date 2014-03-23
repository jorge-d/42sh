/*
** my_strcpy.c for minishell in /u/all/jorge_d/cu/MINISHELL2
** 
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
** 
** Started on  Mon Jan 25 19:14:48 2010 dimitri jorge
** Last update Sun Apr 25 20:55:02 2010 dimitri jorge
*/

#include <unistd.h>
#include <stdlib.h>
#include "lib.h"

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  if (src == NULL)
    return (0);
  while (src[i])
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}
