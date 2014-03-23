/*
** check_line_syntax_2.c for 42sh in /u/all/jorge_d/svn/parserll/trunk/src/parser
**
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
**
** Started on  Wed Apr 14 12:46:40 2010 dimitri jorge
** Last update Sat May 22 20:42:35 2010 julien di-marco
*/

#include <sys/types.h>
#include <sys/uio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "42sh.h"
#include "parserll.h"

static void	init_counters(int *a, int *b, int *c)
{
  *a = 0;
  *b = 0;
  *c = 0;
}

static int	count_spaces_to_set(char *old)
{
  int		count;
  int		i;
  int		flag;

  init_counters(&count, &i, &flag);
  while (old[i])
    {
      if (old[i] == '\'' || old[i] == '\"' || old[i] == '`')
	flag = check_quote_flag(old[i], flag);
      if (flag == 0 && (old[i] == '>' || old[i] == ';' || old[i] == '<' ||
			old[i] == '|' || old[i] == '&'))
	{
	  count += 2;
	  if (old[i + 1] && old[i + 1] != ';' && old[i + 1] == old[i])
	    i += 2;
	  else
	    i++;
	}
      else
	i++;
      while (old[i] && (old[i] == ' ' || old[i] == '\t') && old[i + 1] &&
	     (old[i + 1] == ' ' || old[i + 1] == '\t') && flag == 0)
	i++;
    }
  return (count);
}

static void	set_spaces(char *new, char *old, int *a, int *b)
{
  int		i;
  int		j;

  i = *a;
  j = *b;
  if (new[j - 1] && new[j - 1] != ' ' && new[j - 1] != '\t')
    new[j++] = ' ';
  new[j++] = old[i];
  if (old[i] && old[i + 1] && old[i] != ';' && old[i] == old[i + 1])
    new[j++] = old[++i];
  if (old[i])
    i++;
  if (old[i] && old[i] != ' ' && old[i] != '\t')
    new[j++] = ' ';
  *a = i;
  *b = j;
}

static void	set_spaces_in_line(char *old, char *new, int max)
{
  int		i;
  int		j;
  int		flag;

  init_counters(&j, &i, &flag);
  while (old[i] && j < max)
    {
      if (old[i] == '\'' || old[i] == '\"' || old[i] == '`')
	flag = check_quote_flag(old[i], flag);
      if ((flag == 0 && old[i] != '>' && old[i] != '<' && old[i] != '|'
	    && old[i] != '&' && old[i] != ';') || (flag != 0))
	new[j++] = old[i++];
      else if (flag == 0 && old[i])
	set_spaces(new, old, &i, &j);
      while (old[i] && (old[i] == ' ' || old[i] == '\t') && old[i + 1] &&
	     (old[i + 1] == ' ' || old[i + 1] == '\t') && flag == 0)
	i++;
    }
  new[j] = '\0';
}

char	*format_line(char *old)
{
  int	count;
  char	*new;

  new = NULL;
  if (!old)
    return (NULL);
  count = count_spaces_to_set(old);
  new = xcalloc((strlen(old) + (count * 2) + 10), sizeof(*new));
  if (!new)
    return (NULL);
  set_spaces_in_line(old, new, (strlen(old) + (count * 2) + 10));
  return (new);
}
