/*
** redir.c for  in /u/all/shkurt_j/svn/parserll/trunk
** 
** Made by joni shkurti
** Login   <shkurt_j@epitech.net>
** 
** Started on  Sun May  2 04:12:38 2010 joni shkurti
** Last update Thu May 13 13:51:35 2010 julien di-marco
*/

#include <string.h>
#include "parserll.h"

t_bool		redir_exp(t_tree **tree, t_token *t)
{
  int		bkup;

  bkup = t->i;
  if (!redir_left_norm(tree, t))
    {
      t->i = bkup;
      if (!redir_left_spe(tree, t))
	return (FALSE);
    }
  return (TRUE);
}

t_bool		redir_left_norm(t_tree **tree, t_token *t)
{
  t_bool	ret;
  t_tree	*new;

  if (redir_right(tree, t))
    {
      if (t->board[t->i])
	if (is_left_redir(t->board[t->i]))
	  {
	    if (!alloc_tree(&new, *tree))
	      return (FALSE);
	    new->type = (!strcmp(t->board[t->i], D_LEFT_R))
	      ? IS_D_LEFT : IS_LEFT;
	    new->left = *tree;
	    *tree = new;
	    t->i++;
	    ret = file_exp(&(new->right), t);
	    while (args_exp(tree, t) && t->i++);
	    return ((is_right_redir(t->board[t->i]))
		    ? special_case(tree, t) : ret);
	  }
      return (TRUE);
    }
  return (FALSE);
}

t_bool		redir_left_spe(t_tree **tree, t_token *t)
{
  t_bool	ret;
  t_tree	*new;

  if (is_left_redir(t->board[t->i++]))
    if (file_exp(tree, t))
      {
	if (!alloc_tree(&new, *tree))
	  return (FALSE);
	new->type = (!strcmp(t->board[t->i - 2], D_LEFT_R))
	  ? IS_D_LEFT : IS_LEFT;
	new->right = *tree;
	*tree = new;
	ret = command_exp(&(new->left), t);
	return ((is_right_redir(t->board[t->i]))
		    ? special_case(tree, t) : ret);
      }
  return (FALSE);
}

t_bool		redir_right(t_tree **tree, t_token *t)
{
  int		bkup;

  bkup = t->i;
  if (!redir_right_norm(tree, t))
    {
      t->i = bkup;
      if (!redir_right_spe(tree, t))
	return (FALSE);
    }
  return (TRUE);
}

t_bool		redir_right_norm(t_tree **tree, t_token *t)
{
  t_bool	ret;
  t_tree	*new;

  if (command_exp(tree, t))
    {
      if (t->board[t->i])
	if (is_right_redir(t->board[t->i]))
	  {
	    if (!alloc_tree(&new, *tree))
	      return (FALSE);
	    new->type = (!strcmp(t->board[t->i], D_RIGHT_R))
	      ? IS_D_RIGHT : IS_RIGHT;
	    new->left = *tree;
	    *tree = new;
	    t->i++;
	    ret = file_exp(&(new->right), t);
	    while (args_exp(tree, t) && t->i++);
	    return (ret);
	  }
      return (TRUE);
    }
  return (FALSE);
}
