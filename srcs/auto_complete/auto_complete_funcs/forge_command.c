/*
** readstd.c for mysh in /u/all/strzel_a/cu/rendu/c/my_ls
**
** Made by alexandre strzelewicz
** Login   <strzel_a@epitech.net>
**
** Started on  Mon Dec  7 15:08:13 2009 alexandre strzelewicz
** Last update Sat May 22 13:55:29 2010 alexandre strzelewicz
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "42sh.h"
#include "auto_complete.h"

static int	get_end_sequence_val(char *cmd, int i)
{
  int		end;

  end = i;
  while (cmd[end] && cmd[end] != ' ')
    end++;
  return (end);
}

char		*forge_new_command(char *cmd, char *seq, int *i, int beg)
{
  char		*new_cmd;
  int		end;
  int		end_2;

  if (!(new_cmd = xcalloc((strlen(cmd) + strlen(seq) + 2),
			  sizeof(*new_cmd))))
    return (NULL);
  if (beg != 0)
    strncpy(new_cmd, cmd, beg + 1);
  strcat(new_cmd, seq);
  end = get_end_sequence_val(cmd, *i);
  *i += strlen(seq) - (end - beg) + 1;
  end_2 = strlen(seq) + 1;
  strcat(new_cmd, cmd + end);
  return (new_cmd);
}
