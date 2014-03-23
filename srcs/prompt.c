/*
** main.c for 42sh in /u/all/jorge_d/cu/svn/42shsvn/trunk
**
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
**
** Started on  Wed Dec 23 02:59:49 2009 dimitri jorge
** Last update Sun May 23 15:56:53 2010 julien di-marco
*/

#include <sys/types.h>
#include <sys/param.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "42sh.h"
#include "my_readline.h"
#include "set_environ.h"

# define SIZE_MAX_PROMPT 60
# define MAX_POURC	 4
# define BUF_PROMPT	 512

static void	concat_prompt(char *prompt, char *buf, int s)
{
  if (buf)
    {
      if (strlen(prompt) == 0)
	strncpy(prompt, buf, 32);
      else
	strncat(prompt, buf, 32);
      if (s)
	xfree(buf);
    }
}

static int	check_prompt_syntax(char *prompt)
{
  int		t;
  int		s;

  t = 0;
  s = 0;
  if (!prompt)
    return (FALSE);
  while (*prompt)
    {
      if (s++ > SIZE_MAX_PROMPT || t > MAX_POURC)
	return (FALSE);
      if (*prompt == '%')
	t++;
      prompt++;
    }
  return (TRUE);
}

static char	*_pwd(char *pwd)
{
  char		*buffer;
  int		count;

  if (pwd && (buffer = xmalloc((strlen(pwd) + 10) * sizeof(*buffer))))
    {
      count = strlen(pwd) - 1;
       if (count >= 2)
	{
	  if (pwd[count] == '/')
	    count--;
	  while (pwd[count] && pwd[count] != '/')
	    count--;
	  if (buffer && pwd)
	    {
	      strcpy(buffer, pwd + count + 1);
	      if (buffer[strlen(buffer) - 1] == '/')
		buffer[strlen(buffer) - 1] = '\0';
	    }
	}
      else
	buffer = strdup("/");
      xfree(pwd);
      return (buffer);
    }
  return (NULL);
}

static char	*update_prompt_line(char *raw_prompt)
{
  char		*prompt;
  int		i;

  i = 0;
  if ((prompt = xmalloc((BUF_PROMPT + 1) * sizeof(*prompt))))
    {
      while (*raw_prompt && i++ < (BUF_PROMPT / 4))
	{
	  if (*raw_prompt == '%' && *(raw_prompt + 1))
	    {
	      raw_prompt++;
	      if (*raw_prompt == 'u' || *raw_prompt == 'U')
		concat_prompt(prompt, get_env_from_list("USER"), 0);
	      else if (*raw_prompt == 'h' || *raw_prompt == 'H')
		concat_prompt(prompt, get_env_from_list("HOST"), 0);
	      else if (*raw_prompt == 'p' || *raw_prompt == 'P')
		concat_prompt(prompt, _pwd(getcwd(NULL, MAXPATHLEN)), 1);
	    }
	  else
	    prompt[my_strlen(prompt)] = *raw_prompt;
	  raw_prompt++;
	}
      return (prompt);
    }
  return (NULL);
}

char		*generate_prompt(void)
{
  char		*buf;
  char		*prompt;
  static char	flg;

  prompt = NULL;
  buf = get_set_from_list("PROMPT");
  if (buf && check_prompt_syntax(buf))
    {
      flg = 1;
      prompt = update_prompt_line(buf);
    }
  else if (flg == 1)
    {
      flg = 0;
      fprintf(stderr, "Error in prompt... Prompt restored\n");
    }
  else
    prompt = update_prompt_line(DEFAULT_PROMPT);
  return (prompt);
}
