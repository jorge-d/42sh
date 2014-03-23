/*
** check_redirection_syntax.c for 42sh in /u/all/jorge_d/svn/parserll/trunk/src/parser
**
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
**
** Started on  Wed Apr 14 14:33:58 2010 dimitri jorge
** Last update Tue May 18 22:36:06 2010 dimitri jorge
*/

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include "42sh.h"
#include "parserll.h"

int	check_left_redir_syntax(char **arg, int i)
{
  if (i == 0 || (i > 0 && (is_sep(arg[i - 1]) || is_pipe(arg[i - 1]))))
    {
      if (!arg[i + 1] || !arg[i + 2] || is_redir_or_sep(arg[i + 1]) ||
	  is_redir_or_sep(arg[i + 2]))
	return (1);
    }
  if ((arg[i + 1] && !is_redir_or_sep(arg[i + 1])))
    {
      i--;
      while (i >= 1 && !is_semi_colon(arg[i]) && !is_and_or_or_bin(arg[i]))
	{
	  if (is_pipe(arg[i]) || is_left_redir(arg[i]))
	    return (3);
	  i--;
	}
      return (0);
    }
  return (2);
}

int	check_right_redir_syntax(char **arg, int i)
{

  if (i == 0 || (i > 0 && (is_sep(arg[i - 1]) || is_pipe(arg[i - 1]))))
    {
      if (!arg[i + 1] || !arg[i + 2] || is_redir_or_sep(arg[i + 1]) ||
	  is_redir_or_sep(arg[i + 2]))
	return (1);
    }
  if ((arg[i + 1] && !is_redir_or_sep(arg[i + 1])))
    {
      if (arg[i])
	i++;
      while (arg[i] && !is_semi_colon(arg[i]) && !is_and_or_or_bin(arg[i]))
	{
	  if (is_pipe(arg[i]) || is_right_redir(arg[i]))
	    return (4);
	  i++;
	}
      return (0);
    }
  return (2);
}

int	check_pipe_and_or(char **arg, int i)
{
  if (is_pipe(arg[i]))
    {
      if (arg[i + 1] && arg[i - 1] && !is_redir_or_sep(arg[i - 1]) &&
	  !is_sep(arg[i - 1]) && !is_sep(arg[i + 1]))
	return (0);
    }
  else
    {
      if (arg[i + 1] && arg[i - 1] && !is_pipe(arg[i - 1]) &&
	  !is_pipe(arg[i + 1]) && !is_sep(arg[i + 1]) && !is_sep(arg[i - 1]))
	return (0);
    }
  return (1);
}
