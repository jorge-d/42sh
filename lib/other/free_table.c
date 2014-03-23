/*
** free_table.c for vsh in /u/all/jorge_d/svn/VSHsvn/trunk/lib
** 
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
** 
** Started on  Wed Mar 31 12:15:26 2010 dimitri jorge
** Last update Wed May 19 17:58:19 2010 julien di-marco
*/

#include "lib.h"

void	free_table(char **board)
{
  int	i;

  i = 0;
  if (board)
    {
      while (board[i])
	xfree(board[i++]);
      xfree(board);
    }
}
