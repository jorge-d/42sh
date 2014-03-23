/*
** my_str_to_wordtab.c for minishell1 in /u/all/jorge_d/cu/rendu/c/minishell1/lib
** 
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
** 
** Started on  Wed Dec 30 16:55:04 2009 dimitri jorge
** Last update Wed May 19 18:00:54 2010 julien di-marco
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include "lib.h"

static void	init_counters(int *a, int *b)
{
  *a = 0;
  *b = 0;
}

static int	check_quote(int flag, char c)
{
  if (flag == 0 && c == '\'')
    flag = 1;
  else if (flag == 0 && c == '\"')
    flag = 2;
  else if (flag == 0 && c == '`')
    flag = 5;
  else if (flag == 5 && c == '`')
    flag = 6;
  else if (flag == 1 && c == '\'')
    flag = 3;
  else if (flag == 2 && c == '\"')
    flag = 4;
  return (flag);
}

static int	word_counter(char *str, int flag)
{
  int		i;
  int		word_number;

  init_counters(&i, &word_number);
  while (str[i])
    {
      while (str[i] == ' ' || str[i] == '\t')
	i++;
      if (str[i] && str[i] != ' ' && str[i] != '\t')
	{
	  if (flag == 0)
	    word_number++;
	  while (str[i] && ((flag == 0 && str[i] != '\t' && str[i] != ' ')
			    || (flag == 1 || flag == 2 || flag == 5)))
	    {
	      if (str[i] == '\'' || str[i] == '\"' || str[i] == '`')
		flag = check_quote(flag, str[i]);
	      if (flag == 3 || flag == 4 || flag == 6)
		flag = 0;
	      i++;
	    }
	}
    }
  return (word_number);
}

static void	copy_into_tab(char **board, char *str, int flag)
{
  int		i;
  int		j;

  init_counters(&i, &j);
  while (*str)
    {
      while (*str == ' ' || *str == '\t')
	str++;
      while (*str && ((*str != ' ' && *str != '\t' && flag == 0) || flag != 0))
	{
	  flag = check_quote(flag, *str);
	  board[i][j++] = *str;
	  str++;
	  if (flag == 3 || flag == 4 || flag == 6)
	    flag = 0;
	  if (!(*str) || ((*str == '\t' || *str == ' ') && flag == 0))
	    {
	      board[i++][j] = '\0';
	      j = 0;
	    }
	}
    }
  board[i] = NULL;
}

char		**my_str_to_wordtab(char *str)
{
  int		word_nbr;
  char		**board;

  board = NULL;
  word_nbr = word_counter(str, 0);
  board = malloc_table(board, str, word_nbr);
  if (!board)
    return (NULL);
  copy_into_tab(board, str, 0);
  return (board);
}
