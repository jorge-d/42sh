/*
** my_strncat.c for my_strncat.c in /u/all/strzel_a/cu/rendu/lib/my
** 
** Made by alexandre strzelewicz
** Login   <strzel_a@epitech.net>
** 
** Started on  Wed Oct 14 10:52:16 2009 alexandre strzelewicz
** Last update Sun Apr 25 20:53:30 2010 dimitri jorge
*/

#include <unistd.h>
#include <stdlib.h>

char	*my_strncat(char *str1, char *str2, int n)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str1[i])
    i++;
  while (str2[j])
    {
      if (j == n)
	{
	  str1[i] = '\0';
	  return (str1);
	}
      str1[i++] = str2[j++];
    }
  str1[i] = '\0';
  return (str1);
}

