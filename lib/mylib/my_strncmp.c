/*
** my_strcmp.c for my_strcmp in /u/all/strzel_a/cu/rendu/piscine/Jour_06
** 
** Made by alexandre strzelewicz
** Login   <strzel_a@epitech.net>
** 
** Started on  Mon Oct 12 12:53:37 2009 alexandre strzelewicz
** Last update Sun Apr 25 20:53:20 2010 dimitri jorge
*/

#include <unistd.h>
#include <stdlib.h>

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  if (!(s1) || !(s2))
    return (-1);
  while (n-- > 0)
    {
      if (!s1[i] || !s2[i] || s1[i] != s2[i])
        return (s1[i] - s2[i]);
      i++;
    }
  return (0);

}
