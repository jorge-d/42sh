/*
** my_readline.c for Readline Recode by lifely in /u/all/di-mar_j/cu/svn/VSHsvn/branches/my_readline-new
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Mon Apr 19 12:46:50 2010 julien di-marco
** Last update Thu May 27 17:29:37 2010 dimitri jorge
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	<signal.h>
#include	"42sh.h"
#include	"my_readline.h"
#include	"hreact.h"

void		term_size(int sig)
{
  (void)sig;
  if (ioctl(STDIN_FILENO, TIOCGSIZE, &gl_st.size) == -1)
    perror("42sh: Error terminal size");
  gl_resize = 1;
}

char		*my_readline(t_shell *shell, char *prompt)
{
  t_rl		*base;
  char		*output;

  base = &shell->rl;
  init_readline(base);
  output = NULL;
  if (!(CHCK(base->flags, 0x01)))
    {
      xfree(prompt);
      return (get_next_line(STDIN_FILENO));
    }
  else if (prompt)
    {
      if (signal(SIGWINCH, term_size) == SIG_ERR)
	perror("42sh");
#ifdef __HREACT_ON__
      hreact_displaying(shell);
#endif
      print_prompt(base, prompt);
      output = getline(base, shell);
      save_to_history(shell, output);
    }
  reset_readline(base);
  return (output);
}
