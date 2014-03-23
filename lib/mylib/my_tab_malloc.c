/*
** my_tab_malloc.c for 42sh in /u/all/jorge_d/cu/svn/42shsvn/trunk/lib
** 
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
** 
** Started on  Sun May 23 16:07:08 2010 dimitri jorge
** Last update Sun May 23 16:07:09 2010 dimitri jorge
*/

#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include "lib.h"

char	**malloc_table(char **board, char *str, int words)
{
  int	len;
  int	count;

  len = my_strlen(str);
  board = xcalloc((words + 1), sizeof(*board));
  if (!board)
    return (NULL);
  count = 0;
  while (count < words)
    {
      board[count] = xcalloc((len + 1), sizeof(*board));
      if (!board[count])
	{
	  free_table(board);
	  return (NULL);
	}
      count++;
    }
  return (board);
}
