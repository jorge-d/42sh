/*
** my.h for my_printf in /u/all/strzel_a/cu/rendu/c/my_printf
** 
** Made by alexandre strzelewicz
** Login   <strzel_a@epitech.net>
** 
** Started on  Mon Nov  9 11:50:26 2009 alexandre strzelewicz
** Last update Sat May 22 21:28:22 2010 dimitri jorge
*/


#ifndef		__MY_H__
# define	__MY_H__

# include "sysincludes.h"
# include "terminal.h"
# include "define.h"

# define BUFF_SIZE	256
# define BUF_READ	50

/*
** structures
*/

typedef struct		s_env
{
  char			*var;
  struct s_env		*next;
  struct s_env 		*prev;
}			t_env;

typedef struct		s_gl
{
  t_env			*st_set;
  t_env			*st_env;
  t_ttysize		size;
  int			tty;
}			t_gl;

extern t_gl		gl_st;

void		my_putstr(char *str);
int		my_put_nbr(int nb);


/*
** ./lib/
*/

int		my_strlen(char *str);
char		*my_strncpy(char *dest, char *src, int n);
int		my_strcmp(char *s1, char *s2);
int		my_strncmp(char *s1, char *s2, int n);
char		*my_strcat(char *str1, char *str2);
char		*my_strncat(char *str1, char *str2, int n);
char		**my_str_to_wordtab(char *str);
void		*my_memset(void *b, int c, size_t len);
void            my_perror(char *, ...);
int		my_tablen(char **);
char            *get_next_line(int);
char		**malloc_table(char **, char *, int);
void		free_table(char **);

/*char		*my_strdup(char *str);*/

pid_t           xfork(void);
int		xreadlink(char *path, char *buff, int bufsiz);
DIR		*xopendir(const char *name);
void		xclosedir(DIR *dir);

/*
** display_errors.c
*/
void		my_put_error(char *);
void		display_errors(int, char *, int);

/*
** xfonction.c
*/
int		xstat(char *, struct stat *);
int		xlstat(char *, struct stat *);
int             xopen(char *, int, int);
void		*xmalloc(size_t);
void		*xcalloc(size_t, size_t);
void            xclose(int);

/*
** xfonction_2.c
*/
int		xfopen(char *, char *);
int             xwrite(int, char *, int);
int             xread(int, char *, int);
void		xfree(void *p);
int		xpipe(int *);

/*
** xfonction_3.c
*/
void            xclosedir(DIR *);
void            xfree_tab(char **);

#endif
