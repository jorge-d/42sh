/*
** my_str_to_wordtab.c for mystrtowordtab in /u/all/strzel_a/cu/rendu/piscine/Jour_08
** 
** Made by alexandre strzelewicz
** Login   <strzel_a@epitech.net>
** 
** Started on  Fri Oct 16 14:56:35 2009 alexandre strzelewicz
** Last update Sun Apr 25 20:56:37 2010 dimitri jorge
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"lib.h"

int	my_show_to_wordtab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      my_putstr(tab[i]);
      my_putchar('\n');
      i++;
    }
  return (0);
}

