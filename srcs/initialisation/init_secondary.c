/*
** init_secondary.c for das in /u/epitech_2014/strzel_a/svn/42shsvn/trunk
** 
** Made by alexandre strzelewicz
** Login   <strzel_a@epitech.net>
** 
** Started on  Sat May 22 12:32:25 2010 alexandre strzelewicz
** Last update Sat May 22 12:37:39 2010 alexandre strzelewicz
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include "42sh.h"
#include "hreact.h"
#include "set_environ.h"

void		_env_copy(char **env)
{
  int		i;
  t_env		*begin;

  begin = NULL;
  i = 0;
  while (env[i])
    my_put_in_list(&begin, env[i++]);
  gl_st.st_env = begin;
}

void		handle_sign(void (*type)(int))
{
  if (signal(SIGINT, type) == SIG_ERR)
    perror("Signal");
  if (signal(SIGTSTP, SIG_IGN) == SIG_ERR)
    perror("Signal");
  if (signal(SIGQUIT, type) == SIG_ERR)
    perror("Signal");
  if (signal(SIGHUP, type) == SIG_ERR)
    perror("Signal");
}

int		init_term(t_shell *sh)
{
  t_termios	line;
  int		i;

  if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
    {
      if ((i = ioctl(STDIN_FILENO, TIOCGSIZE, &gl_st.size)) == -1)
	perror("42sh: retrieve terminal size");
      if ((i = ioctl(STDIN_FILENO, TIOCGETA, &sh->terminal)) != -1)
	{
	  line = sh->terminal;
	  line.c_lflag &= ~(ECHO | ISIG);
	  if (ioctl(STDIN_FILENO, TIOCSETA, &line) != -1)
	    {
	      handle_sign(SIG_IGN);
	      return (0x04);
	    }
	}
      if (i == -1)
	perror("42sh: terminal");
    }
  return (0x00);
}
