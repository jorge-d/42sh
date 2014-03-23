/*
** my_setenv.c for minishell2 in /u/all/jorge_d/cu/MINISHELL2
**
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
**
** Started on  Mon Jan 25 23:21:39 2010 dimitri jorge
** Last update Thu Jun  3 11:41:30 2010 dimitri jorge
*/

#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "42sh.h"
#include "builtins.h"
#include "set_environ.h"

static void	_set_existing_var(t_env **begin, t_env *parse, t_env *new)
{
  t_env		*tmp1;
  t_env		*tmp2;

  tmp1 = parse->prev;
  tmp2 = parse->next;
  if (tmp1 == NULL)
    {
      new->prev = NULL;
      new->next = tmp2;
      if (tmp2)
	tmp2->prev = new;
      *begin = new;
    }
  else
    {
      new->prev = tmp1;
      tmp1->next = new;
      new->next = tmp2;
      if (tmp2)
	tmp2->prev = new;
    }
  xfree(parse->var);
  xfree(parse);
}

static void	_set_elem(t_env **begin, t_env *new, char *var)
{
  t_env		*parse;

  parse = *begin;
  while ((parse->next) && my_strcmp(parse->var, var) != '=')
    parse = parse->next;
  if (my_strcmp(parse->var, var) != '=')
    {
      parse->next = new;
      new->prev = parse;
      new->next = NULL;
    }
  else
    _set_existing_var(begin, parse, new);
}

static int	_bad_syntax(void)
{
  fprintf(stderr, "Set: Syntax Error.\n");
  return (EXIT_FAILURE);
}

int		set_new(char **args, t_tree *tree)
{
  t_env		*new;
  t_env		*begin;

  begin = gl_st.st_set;
  if (my_tablen(args) == 1)
    return (aff_set(tree));
  else if ((args[1] && (_check_var_syntax(args[1]) == -1 || !args[2]))
	   || (strlen(args[1]) > 128 || strlen(args[2]) > 256))
    return (_bad_syntax());
  if (!(new = xcalloc(1, sizeof(*new))) ||
      !(new->var = set_it(args[1], args[2])))
    return (FATAL_ERROR);
  if (begin == NULL)
    {
      new->prev = NULL;
      new->next = NULL;
      begin = new;
    }
  else
    _set_elem(&begin, new, args[1]);
  gl_st.st_set = begin;
  return (EXIT_SUCCESS);
}
