/*
** line_syntax.c for minishell2 in /u/all/jorge_d/cu/MINISHELL2
** 
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
** 
** Started on  Mon Feb  1 12:45:31 2010 dimitri jorge
** Last update Fri May 21 19:45:51 2010 dimitri jorge
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <sys/uio.h>
#include "42sh.h"
#include "parserll.h"

static void	init_counters(int *a, int *b, int *c, int *d)
{
  *a = 0;
  *b = 0;
  *c = 0;
  *d = 0;
}

static void	check_flag(char c, int *d_quote, int *s_quote, int *back)
{
  if (c == '\"' && *d_quote == 0 && *s_quote == 0 && *back == 0)
    *d_quote = 1;
  else if (c == '\"' && *d_quote == 1)
    *d_quote = 0;
  else if (c == '\'' && *d_quote == 0 && *s_quote == 0 && *back == 0)
    *s_quote = 1;
  else if (c == '\'' && *s_quote == 1)
    *s_quote = 0;
  else if (c == '`' && *d_quote == 0 && *s_quote == 0 && *back == 0)
    *back = 1;
  else if (c == '`' && *back == 1)
    *back = 0;
}

int		check_if_line_is_valid(char *str)
{
  int		count;
  int		double_quote;
  int		simple_quote;
  int		back;
  int		space;

  count = 0;
  init_counters(&back, &simple_quote, &double_quote, &space);
  while (str[count])
    {
      if (str[count] != ' ' && str[count] != '\t' && space == 0)
	space = 1;
      if (str[count] == '\'' || str[count] == '\"' || str[count] == '`')
	check_flag(str[count], &double_quote, &simple_quote, &back);
      count++;
    }
  if (simple_quote == 1)
    fprintf(stderr, "Unmatched \'.\n");
  else if (double_quote == 1)
    fprintf(stderr, "Unmatched \".\n");
  else if (back == 1)
    fprintf(stderr, "Unmatched `.\n");
  if (space == 0 || simple_quote == 1 || double_quote == 1 || back == 1)
    return (-1);
  return (0);
}
