/*
** check_env_var.c for 42sh in /u/all/jorge_d/cu/svn/parserll/trunk/src/execution
** 
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
** 
** Started on  Mon May 10 16:26:12 2010 dimitri jorge
** Last update Thu Jun  3 11:36:47 2010 julien di-marco
*/

#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include "parserll.h"
#include "42sh.h"

static int	_there_is_var(char *s)
{
  int		i;

  i = 0;
  while (s[i])
    {
      if (s[i] == '$')
	return (1);
      i++;
    }
  return (0);
}
static int	_is_it_on_env(char *s, char *var)
{
  int		i;
  int		j;

  j = 0;
  i = 0;
  while (s[i] != '$')
    i++;
  i++;
  while (s[i] && s[i] != ' ' && s[i] != '\t' && s[i] != '/'
	 && s[i] != '\'' && s[i] != '\"' && s[i] != '`')
    var[j++] = s[i++];
  var[j] = '\0';
  if (get_env_from_list(var) == NULL)
    {
      fprintf(stderr, "%s: Undefined variable.\n", var);
      xfree(var);
      return (-1);
    }
  return (0);
}

static int	_copy_variable_val(char *arg, t_tree *tree, int i, char *var)
{
  char		*val;
  char		*new;
  int		a;
  int		j;
  int		k;

  k = 0;
  a = 0;
  j = 0;
  val = get_env_from_list(var);
  xfree(var);
  if (!(new = xmalloc((strlen(val) + strlen(arg) + 2) * sizeof(*new))))
    return (FATAL_ERROR);
  while (arg[a] && arg[a] != '$')
    new[j++] = arg[a++];
  while (val[k])
    new[j++] = val[k++];
  while (arg[a] && arg[a] != ' ' && arg[a] != '\t' && arg[a] != '/' &&
	 arg[a] != '\'' && arg[a] != '\"' && arg[a] != '`')
    a++;
  while (arg[a])
    new[j++] = arg[a++];
  free(arg);
  tree->args[i] = new;
  return (EXIT_SUCCESS);
}

int	check_var_on_env(char **args, t_tree *tree)
{
  int	i;
  int	flag;
  char	*var;

  var = NULL;
  flag = 0;
  i = 0;
  while (args[i])
    {
      if (check_tilde(args[i]) && concat_tilde(args, tree, i) == FATAL_ERROR)
	return (FATAL_ERROR);
      if (_there_is_var(args[i]))
	{
	  if (!(var = xmalloc((my_strlen(args[i]) + 1) * sizeof(*var))))
	    return (FATAL_ERROR);
	  if ((flag = _is_it_on_env(args[i], var)) == -1)
	    return (FATAL_ERROR);
	  if (_copy_variable_val(args[i], tree, i, var) == FATAL_ERROR)
	    return (FATAL_ERROR);
	}
      else
	i++;
    }
  return (EXIT_SUCCESS);
}
