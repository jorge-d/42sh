/*
** my_strncpy.c for 42sh in /u/all/jorge_d/cu/svn/42shsvn/trunk/lib
** 
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
** 
** Started on  Sun May 23 16:07:20 2010 dimitri jorge
** Last update Sun May 23 16:07:21 2010 dimitri jorge
*/

#include <unistd.h>
#include <stdlib.h>

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while (src[i])
    {
      if (i == n)
	{
	  dest[i] = '\0';
	  return (dest);
	}
      else
	dest[i] = src[i];
      i++;
    }
  return (dest);
}

