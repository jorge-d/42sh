/*
** my.h for my_printf in /u/all/strzel_a/cu/rendu/c/my_printf
**
** Made by alexandre strzelewicz
** Login   <strzel_a@epitech.net>
**
** Started on  Mon Nov  9 11:50:26 2009 alexandre strzelewicz
** Last update Sat May 22 14:37:55 2010 fares sabbagh
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "42sh.h"
#include "alias_glob.h"
#include "builtins.h"
#include "set_environ.h"
#include "my_readline.h"
#include "hreact.h"

#ifdef		__HREACT_ON__

void		dlf_display_top_frame(t_shell *st_shell)
{
  int		i;
  static char	line[1024];
  char		buf[1024];

  if (!*line || st_shell->st_hreact->flags & DISP_REACTUALIZE)
    {
      strcpy(line, FRAME_INTERSECTION);
      i = 0;
      while (i != (st_shell->st_hreact->x_width_window / 2) - 2)
	buf[i++] = TOP_FRAME_CARACTER;
      buf[i] = 0;
      strcat(line, buf);
      i = 0;
      strcat(line, " hreact ");
      while (i != (st_shell->st_hreact->x_width_window / 2) - 3)
	buf[i++] = TOP_FRAME_CARACTER;
      buf[i] = 0;
      strcat(line, buf);
      strcat(line, FRAME_INTERSECTION);
    }
  xwrite(1, line, st_shell->st_hreact->x_width_window + SPE_SPACE);
}

void		dl_clear_disp(t_shell *st_shell, int *oldline)
{
  static char	clear[1024];
  static int	x;
  int		y;
  int		i;

  CURSOR_HOME;
  y = 0;
  while (y <= (*oldline))
    {
      xtputs(xtgoto(st_shell->st_hreact->cmstr, x, y++), 1, xoutc);
      xwrite(1, clear, st_shell->st_hreact->x_width_window + SPE_SPACE);
    }
  if (!x || st_shell->st_hreact->flags & DISP_REACTUALIZE)
    {
      i = 0;
      while (i != st_shell->st_hreact->x_width_window + SPE_SPACE)
	clear[i++] = ' ';
    }
  x = st_shell->st_hreact->x - st_shell->st_hreact->x_width_window - SPE_SPACE;
  *oldline = 0;
}

void		*dl_init_spe_disp(t_hreact *hreact)
{
  if (hreact)
    {
      if (!(hreact->cmd = xcalloc((MAX_CMD + 1), sizeof(*hreact->cmd))))
	{
	  xfree(hreact);
	  return (NULL);
	}
      memset(hreact->cmd[0].comment, '\0', 1024);
      strcpy(hreact->cmd[0].comment, "-- PWD --");
      hreact->cmd[0].spe_cmd = strdup("pwd");
      memset(hreact->cmd[1].comment, '\0', 1024);
      strcpy(hreact->cmd[1].comment, "-- Current Directory --");
      hreact->cmd[1].spe_cmd = strdup("ls -lhtF");
      memset(hreact->cmd[2].comment, '\0', 1024);
      hreact->cmd[2].spe_cmd = NULL;
      if (hreact->cmd[0].spe_cmd == NULL || hreact->cmd[0].spe_cmd == NULL)
	{
	  fprintf(stderr, "Cannot allocate memory for hreact.\n");
	  free_hreact(hreact);
	  return (NULL);
	}
    }
  return (hreact);
}

void		dl_reduce_line_size(char *buf, t_shell *st_shell)
{
  int		i;

  i = 0;
  if (buf && st_shell->st_hreact)
    {
      while (*buf && i < st_shell->st_hreact->x_width_window)
	i++;
      buf[i] = '\0';
    }
}

#endif		/* !__HREACT_ON__ */
