/*
** check_syntax_error.c for 42sh in /u/all/jorge_d/svn/parserll/trunk/src/parser
** 
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
** 
** Started on  Wed Apr 14 13:43:10 2010 dimitri jorge
** Last update Sat May 22 13:21:09 2010 dimitri jorge
*/

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include "42sh.h"
#include "parserll.h"

static char	**set_error_msg(int flag, char **board)
{
  if (flag == 0)
    return (board);
  if (flag == 1)
    fprintf(stderr, "Invalid null command.\n");
  else if (flag == 2)
    fprintf(stderr, "Missing name for redirect.\n");
  else if (flag == 3)
    fprintf(stderr, "Ambiguous input redirect.\n");
  else if (flag == 4)
    fprintf(stderr, "Ambiguous output redirect.\n");
  free_table(board);
  return (NULL);
}

char		**check_syntax_error(const char *str)
{
  char		**board;
  int		flag;
  int		i;

  i = 0;
  flag = 0;
  if ((board = my_str_to_wordtab((char *)str)) == NULL)
    return (0);
  if (is_pipe(board[i]) || is_and_or_or_bin(board[i]))
    flag = 1;
  while (board[i] && flag == 0)
    {
      if (is_left_redir(board[i]))
	flag = check_left_redir_syntax(board, i);
      else if (is_right_redir(board[i]))
	flag = check_right_redir_syntax(board, i);
      else if (is_pipe(board[i]) || is_and_or_or_bin(board[i]))
	flag = check_pipe_and_or(board, i);
      i++;
    }
  return (set_error_msg(flag, board));
}
