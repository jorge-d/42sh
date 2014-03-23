/*
** print_prompt.c for Print That Prompt in /u/all/di-mar_j/cu/svn/VSHsvn/branches/my_readline/new
**
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
**
** Started on  Tue Apr 20 23:20:46 2010 julien di-marco
** Last update Sat May 22 20:22:04 2010 dimitri jorge
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	"42sh.h"
#include	"my_readline.h"
#include	"set_environ.h"

static int	check_def_prompt(void)
{
  char		*recup;

  if ((recup = get_set_from_list("PROMPT")))
    {
      if (strcmp(recup, DEFAULT_PROMPT) == 0)
	return (26);
    }
  return (0);
}

static int	print_it(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    xwrite(STDOUT_FILENO, &str[i++], 1);
  return (i);
}

int		print_prompt(t_rl *rl, char *text)
{
  int		i;

  if (text && rl->prompt)
    xfree(rl->prompt);
  if (text)
    {
      rl->p_len = print_it(text);
      rl->prompt = text;
    }
  else if (!text && rl->prompt)
      rl->p_len = print_it(rl->prompt);
  if ((i = check_def_prompt()))
    rl->p_len -= i;
  while ((rl->p_len >= gl_st.size.ts_cols))
    rl->p_len -= gl_st.size.ts_cols;
  return (EXIT_SUCCESS);
}
