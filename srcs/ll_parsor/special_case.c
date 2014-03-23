/*
** special_case.c for  in /u/all/shkurt_j/svn/42shsvn/trunk/srcs/ll_parsor
** 
** Made by joni shkurti
** Login   <shkurt_j@epitech.net>
** 
** Started on  Tue May 11 18:17:43 2010 joni shkurti
** Last update Thu May 13 13:51:35 2010 julien di-marco
*/

#include <string.h>
#include "parserll.h"

t_bool		special_case(t_tree **tree, t_token *t)
{
  t_tree	*new;

  if (!alloc_tree(&new, *tree))
    return (FALSE);
  new->type = (!strcmp(t->board[t->i], D_RIGHT_R))
    ? IS_D_RIGHT : IS_RIGHT;
  new->left = *tree;
  *tree = new;
  t->i++;
  return (file_exp(&(new->right), t));
}

t_bool		alloc_tree(t_tree **new, t_tree *cur)
{
  if (!(*new = init_tree()))
    {
      free_tree(cur);
      return (FALSE);
    }
  return (TRUE);
}
