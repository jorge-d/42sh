/*
** my_strcmp.c for my_strcmp in /u/all/strzel_a/cu/rendu/piscine/Jour_06
** 
** Made by alexandre strzelewicz
** Login   <strzel_a@epitech.net>
** 
** Started on  Mon Oct 12 12:53:37 2009 alexandre strzelewicz
** Last update Sun Apr 25 20:56:18 2010 dimitri jorge
*/

#include <stdlib.h>
#include <unistd.h>
#include "lib.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i])
    {
      if (s1[i] > s2[i])
	return (s1[i] - s2[i]);
      if (s1[i] < s2[i])
	return (s1[i] - s2[i]);
      i = i + 1;
    }
  if (s2[i])
    return (-1);
  return (0);
}
