/*
** my_strlen.c for exo3 in /u/all/strzel_a/cu/rendu/piscine/Jour_04
** 
** Made by alexandre strzelewicz
** Login   <strzel_a@epitech.net>
** 
** Started on  Thu Oct  8 10:54:07 2009 alexandre strzelewicz
** Last update Sun Apr 25 20:53:36 2010 dimitri jorge
*/

#include <stdlib.h>
#include <unistd.h>

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  if (str)
    while (str[i])
      i++;
  return (i);
}

