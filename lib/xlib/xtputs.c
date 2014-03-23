/*
** xtputs.c for 42sh in /u/all/jorge_d/cu/svn/42shsvn/trunk/lib
** 
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
** 
** Started on  Sun May 23 16:05:15 2010 dimitri jorge
** Last update Sun May 23 16:05:15 2010 dimitri jorge
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"terminal.h"

# define ERROR_TPUTS	"Error: Tputs error\n"

#ifdef			_Darwin_
void			xtputs(const char *str, int affcnt,
				int (*putc)(int))
{
  if (tputs(str, affcnt, putc) == ERR)
    {
      fprintf(stderr, ERROR_TPUTS);
    }
}
#endif
#ifdef			_FreeBSD_
void			xtputs(const char *str, int affcnt,
				int (*putc)(int))
{
  if (tputs(str, affcnt, putc) == ERR)
    {
/*       fprintf(stderr, ERROR_TPUTS); */
    }
}
#endif
#ifdef			_NetBSD_
void			xtputs(const char *str, int affcnt,
				int (*putc)(int))
{
  tputs(str, affcnt, putc);
}
#endif
#ifdef			_SunOS_
void		xtputs(char *str, int affcnt,
		       int (*putc)(char))
{
  if (tputs(str, affcnt, putc) == ERR)
    {
      fprintf(stderr, ERROR_TPUTS);
    }
}
#endif
