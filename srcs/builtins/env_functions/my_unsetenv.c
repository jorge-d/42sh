/*
** my_unsetenv.c for 42sh in /u/all/jorge_d/cu/svn/42shsvn/trunk/srcs/builtins
** 
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
** 
** Started on  Fri May  7 17:46:04 2010 dimitri jorge
** Last update Fri May 21 13:40:19 2010 dimitri jorge
*/

#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "42sh.h"

static void	_unset_head(t_env **begin, t_env *parse)
{
  t_env		*new_begin;

  new_begin = parse->next;
  xfree(parse->var);
  xfree(parse);
  if (new_begin)
    new_begin->prev = NULL;
  *begin = new_begin;
}

static void	_unset_tail(t_env *parse)
{
  t_env		*tmp;

  tmp = parse->prev;
  xfree(parse->var);
  xfree(parse);
  tmp->next = NULL;
}

static void	_unset_basic(t_env *parse)
{
  t_env		*tmp1;
  t_env		*tmp2;

  tmp1 = parse->prev;
  tmp2 = parse->next;
  xfree(parse->var);
  xfree(parse);
  tmp1->next = tmp2;
  tmp2->prev = tmp1;
}

static void	_unset_elem(t_env **begin, t_env *parse)
{
  if (parse->prev == NULL)
    _unset_head(begin, parse);
  else if (parse->next == NULL)
    _unset_tail(parse);
  else
    _unset_basic(parse);
}

int		my_unsetenv(char **args)
{
  t_env		*parse;
  t_env		*begin;
  int		count;

  begin = gl_st.st_env;
  count = 1;
  if (my_tablen(args) < 2)
    {
      fprintf(stderr, "unsetenv: Too few arguments.\n");
      return (EXIT_FAILURE);
    }
  else if (begin)
    while ((begin) && (args[count]))
      {
	parse = begin;
	while ((parse) && my_strcmp(parse->var, args[count]) != '=')
	  parse = parse->next;
	if (parse)
	  _unset_elem(&begin, parse);
	count++;
      }
  gl_st.st_env = begin;
  return (EXIT_SUCCESS);
}
