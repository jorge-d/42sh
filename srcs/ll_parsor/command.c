/*
** command.c for  in /u/all/shkurt_j/svn/parserll/trunk
**
** Made by joni shkurti
** Login   <shkurt_j@epitech.net>
**
** Started on  Sun May  2 04:12:47 2010 joni shkurti
** Last update Tue Jun  1 18:54:08 2010 julien di-marco
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <42sh.h>

static char	**tab_cpy(char **src, int len)
{
  int		i;
  char		**dest;

  i = 0;
  dest = NULL;
  if (!(dest = xmalloc((len + 1) * sizeof(*dest))))
    return (NULL);
  while (i < len)
    {
      if (!(dest[i] = strdup(src[i])))
	{
	  free_table(dest);
	  return (NULL);
	}
      i++;
    }
  dest[i] = NULL;
  return (dest);
}

t_bool		command_exp(t_tree **tree, t_token *t)
{
  t_tree	*new;

  if (cmd_exp(tree, t))
    {
      if (!alloc_tree(&new, *tree))
	return (FALSE);
      new->type = IS_CMD;
      new->cmd.len = 1;
      new->cmd.args = &(t->board[t->i++]);
      while (args_exp(tree, t) && t->i++)
	new->cmd.len++;
      if (!(new->args = tab_cpy(new->cmd.args, new->cmd.len)))
	return (FALSE);
      *tree = new;
      return (TRUE);
    }
  return (FALSE);
}

t_bool		cmd_exp(t_tree **tree, t_token *t)
{
  (void)tree;
  if (t->board[t->i] && !is_redir_or_sep(t->board[t->i]))
    return (TRUE);
  return (FALSE);
}

t_bool		args_exp(t_tree **tree, t_token *t)
{
  return (cmd_exp(tree, t));
}

t_bool		file_exp(t_tree **tree, t_token *t)
{
  t_tree	*new;

  if (!is_redir_or_sep(t->board[t->i]))
    {
      if (!alloc_tree(&new, *tree))
	return (FALSE);
      new->type = IS_FILE;
      new->cmd.len = 1;
      new->cmd.args = &(t->board[t->i++]);
      if (!(new->args = tab_cpy(new->cmd.args, new->cmd.len)))
	return (FALSE);
      *tree = new;
      return (TRUE);
    }
  return (FALSE);
}
