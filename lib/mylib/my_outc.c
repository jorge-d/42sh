/*
** my_outc.c for my_outc in /u/all/jorge_d/svn/VSHsvn/trunk/lib
**
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
**
** Started on  Wed Apr  7 15:45:31 2010 dimitri jorge
** Last update Wed May 19 20:10:04 2010 fares sabbagh
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"lib.h"
#include	"terminal.h"

#ifdef				_Darwin_
int			my_outc(int c)
{
  static int		tty = 0;
  char			tmp;

  if (!tty)
    tty = open("/dev/tty", O_WRONLY);
  tmp = c;
  write(tty, &tmp, 1);
  return (0);
}
#endif
#ifdef		       _FreeBSD_
int			my_outc(int c)
{
  static int		tty = 0;
  char			tmp;

  if (!tty)
    tty = open("/dev/tty", O_WRONLY);
  tmp = c;
  write(tty, &tmp, 1);
  return (0);
}
#endif
#ifdef		       _NetBSD_
int			my_outc(int c)
{
  static int		tty = 0;
  char			tmp;

  if (!tty)
    tty = open("/dev/tty", O_WRONLY);
  tmp = c;
  write(tty, &c, 1);
  return (0);
}
#endif
#ifdef			_SunOS_
int			my_outc(char c)
{
  static int		tty = 0;

  if (!tty)
    tty = open("/dev/tty", O_WRONLY);
  write(tty, &c, 1);
  return (0);
}
#endif

