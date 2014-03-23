/*
** check_type.c for 42sh in /u/all/jorge_d/svn/parserll/trunk/src/parser
**
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
**
** Started on  Wed Apr 14 14:46:17 2010 dimitri jorge
** Last update Mon May 17 20:34:54 2010 dimitri jorge
*/

#include <string.h>
#include "42sh.h"
#include "parserll.h"

t_bool		is_left_redir(char *str)
{
  if (str && (!strcmp(str, LEFT_R) || !strcmp(str, D_LEFT_R)))
    return (TRUE);
  return (FALSE);
}

t_bool		is_right_redir(char *str)
{
  if (str && (!strcmp(str, RIGHT_R) || !strcmp(str, D_RIGHT_R)))
    return (TRUE);
  return (FALSE);
}

t_bool		is_pipe(char *str)
{
  if (str && !strcmp(str, PIPE))
    return (TRUE);
  return (FALSE);
}

t_bool		is_and_or_or_bin(char *str)
{
  if (str && (!strcmp(str, AND_BIN) || !strcmp(str, OR_BIN)))
    return (TRUE);
  return (FALSE);
}

t_bool		is_semi_colon(char *str)
{
  if (str && !strcmp(str, SEMICOLON))
    return (TRUE);
  return (FALSE);
}
