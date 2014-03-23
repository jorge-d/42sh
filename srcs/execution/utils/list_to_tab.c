/*
** list_to_tab.c for 42sh in /u/all/jorge_d/cu/svn/42shsvn/trunk/srcs/execution
** 
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
** 
** Started on  Tue May 11 18:30:45 2010 dimitri jorge
** Last update Sat May 22 13:27:16 2010 dimitri jorge
*/

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "parserll.h"
#include "42sh.h"

static int	_list_size(t_env *list)
{
  int		i;

  i = 0;
  while (list)
    {
      i++;
      list = list->next;
    }
  return (i);
}

char		**list_to_table(t_env *env)
{
  int		i;
  char		**board;
  int		j;

  j = 0;
  i = _list_size(env);
  if (i == 0)
    return (NULL);
  board = xcalloc((i + 1), sizeof(*board));
  if (!board)
    return (NULL);
  while (env)
    {
      board[j++] = env->var;
      env = env->next;
    }
  board[j] = NULL;
  return (board);
}
