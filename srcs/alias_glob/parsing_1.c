/*
** readstd.c for mysh in /u/all/strzel_a/cu/rendu/c/my_ls
**
** Made by alexandre strzelewicz
** Login   <strzel_a@epitech.net>
**
** Started on  Mon Dec  7 15:08:13 2009 alexandre strzelewicz
** Last update Sun May 23 14:57:54 2010 dimitri jorge
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "42sh.h"
#include "alias_glob.h"

static int	how_much_caracter(char *str, char caracter)
{
  int		nb_caracs;

  nb_caracs = 1;
  while (*str && *str != caracter)
    {
      if (*str == '"')
	{
	  str++;
	  while (*str && *str != '"')
	    {
	      str++;
	      nb_caracs++;
	    }
	  return (nb_caracs + 1);
	}
      else
	{
	  nb_caracs++;
	  str++;
	}
    }
  if (*str && *str == caracter)
    return (nb_caracs - 1);
  return (nb_caracs);
}

static int	how_much_word(char *str, char caracter)
{
  int		nb_words;

  nb_words = 1;
  while (*str)
    {
      if (*str == caracter)
	nb_words++;
      str++;
    }
  return (nb_words);
}

static char	*delete_space(char *str)
{
  while (*str && (*str == ' ' || *str == '\t'))
    str++;
  return (str);
}

char	**parse_str(char *str, char c)
{
  char	**wordtab;
  int	nb_words;
  int	i;
  int	nb_caracs;

  nb_words = 0;
  if (!str ||
      !(wordtab = xmalloc(sizeof(*wordtab) * (how_much_word(str, c) + 5))))
    return (NULL);
  while (*str)
    {
      i = 0;
      str = delete_space(str);
      nb_caracs = how_much_caracter(str, c);
      if (!(wordtab[nb_words] = xmalloc(sizeof(*wordtab) * (nb_caracs + 5))))
	return (NULL);
      strncpy(wordtab[nb_words], str, nb_caracs);
      while (i++ != nb_caracs && *str)
	str++;
      if ((*str == c) && *str)
	str++;
      nb_words++;
    }
  wordtab[nb_words] = NULL;
  return (wordtab);
}
