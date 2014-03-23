/*
** init_shell.c for Init the shell in /u/all/di-mar_j/svn/minishell2
**
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
**
** Started on  Tue Mar  2 13:46:43 2010 julien di-marco
** Last update Thu May 27 17:30:18 2010 dimitri jorge
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	<errno.h>
#include	"42sh.h"
#include	"my_readline.h"

static int	raw_mode(t_termios *old)
{
  t_termios	line;

  if ((ioctl(STDIN_FILENO, TIOCGETA, old)) != -1)
    {
      line = *old;
      line.c_lflag &= ~(ICANON | ECHO | ISIG);
      line.c_cc[VMIN] = 1;
      line.c_cc[VTIME] = 0;
      if (ioctl(STDIN_FILENO, TIOCSETA, &line) != -1)
	return (0x01);
    }
  return (0x00);
}

static int	get_termcap(char *term, t_rl *info)
{
  char		buffer[4096];

  if (tgetent(buffer, term) != 1)
    {
      fprintf(stderr, E_TERMINAL);
      return (MFALSE);
    }
  else if (strcmp("dumb", term) == 0)
    {
      fprintf(stderr, E_DUMB);
      info->flags |= 0x10;
    }
  return (MTRUE);
}

int			init_readline(t_rl *info)
{
  static unsigned char	start = 0;
  char			*term;

  if (CHCK(info->flags, 0x04))
    {
      info->info.buffer = NULL;
      info->info.tmp = NULL;
      info->prompt = NULL;
      info->tmp.buffer = NULL;
      info->info.i = 0;
      info->info.nb = 0;
      info->info.insert_m = 1;
      if (!(info->bind))
	default_database(info);
      if ((info->flags |= raw_mode(&info->terminal)) && !start)
	{
	  if (!(term = getenv("TERM")))
	    get_termcap("dumb", info);
	  else if (!(get_termcap(term, info)))
	    get_termcap("dumb", info);
	  start++;
	}
    }
  return (MTRUE);
}
