/*
** my_tabcpy.c for tabcpy in /u/all/jorge_d/cu/rendu/c/42sh
**
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
**
** Started on  Fri Apr  2 17:22:43 2010 dimitri jorge
** Last update Sat May 22 14:29:36 2010 fares sabbagh
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

char	**my_tabcpy(char **board)
{
  char	**new;
  int	i;

  i = 0;
  new = xcalloc((my_tablen(board) + 1), sizeof(*new));
  while (board[i])
    {
      new[i] = xcalloc((my_strlen(board[i] + 1)), sizeof(*new));
      new[i] = strcpy(new[i], board[i]);
      i++;
    }
  new[i] = NULL;
  return (new);
}
