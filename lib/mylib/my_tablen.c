/*
** my_tablen.c for my_tablen in /u/all/jorge_d/cu/rendu/c/42sh/src/env
** 
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
** 
** Started on  Fri Apr  2 15:58:34 2010 dimitri jorge
** Last update Sun Apr 25 20:50:58 2010 dimitri jorge
*/

#include <unistd.h>
#include <stdlib.h>

int	my_tablen(char **tab)
{
  int	i;

  i = 0;
  while (tab && tab[i])
    i++;
  return (i);
}
