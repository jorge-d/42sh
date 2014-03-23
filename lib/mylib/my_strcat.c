/*
** my_strcat.c for strcat in /u/all/strzel_a/cu/rendu/lib/my
** 
** Made by alexandre strzelewicz
** Login   <strzel_a@epitech.net>
** 
** Started on  Wed Oct 14 10:51:19 2009 alexandre strzelewicz
** Last update Sun Apr 25 20:56:33 2010 dimitri jorge
*/

#include <unistd.h>
#include <stdlib.h>
#include "lib.h"

char	*my_strcat(char *str1, char *str2)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str1[i])
    i++;
  while (str2[j])
    str1[i++] = str2[j++];
  str1[i] = '\0';
  return (str1);
}



