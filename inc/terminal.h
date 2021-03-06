/*
** terminal.h for Terminal & Termcap in /u/all/di-mar_j/cu/svn/VSHsvn/branches/my_readline-new
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Mon Apr 19 13:03:42 2010 julien di-marco
** Last update Sun May 23 03:40:47 2010 julien di-marco
*/

#ifndef		TERMINAL_H__
# define	TERMINAL_H__

/*
**	Portabilite !
*/

#  include	<sys/ioctl.h>
#  include	<termios.h>

# ifndef	TIOCGETA
#   define	TIOCGETA TCGETS
#   define	TIOCSETA TCSETS
# endif		/* !TIOCGETA */
# ifdef		_FreeBSD_
#  include	<term.h>
#  include	<ncurses.h>
# endif
# ifdef		_NetBSD_
#  include	<curses.h>
#  include	<termcap.h>
# endif
# ifdef		_Darwin_
#  include	<term.h>
#  include	<curses.h>
#  include	<termcap.h>
#  include	<sys/termios.h>
# endif
# ifdef          _SunOS_
#  include	<curses.h>
#  include	<termio.h>
#  include	<stropts.h>
#  include	<term.h>
char		*tgoto(char *, int, int);
# endif
# ifdef		_Linux_
#  include	<term.h>
#  include	<termio.h>
#  include	<ncurses.h>
# endif

/*
**	Structures
*/

typedef struct termios	t_termios;
typedef struct ttysize	t_ttysize;

/*
**	Protos
*/

char		*xtgetstr(char *, char **);
int		xtgetent(char *, char *);
char		*xtgoto(char *, int, int);

#ifdef			_FreeBSD_
void		xtputs(const char *, int, int (*putc)(int));
int		xoutc(int c);
#elif			_Darwin_
void		xtputs(const char *, int, int (*putc)(int));
int		xoutc(int c);
#elif			_NetBSD_
int		xoutc(int c);
void		xtputs(const char *, int, int (*putc)(int));
#elif			_SunOS_
int		xoutc(char c);
void		xtputs(char *, int, int (*putc)(char));
#endif			/* !SYSTEM_ */

void		apply_term(char	*);

#endif		/* !TERMINAL_H__ */
