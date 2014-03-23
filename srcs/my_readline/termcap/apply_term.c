/*
** apply_term.c for Apply Tc to Term in /u/all/di-mar_j/svn/minishell2/termcap
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Mar  4 16:22:48 2010 julien di-marco
** Last update Sun May 23 03:20:42 2010 julien di-marco
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	"my_readline.h"

void		apply_term(char	*term)
{
  char		*str;
  char		buff[MAX_ARG];
  char		*ptr;

  ptr = buff;
  memset(buff, '\0', MAX_ARG);
  if (((str = xtgetstr(term, &ptr))))
    xtputs(str, 1, xoutc);
}

char		*cap(char *term)
{
  char		*str;
  char		buff[MAX_ARG];
  char		*ptr;

  ptr = buff;
  memset(buff, '\0', MAX_ARG);
  if (((str = xtgetstr(term, &ptr))))
    return (str);
  return (NULL);
}

void		apply_tparm(char *term, int value)
{
  char		*str;
  char		buff[MAX_ARG];
  char		*ptr;

  ptr = buff;
  memset(buff, '\0', MAX_ARG);
  if (((str = xtgetstr(term, &ptr))) && (str = tparm(str, value)))
    xtputs(str, 1, xoutc);
}
