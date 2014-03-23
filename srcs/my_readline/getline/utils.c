/*
** utils.c for Utils functions for my readline in /u/all/di-mar_j/cu/svn/VSHsvn/branches/my_readline/getline
**
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
**
** Started on  Sat May  8 14:56:20 2010 julien di-marco
** Last update Sat May 22 19:28:31 2010 julien di-marco
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	"42sh.h"
#include	"my_readline.h"

int		buffer_size(t_rl *base)
{
  if (!base->info.nb && !base->info.buffer)
    {
      if (!(base->info.buffer = xmalloc((NEWSIZE(base) + 4) * \
					sizeof(*base->info.buffer))))
	return (0);
    }
  else if (base->info.nb >= (BUFSIZE(base) - 1))
    {
      if ((base->info.nb + 1) < MAXBUF)
	{
	  if (!(base->info.buffer = realloc(base->info.buffer, \
					    (NEWSIZE(base) + 4) * \
					    sizeof(*base->info.buffer))))
	    return (0);
	  memset(&base->info.buffer[base->info.nb], '\0', (SIZEB + 3));
	}
      else
	return (0);
    }
  return (1);
}

int		cm_inter(t_bind *bind, char *read)
{
  if (bind && bind->key && bind->key2)
    {
      if ((strkeyh(bind->key, read) == 0) && \
	  (strkeyl(bind->key2, read) == 0))
	return (0);
    }
  return (1);
}
