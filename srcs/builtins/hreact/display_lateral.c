/*
** my.h for my_printf in /u/all/strzel_a/cu/rendu/c/my_printf
**
** Made by alexandre strzelewicz
** Login   <strzel_a@epitech.net>
**
** Started on  Mon Nov  9 11:50:26 2009 alexandre strzelewicz
** Last update Sat May 22 21:04:12 2010 julien di-marco
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/param.h>
#include <sys/types.h>
#include <dirent.h>
#include "42sh.h"
#include "parserll.h"
#include "builtins.h"
#include "set_environ.h"
#include "my_readline.h"
#include "hreact.h"

#ifdef		__HREACT_ON__

static void	dl_parent_process(t_shell *shell, int *oldLine, pipe_t *p)
{
  int		y;
  int		x;
  char		*buf;
  int		tmp;

  y = 0;
  x = shell->st_hreact->x - shell->st_hreact->x_width_window - SPE_SPACE;
  if ((tmp = dup(STDIN)) == -1)
    return ;
  xclose(p[STDOUT]);
  xtputs(xtgoto(shell->st_hreact->cmstr, x, y++), 1, xoutc);
  dlf_display_top_frame(shell);
  while ((buf = get_next_line2(p[STDIN])) &&
	 (*oldLine)++ < shell->st_hreact->y_lenght_window)
    {
      dl_reduce_line_size(buf, shell);
      xtputs(xtgoto(shell->st_hreact->cmstr, x, y++), 1, xoutc);
      fprintf(stdout, "| %-*s |", shell->st_hreact->x_width_window, buf);
      fflush(stdout);
      xfree(buf);
    }
  xtputs(xtgoto(shell->st_hreact->cmstr, x, y++), 1, xoutc);
  dlf_display_top_frame(shell);
  xdup2(STDIN, tmp);
  xclose(p[STDIN]);
}

static void	dl_child_process(t_shell *shell, pipe_t *p)
{
  int		i;

  i = 0;
  xclose(p[STDIN]);
  if (dup2(p[STDOUT], STDOUT) == -1)
    return ;
  while (shell->st_hreact->cmd[i].spe_cmd)
    {
      xwrite(1, shell->st_hreact->cmd[i].comment,
	     strlen(shell->st_hreact->cmd[i].comment));
      xwrite(1, " \n", 2);
      safe_exec_line(shell->st_hreact->cmd[i].spe_cmd, shell);
      if (shell->st_hreact->cmd[i + 1].spe_cmd != NULL)
	xwrite(1, " \n", 2);
      i++;
    }
  exit(EXIT_SUCCESS);
}

static int	dl_check_for_term_size(t_shell *shell)
{
  char		*buf;

  if (!(buf = get_set_from_list("HREACT_DISP")))
    return (FALSE);
  if (buf[0] && buf[0] == '0')
    return (FALSE);
  if ((shell->st_hreact->flags & DISP_STATE) &&
      !(shell->st_hreact->flags & DISP_REACTUALIZE))
    return (FALSE);
  if (shell->st_hreact->x < (X_BEGIN_FRAME + X_MAX_WIDHT_FRAME))
    return (FALSE);
  else if (shell->st_hreact->y < (Y_BEGIN_FRAME + Y_MAX_LENGHT_FRAME))
    return (FALSE);
  return (TRUE);
}

static int	dl_operate_lateral(t_shell *shell, int *oldLine)
{
  pid_t		pid;
  pipe_t	p[PIPE_TAB_SIZE];
  char		*buf;

  if (pipe(p) == -1)
    return (RT_FAILURE);
  if ((pid = fork()) < 0)
    return (RT_FAILURE);
  if (pid)
    {
      if (waitpid(pid, NULL, 0) == -1)
	return (RT_FAILURE);
      if ((buf = get_set_from_list("HREACT_OPT")) && (buf[0] == '0'))
	dl_parent_process(shell, oldLine, p);
      else
	optimized_hreact_parent(shell, oldLine, p);
    }
  else
    dl_child_process(shell, p);
  return (RT_SUCCESS);
}

void		hreact_displaying(t_shell *shell)
{
  static int	oldLine;
  static char	*area;
  static char	t[AREA_SIZE];

  if (!shell->st_hreact || check_if_too_much_files() == FALSE)
    return ;
  if (!area || gl_resize)
    {
      if (!win_size(shell))
	return ;
      area = t;
      shell->st_hreact->cmstr = xtgetstr("cm", &area);
      gl_resize = 0;
    }
  if (dl_check_for_term_size(shell) == FALSE)
    return ;
  CURSOR_SAVE;
  CURSOR_OFF;
  dl_clear_disp(shell, &oldLine);
  if (!(shell->st_hreact->flags & DISP_STATE))
    dl_operate_lateral(shell, &oldLine);
  CURSOR_ON;
  shell->st_hreact->flags &= ~DISP_REACTUALIZE;
  CURSOR_RESTORE;
}

#endif		/* !__HREACT_ON__ */
