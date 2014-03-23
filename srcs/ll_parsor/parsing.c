/*
** parsing.c for 42sh in /u/all/shkurt_j/svn/parserll/trunk/src/parser
**
** Made by joni shkurti
** Login   <shkurt_j@epitech.net>
**
** Started on  Fri Apr 16 14:50:26 2010 joni shkurti
** Last update Sat May 22 13:28:52 2010 dimitri jorge
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "42sh.h"
#include "parserll.h"

t_tree		*init_tree(void)
{
  t_tree	*new;

  new = NULL;
  if ((new = xcalloc(1, sizeof(*new))))
    {
      new->next = NULL;
      new->right = NULL;
      new->left = NULL;
      new->args = NULL;
      new->full_path = NULL;
      new->cmd.args = NULL;
      new->cmd.len = 0;
      new->type = 0;
      new->fd_in = 0;
      new->fd_out = 1;
    }
  return (new);
}

static char	**separate_tree(char **board, int len, int flag)
{
  int		bckup;
  static int	i = (-1);

  if (flag)
    {
      i = (-1);
      return (NULL);
    }
  if (i < len)
    i++;
  while (board[i] && is_semi_colon(board[i]))
    i++;
  bckup = i;
  while (board[i])
    {
      if (is_semi_colon(board[i]))
	{
	  xfree(board[i]);
	  board[i] = NULL;
	  return (&board[bckup]);
	}
      i++;
    }
  return ((i == bckup) ? (NULL) : (&board[bckup]));
}

static void	free_board(char **board, int len)
{
  int		i;

  i = (-1);
  while (++i < len)
    xfree(board[i]);
  xfree(board);
}

static t_tree	*_reset(t_tree *tree, char **board, int len)
{
  if (tree)
    free_tree(tree);
  free_board(board, len);
  separate_tree((char**)NULL, 0, 1);
  return (NULL);
}

t_tree		*make_parsing(char **board)
{
  int		len;
  t_token	t;
  t_tree	*res;
  t_tree	*tmp;

  t.i = 0;
  res = NULL;
  len = my_tablen(board);
  if ((t.board = separate_tree(board, len, 0)) && !expression(&res, &t))
    return (_reset(res, board, len));
  tmp = res;
  while ((t.board = separate_tree(board, len, 0)))
    {
      t.i = 0;
      if (!expression(&(tmp->next), &t))
	return (_reset(tmp, board, len));
      tmp = tmp->next;
    }
  free_board(board, len);
  separate_tree((char**)NULL, 0, 1);
  return (res);
}
