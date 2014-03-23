/*
** main_of_parsing.c for 42sh in /u/all/jorge_d/cu/svn/42shsvn/trunk/srcs/ll_parsor
**
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
**
** Started on  Sun May  9 21:12:03 2010 dimitri jorge
** Last update Sun May 23 15:53:31 2010 dimitri jorge
*/

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "42sh.h"
#include "parserll.h"

void		lexor_and_parsor(char *old, t_shell *st_shell)
{
  char		*new_line;
  char		**board;
  t_tree	*begin;

  if (check_if_line_is_valid(old) != -1)
    {
      begin = NULL;
      new_line = format_line(old);
      if (new_line && (board = check_syntax_error(new_line)) != NULL)
	{
	  begin = make_parsing(board);
	  st_shell->st_tree = begin;
	}
      xfree(new_line);
    }
  xfree(old);
}
