/*
** my_setenv.c for minishell2 in /u/all/jorge_d/cu/MINISHELL2
** 
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
** 
** Started on  Mon Jan 25 23:21:39 2010 dimitri jorge
** Last update Sat May 22 13:33:16 2010 dimitri jorge
*/

#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "42sh.h"
#include "builtins.h"

int		_check_var_syntax(char *var)
{
  int		i;

  i = 0;
  while (var[i])
    if (var[i++] == '=')
      return (-1);
  return (0);
}

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

int		my_setenv(char **args, t_tree *tree)
{
  t_env		*new;
  t_env		*begin;

  begin = gl_st.st_env;
  if (my_tablen(args) == 1)
    return (aff_env(tree));
  if (my_tablen(args) > 1 && _check_var_syntax(args[1]) == -1)
    {
      fprintf(stderr, "setenv: Syntax Error.\n");
      return (EXIT_FAILURE);
    }
  if (!(new = xcalloc(1, sizeof(*new))) ||
      !(new->var = set_value(args[1], args[2])))
    return (FATAL_ERROR);
  if (begin == NULL)
    {
      new->prev = NULL;
      new->next = NULL;
      begin = new;
    }
  else
    _set_elem(&begin, new, args[1]);
  gl_st.st_env = begin;
  return (EXIT_SUCCESS);
}
