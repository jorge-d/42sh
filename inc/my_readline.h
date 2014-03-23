/*
** my_readline.h for My Readline Header in /u/all/di-mar_j/cu/svn/VSHsvn/branches/my_readline-new
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Mon Apr 19 13:00:29 2010 julien di-marco
** Last update Sun May 23 05:51:26 2010 julien di-marco
*/

#ifndef		MY_READLINE_H__
# define	MY_READLINE_H__

#include	"rl_def.h"

/*
**	Functions
*/

int		init_readline(t_rl *);
void		reset_readline(t_rl *);

int		default_database(t_rl *);
int		move_cursor(t_rl *, int);
int		_move_cursor(t_rl *, int);

/*
** getline.c
*/

int		buffer_size(t_rl *);
int		cm_inter(t_bind *, char *);

int		print_prompt(t_rl *, char *);

char		*cap(char *term);
void		apply_tparm(char *term, int value);
int		show_funcs();

#endif		/* !MY_READLINE_H__ */
