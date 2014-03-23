/*
** readstd.c for mysh in /u/all/strzel_a/cu/rendu/c/my_ls
**
** Made by alexandre strzelewicz
** Login   <strzel_a@epitech.net>
**
** Started on  Mon Dec  7 15:08:13 2009 alexandre strzelewicz
** Last update Sun May 23 13:51:40 2010 julien di-marco
*/

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/param.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "42sh.h"
#include "my_readline.h"
#include "set_environ.h"
#include "auto_complete.h"

static int	_list_sz(t_list *st_list)
{
  int		i;

  i = 0;
  while (st_list)
    {
      i++;
      st_list = st_list->previous;
    }
  return (i);
}

int		display_auto_complete_list(t_list *st_list)
{
  t_window	st_window;

  if (st_list && _list_sz(st_list) > 1)
    {
      st_window.list_size = _list_sz(st_list);
      st_window.size_longest = calc_longest_word_list(st_list);
      st_window.nb_col = how_much_column(st_window.size_longest);
      st_window.nb_row = how_much_line(st_window.list_size, st_window.nb_col);
      display_list(st_list, &st_window);
      return (RT_SUCCESS);
    }
  return (RT_FAILURE);
}

static int	disp_too_much(t_list *st_list)
{
  char		read_buf[256];
  char		line[256];
  char		*buf;

  if ((buf = get_set_from_list(COMPLETION_CHOICE_STR)) &&
      buf[0] == '0')
    return (-1);
  if (_list_sz(st_list) < MAX_CHOICE_DIP)
    return (-1);
  memset(read_buf, 0, 256);
  sprintf(line, "Display all %d possibilities ? (y||n)\n", _list_sz(st_list));
  xwrite(1, line, strlen(line));
  while (read_buf[0] != 'y' && read_buf[0] != 'n')
    {
      memset(read_buf, '\0', 256);
      xread(0, read_buf, sizeof(read_buf));
      if (read_buf[0] == 'y' || read_buf[0] == '\t')
	return (TRUE);
      else if (read_buf[0] == 'n')
	{
	  apply_term("up");
	  return (FALSE);
	}
    }
  return (TRUE);
}

int		display_list(t_list *st_list, t_window *st_window)
{
  int		col;
  int		line2;
  char		buf[MAXPATHLEN];

  line2 = 0;
  xwrite(1, "\n", 1);
  if (disp_too_much(st_list) == FALSE)
    return (RT_SUCCESS);
  while (st_list)
    {
      col = 0;
      while (col != st_window->nb_col && st_list &&
	     st_list->type == 0)
	{
	  sprintf(buf, "%-*s", st_window->size_longest + MORE_SPACE,
		  st_list->data);
	  xwrite(1, buf, strlen(buf));
	  st_list = st_list->previous;
	  col++;
	}
      if (st_list != NULL)
	xwrite(1, "\n", 1);
    }
  return (RT_SUCCESS);
}
