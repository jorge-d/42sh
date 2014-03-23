/*
** history.c for sd in /u/all/strzel_a/svn/42shsvn/trunk
**
** Made by alexandre strzelewicz
** Login   <strzel_a@epitech.net>
**
** Started on  Wed May 12 12:17:15 2010 alexandre strzelewicz
** Last update Sat May 22 18:27:35 2010 julien di-marco
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	<signal.h>
#include	<fcntl.h>
#include	<stdio.h>
#include	"42sh.h"
#include	"my_readline.h"
#include	"set_environ.h"

void		load_hist_file(t_hist **st_history)
{
  int		fd;
  int		histsize;
  char		*buffer;
  char		*filepath;

  buffer = NULL;
  if (!(filepath = get_set_from_list("HISTSIZE")))
    return ;
  if ((((histsize = atoi(filepath)) < 0) && (histsize > 1000)) || \
      !(filepath = get_set_from_list("HISTFILE")))
    return ;
  if ((fd = open(filepath, O_RDONLY)) == -1)
      return ;
  while ((buffer = get_next_line(fd)) && histsize > 0)
    {
      if (strcmp(buffer, "") && strcmp(buffer, "#+"))
	{
	  put_in_hist_list(st_history, buffer);
	  histsize -= 1;
	}
      xfree(buffer);
    }
  xfree(buffer);
  xclose(fd);
}

static int	check_line(char *line)
{
  while (*line)
    {
      if ((*line < ' ' && *line > '~'))
	return (0);
      line++;
    }
  return (1);
}

void		save_to_history(t_shell *st_shell, char *line)
{
  char		i;
  char		*conf;

  i = 10;
  if (!line || !*line)
    return ;
  if (!(conf = get_set_from_list("HIST_DOUBLOON")))
	return ;
      i = conf[0];
  if (check_line(line) && i != 10)
    {
      if (!st_shell->st_hist && (i == '1'))
	put_in_hist_list(&(st_shell->st_hist), line);
      else if (st_shell->st_hist && strcmp(st_shell->st_hist->line, line) \
	  && i == '1')
	put_in_hist_list(&(st_shell->st_hist), line);
      else if (i == 0)
	put_in_hist_list(&(st_shell->st_hist), line);
    }
}

int		rewind_hist(t_shell *shell)
{
  while (shell->st_hist && shell->st_hist->prev)
    shell->st_hist = shell->st_hist->prev;
  while (shell->st_hist)
    {
      shell->st_hist->aff = 0;
      if (!(shell->st_hist->next))
	break;
      shell->st_hist = shell->st_hist->next;
    }
  return (1);
}
