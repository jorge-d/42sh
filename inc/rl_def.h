/*
** rl_def.h for Readline Definitions in /u/all/di-mar_j/cu/svn/42shsvn/trunk
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Fri May 14 17:32:01 2010 julien di-marco
** Last update Sat May 22 17:12:24 2010 alexandre strzelewicz
*/

#ifndef		RL_DEF_H__
# define	RL_DEF_H__

/*
**	TermcapInclude
*/

#include	"terminal.h"
#include	"message-rl.h"
#include	"bindkey.h"

/*
**	Structures
*/

typedef struct	s_readline
{
  char		*buffer;
  char		*tmp;
  int		i;
  int		nb;
  int		insert_m;
}		t_readline;

typedef	struct	s_rl
{
  t_bdb		*bind;
  char		*prompt;
  t_termios	terminal;
  t_readline	info;
  t_readline	tmp;
  int		p_len;
  int		flags;
}		t_rl;

/*
**	Defines
*/

# define MFALSE		0
# define MTRUE		1

# ifdef __GNUC__
#  define UNUSED	__attribute__ ((unused))
# else
#  define UNUSED
# endif	/* !__GNUC__ */

# define UN		UNUSED

# define READIT		6
# define SIZEB		256
# define MAX_ARG	4096
/* # define MAXBUF		(64 * SIZEB) */

# define MAXBUF		((gl_st.size.ts_lines - 3) * gl_st.size.ts_cols)

# define BUFF_PROMPT	256

# define CHCK(a, b) (((a) & (b)) == (b)) ? (1):(0)

# define BUFSIZE(p)	((((p->info.nb) / SIZEB) + 1) * SIZEB)
# define NEWSIZE(p)	((((p->info.nb + 1) / SIZEB) + 1) * SIZEB)

# define LINE(i, x)	((i + x->p_len) / gl_st.size.ts_cols)
# define ROW(i, x)	((i+ x->p_len) - (LINE(i, x) * (gl_st.size.ts_cols)))


# define H_START	1
# define H_UNDEFINE	0
# define H_END		2

#endif		/* !RL_DEF_H__ */
