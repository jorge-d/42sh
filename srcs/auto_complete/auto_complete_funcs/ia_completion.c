/*
** readstd.c for mysh in /u/all/strzel_a/cu/rendu/c/my_ls
**
** Made by alexandre strzelewicz
** Login   <strzel_a@epitech.net>
**
** Started on  Mon Dec  7 15:08:13 2009 alexandre strzelewicz
** Last update Sun May 23 13:48:06 2010 julien di-marco
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "42sh.h"
#include "auto_complete.h"

static int	same_level(t_list *st_list)
{
  int		i;
  int		j;
  int		min;

  min = calc_longest_word_list(st_list);
  j = 0;
  i = 0;
  if (st_list == NULL || st_list->previous == NULL)
    return (0);
  st_list = st_list->previous;
  while (st_list)
    {
      j = 0;
      while (st_list->data[j] && st_list->next->data[j] &&
	     (st_list->data[j] == st_list->next->data[j]))
	j++;
      if (j < min)
	min = j;
      st_list = st_list->previous;
    }
  return (min);
}

static int	list_size(t_list *st_list)
{
  int		i;

  i = 0;
  while (st_list)
    {
      st_list = st_list->previous;
      i++;
    }
  return (i);
}

static int	get_beg_sequence_val(char *cmd, int i)
{
  int		beg;

  beg = i - 1;
  while (cmd[beg] && beg > 0 && cmd[beg] != ' ')
    beg--;
  if (beg == 0)
    beg = -1;
  return (beg);
}

char		*operate_auto_completion(t_list *st_list, char *seq,
					 char *cmd, int *i)
{
  int		beg;

  beg = get_beg_sequence_val(cmd, *i);
  if (same_level(st_list) > 0)
    {
      one_gap_modification(seq);
      strncat(seq, st_list->data, same_level(st_list));
      return (forge_new_command(cmd, seq, i, beg));
    }
  else if (list_size(st_list) == 1)
    {
      one_gap_modification(seq);
      strcat(seq, st_list->data);
      return (forge_new_command(cmd, seq, i, beg));
    }
  return (NULL);
}
