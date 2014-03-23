/*
** type.c for 42sh in /u/all/sabbag_a/svn/parserll/trunk/src/parser
**
** Made by fares sabbagh
** Login   <sabbag_a@epitech.net>
**
** Started on  Sat Apr 17 16:41:32 2010 fares sabbagh
** Last update Sat May 22 13:20:59 2010 dimitri jorge
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "42sh.h"
#include "parserll.h"

t_bool		is_redir_no_pipe(char *str)
{
  if (is_left_redir(str) || is_right_redir(str))
    return (TRUE);
  return (FALSE);
}

t_bool		is_redir(char *str)
{
  if (is_left_redir(str) || is_right_redir(str) || is_pipe(str))
    return (TRUE);
  return (FALSE);
}

t_bool		is_sep(char *str)
{
  if (is_and_or_or_bin(str) || is_semi_colon(str))
    return (TRUE);
  return (FALSE);
}

t_bool		is_redir_or_sep(char *s)
{
  if (is_left_redir(s) || is_right_redir(s) || is_sep(s) || is_pipe(s))
    return (TRUE);
  return (FALSE);
}

int		is_directory(char *path)
{
  struct stat	buf;

  if (stat(path, &buf) == -1)
    {
      perror("Stat");
      return (0);
    }
  if (S_ISDIR(buf.st_mode))
    return (1);
  return (0);
}
