/*
** my.h for my_printf in /u/all/strzel_a/cu/rendu/c/my_printf
**
** Made by alexandre strzelewicz
** Login   <strzel_a@epitech.net>
**
** Started on  Mon Nov  9 11:50:26 2009 alexandre strzelewicz
** Last update Sat May 22 17:18:11 2010 fares sabbagh
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "42sh.h"
#include "builtins.h"
#include "set_environ.h"
#include "my_readline.h"
#include "hreact.h"

#ifdef	__HREACT_ON__

# define BUFF_SIZE 2000

void			modify_buff(char *buf, int i)
{
  int			j;

  j = 0;
  if (!buf[i] || buf[i] == '\n')
    while (j != BUFF_SIZE)
      buf[j++] = 0;
  j = 0;
  while (buf[i])
    buf[j++] = buf[i++];
  buf[j] = 0;
}

char			*get_next_line2(const int fd)
{
  static char		buf[BUFF_SIZE + 1];
  char			*str;
  int			i;

  if (fd == -1)
    return (NULL);
  if (!buf[0])
    if (!(read(fd, buf, BUFF_SIZE)))
      return (NULL);
  if (!(str = xcalloc(BUFF_SIZE + 1, sizeof(*str))))
    return (NULL);
  i = 0;
  while (buf[i] && buf[i] != '\n')
    {
      str[i] = buf[i];
      i++;
    }
  str[i] = 0;
  if (buf[i] == '\n')
    modify_buff(buf, i + 1);
  else
    modify_buff(buf, i);
  return (str);
}

void	optimized_hreact_parent(t_shell *shell,
				int *oldLine, pipe_t *p)
{
  int	y;
  int	x;
  char	*buf;
  int	tmp;

  y = 0;
  x = shell->st_hreact->x - shell->st_hreact->x_width_window - SPE_SPACE;
  if ((tmp = dup(STDIN)) == -1)
    return ;
  xclose(p[STDOUT]);
  while ((buf = get_next_line2(p[STDIN])) &&
	 (*oldLine < shell->st_hreact->y_lenght_window - 30))
    {
      dl_reduce_line_size(buf, shell);
      xtputs(xtgoto(shell->st_hreact->cmstr, x, y++), 1, xoutc);
      (*oldLine)++;
      xwrite(1, buf, strlen(buf));
      xfree(buf);
    }
  xfree(buf);
  if (xdup2(STDIN, tmp) == RT_FAILURE)
    return ;
  xclose(p[STDIN]);
}

#endif	/* !__HREACT_ON__ */
