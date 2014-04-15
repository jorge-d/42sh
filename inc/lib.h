/*
** lib.h for 42sh in /u/all/jorge_d/cu/svn/42shsvn/trunk
**
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
**
** Started on  Wed Apr 21 16:48:35 2010 dimitri jorge
** Last update Sat May 22 13:16:14 2010 dimitri jorge
*/

#ifndef		__LIB_H__
# define	__LIB_H__

#include	<sys/types.h>
#include	<dirent.h>

/*
** get_next_line
*/

char		*get_next_line(const int fd);

/*
** xfunctions
*/

int		xchdir(char *);
int		xread(int, void *, int);
int		xwrite(int, void *, int);
void		*xmalloc(int);
void		*xcalloc(size_t, size_t);
void		xfree(void *);
pid_t		xfork(void);
pid_t		xwait(int *);
void		xexecve(char *, char **, char **);
int		xpipe(int *);
int             xopen(char *, int, int);
void		xclose(int);
void		xclosedir(DIR *);
int		xdup2(int, int);

/*
** my_Libc
*/

int		my_strlen(char *);
int		my_tablen(char **);

char		*my_strcat(char *, char *);
char		*my_strcpy(char *, char *);

int		my_strcmp(char *, char *);
int		my_strncmp(char *, char *, int);
char		*my_strdup(char *, char *);
char		*my_strndup(char *, int);
int		my_fdstr(int fd, char *str);

char		**my_str_to_wordtab(char *);

void		free_table(char **);
char		**malloc_table(char **, char *, int);

/*
** My Printf
*/

int		my_fprintf(int file, char *str, ...);
int		my_printf(char *str, ...);

#endif		/* !LIB_H__ */
