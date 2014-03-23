/*
** readstd.c for mysh in /u/all/strzel_a/cu/rendu/c/my_ls
**
** Made by alexandre strzelewicz
** Login   <strzel_a@epitech.net>
**
** Started on  Mon Dec  7 15:08:13 2009 alexandre strzelewicz
** Last update Sun May 23 14:03:09 2010 julien di-marco
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/param.h>
#include "42sh.h"
#include "my_readline.h"
#include "auto_complete.h"
#include "set_environ.h"

static char	*get_sequence(char *cmd, int i, int size)
{
  char		*seq;
  int		beg;
  int		end;

  if (!i || !cmd || size > (MAXPATHLEN / 2))
    return (NULL);
  beg = end = i;
  beg -= 1;
  while (cmd[beg] && beg > 0 && cmd[beg] != ' ')
    beg--;
  while (cmd[end] && cmd[end] != ' ')
    end++;
  if (!(seq = xcalloc(MAXPATHLEN, sizeof(*seq))))
    return (NULL);
  if (!beg)
    strncpy(seq, cmd + beg, end - beg);
  else if (!cmd[end])
    strncpy(seq, cmd + beg + 1, end - beg);
  else
    strncpy(seq, cmd + beg + 1, end - beg - 1);
  return (seq);
}

static void	select_completion(char *seq, t_list **st_list,
				  t_shell *st_shell)
{
  char		*buf;

  *st_list = file_completion(seq);
  if ((buf = get_set_from_list("COMPLETION_BIN")) && buf[0] == '1')
    builtin_completion(seq, st_list);
  if ((buf = get_set_from_list("COMPLETION_SET")) && buf[0] == '1')
    set_environ_completion(seq, st_list);
  if ((buf = get_set_from_list("COMPLETION_ALIAS")) && buf[0] == '1')
    alias_completion(seq, st_list, st_shell->st_alias);
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

char		*auto_complete(t_rl *rl, t_shell *shell)
{
  t_list	*st_list;
  char		*seq;
  char		*buf;
  int		beg;

  buf = get_set_from_list(COMPLETION_STATE_STR);
  if ((!(st_list = NULL) && (buf && buf[0] && buf[0] == '0')) || buf == NULL)
    return (NULL);
  buf = NULL;
  if ((rl->info.i == 0) || (!(seq = get_sequence(rl->info.buffer, rl->info.i, \
						 rl->info.nb)) || !seq[0]))
    {
      st_list = display_file();
      display_auto_complete_list(st_list);
      return (NULL);
    }
  select_completion(seq, &st_list, shell);
  beg = get_beg_sequence_val(rl->info.buffer, rl->info.i);
  rl->info.i = strlen(seq) + beg + 1;
  buf = operate_auto_completion(st_list, seq, rl->info.buffer, &(rl->info.i));
  display_auto_complete_list(st_list);
  free_st_list(st_list);
  xfree(seq);
  rl->info.nb = strlen(rl->info.buffer);
  return (buf);
}




