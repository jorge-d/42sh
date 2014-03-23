/*
** save_to_file.c for Save history to file  in /Users/lifely/Developer/project/42shsvn/trunk/srcs/my_readline/history
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Tue May 18 05:26:47 2010 julien di-marco
** Last update Fri May 21 14:27:25 2010 dimitri jorge
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	<fcntl.h>
#include	<stdio.h>
#include	"42sh.h"
#include	"my_readline.h"
#include	"set_environ.h"

static int	get_info(char **path)
{
  int		histsize;

  histsize = 0;
  if (!(*path = get_set_from_list("HISTSIZE")))
      return (-1);
  histsize = atoi(*path);
  if (!(*path = get_set_from_list("HISTFILE")))
    return (-1);
  return (histsize);
}

static void	write_on_hist_file(int fd, char *line)
{
  xwrite(fd, "#+\n", 3);
  xwrite(fd, line, strlen(line));
  xwrite(fd, "\n", 1);
}

void		save_hist_to_file(t_hist *hist)
{
  int		histsize;
  char		*path;
  int		fd;

  path = NULL;
  if (hist && (histsize = get_info(&path)) > 0)
    {
      remove(path);
      if ((fd = xopen(path, O_RDWR | O_CREAT, 0600)) == -1)
	return ;
      while (hist->prev && histsize-- > 0)
	hist = hist->prev;
      while (hist)
	{
	  if (strcmp(hist->line, "exit") && strcmp(hist->line, ""))
	    write_on_hist_file(fd, hist->line);
	  hist = hist->next;
	}
      xclose(fd);
    }
}
