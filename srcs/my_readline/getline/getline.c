/*
** getline.c for  in /u/all/di-mar_j/cu/svn/VSHsvn/branches/my_readline/new
**
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
**
** Started on  Fri Apr 23 01:11:03 2010 julien di-marco
** Last update Sat May 22 19:46:12 2010 dimitri jorge
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	"42sh.h"
#include	"my_readline.h"

/*
** Execute Bind - Call by who want.
** This function execute the bind wanted giving to the
** function binded the base, the buffer read, or everything
** you want.
*/

int		execute_bind(t_bind *bind, t_rl *base,
			     t_shell *shell, char *readc)
{
  t_bind_funct	*funct;

  if (bind && (funct = bind->func))
    return (funct->func(shell, base, readc));
  else
    fprintf(stderr, "bind corupt\n");
  return (-1);
}

/*
** Check entire - call by getline or print_buf - NOT USER
** this fonction perform a comparison between the buffer
** 'read' and all the bind database if there is a match
** this finction return a pointer to the bind that match.
** This Function Handle, key and range.
*/

t_bind		*check_entire(char *read, t_bdb *data)
{
  t_bind	*bind;

  while (data)
    {
      if ((bind = data->keybind))
	{
	  if ((CHCK(bind->flags, INTER)) && (cm_inter(bind, read) == 0))
	      return (bind);
	  else if (bind->key && !bind->key2 && \
		   !(cmp_key(bind->key, read, READSIZE)))
	      return (bind);
	  data = data->next;
	}
      else
	fprintf(stderr, E_BDB_CORUPT);
    }
  return (NULL);
}

/*
** Print Buf - Call by GetLine - NOT USER
** this fonctions perfom the copy past, from the system,
** so if chec_entire does nothing, print buf do.
** This Functions parse the buffer 'read', and check each
** charactere with the bind database, if there is a math, he execute
** the function associated.
** -> see check_entire(^)
*/

static int	print_buf(char *read, t_rl *base, t_shell *shell)
{
  t_bind	*bind;
  int		size;
  char		cara[2];
  int		i;

  i = 0;
  size = 1;
  cara[0] = '\0';
  cara[1] = '\0';
  while (read[i] && (read[i] != CTRL('[')))
    {
      cara[0] = read[i];
      if ((bind = check_entire(cara, base->bind)))
	if ((size = execute_bind(bind, base, shell, cara)) == 0)
	  return (size);
      i++;
    }
  return (size);
}

/*
** GetLine - Call by my_readline - NOT USER
** This functions is magic !.
** this function perform the read, and then check if the buffer read
** match with a bind define in the database.
** if there is something match, we execute the bind with (execute_bind)
** but i repeat, this is magical .
*/

char		*getline(t_rl *base, t_shell *shell)
{
  char		readc[READSIZE + 1];
  t_bind	*bind;
  int		size;

  size = 1;
  buffer_size(base);
  while (size)
    {
      memset(readc, '\0', READSIZE + 1);
      if ((size = read(STDIN_FILENO, readc, READSIZE)) != -1)
	{
	  if ((bind = check_entire(readc, base->bind)))
	    size = execute_bind(bind, base, shell, readc);
	  else
	    size = print_buf(readc, base, shell);
	}
      else
	{
	  fprintf(stderr, "\nError reading !\n");
	  return (NULL);
	}
    }
  xfree(base->tmp.buffer);
  rewind_hist(shell);
  return (base->info.buffer);
}
