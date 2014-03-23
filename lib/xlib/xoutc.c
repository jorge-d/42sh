/*
** my_outc.c for my_outc in /u/all/jorge_d/svn/VSHsvn/trunk/lib
** 
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
** 
** Started on  Wed Apr  7 15:45:31 2010 dimitri jorge
** Last update Wed May 19 18:07:01 2010 julien di-marco
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<fcntl.h>
#include	"lib.h"
#include	"terminal.h"

#ifdef				_Darwin_
int			xoutc(int c)
{
  char			tmp;

  if (!(gl_st.tty))
    gl_st.tty = xopen("/dev/tty", O_WRONLY, -1);
  tmp = c;
  write(gl_st.tty, &tmp, 1);
  return (0);
}
#endif
#ifdef		       _FreeBSD_
int			xoutc(int c)
{
  char			tmp;

  if (!(gl_st.tty))
    gl_st.tty = xopen("/dev/tty", O_WRONLY, -1);
  tmp = c;
  write(gl_st.tty, &tmp, 1);
  return (0);
}
#endif
#ifdef		       _NetBSD_
int			xoutc(int c)
{
  char			tmp;

  if (!(gl_st.tty))
    gl_st.tty = xopen("/dev/tty", O_WRONLY, -1);
  tmp = c;
  write(gl_st.tty, &c, 1);
  return (0);
}
#endif
#ifdef			_SunOS_
int			xoutc(char c)
{

  if (!(gl_st.tty))
    gl_st.tty  xopen("/dev/tty", O_WRONLY, -1);
  write(gl_st.tty, &c, 1);
  return (0);
}
#endif
