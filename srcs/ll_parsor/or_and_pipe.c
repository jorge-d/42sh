/*
** or_and_pipe.c for  in /u/all/shkurt_j/svn/parserll/trunk
**
** Made by joni shkurti
** Login   <shkurt_j@epitech.net>
**
** Started on  Sun May  2 04:12:00 2010 joni shkurti
** Last update Thu Jun  3 11:58:00 2010 dimitri jorge
*/

#include <string.h>
#include "parserll.h"

t_bool		expression(t_tree **tree, t_token *t)
{
  return (or_exp(tree, t));
}

t_bool		or_exp(t_tree **tree, t_token *t)
{
  t_tree	*new;

  if (and_exp(tree, t))
    {
      if (t->board[t->i])
	if (!strcmp(t->board[t->i], OR_BIN))
	  {
	    t->i++;
	    if (!alloc_tree(&new, *tree))
	      return (FALSE);
	    new->type = IS_OR;
	    new->left = *tree;
	    *tree = new;
	    return (or_exp(&(new->right), t));
	  }
	else
	  return (FALSE);
      else
	return (TRUE);
    }
  return (FALSE);
}

t_bool		and_exp(t_tree **tree, t_token *t)
{
  t_tree	*new;

  if (pipe_exp(tree, t))
    {
      if (t->board[t->i])
	if (!strcmp(t->board[t->i], AND_BIN))
	  {
	    t->i++;
	    if (!alloc_tree(&new, *tree))
	      return (FALSE);
	    new->type = IS_AND;
	    new->left = *tree;
	    *tree = new;
	    return (and_exp(&(new->right), t));
	  }
      return (TRUE);
    }
  return (FALSE);
}

t_bool		pipe_exp(t_tree **tree, t_token *t)
{
  t_tree	*new;

  if (redir_exp(tree, t))
    {
      if (t->board[t->i])
	if (!strcmp(t->board[t->i], PIPE))
	  {
	    t->i++;
	    if (!alloc_tree(&new, *tree))
	      return (FALSE);
	    new->type = IS_PIPE;
	    new->right = *tree;
	    *tree = new;
	    return (pipe_exp(&(new->left), t));
	  }
      return (TRUE);
    }
  return (FALSE);
}

t_bool		redir_right_spe(t_tree **tree, t_token *t)
{
  t_tree	*new;

  if (is_right_redir(t->board[t->i++]))
    if (file_exp(tree, t))
      {
	if (!alloc_tree(&new, *tree))
	  return (FALSE);
	new->type = (!strcmp(t->board[t->i - 2], D_RIGHT_R))
	  ? IS_D_RIGHT : IS_RIGHT;
	new->right = *tree;
	*tree = new;
	return (command_exp(&(new->left), t));
      }
  return (FALSE);
}
