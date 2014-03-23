/*
** check_flags.c for 42sh in /u/all/jorge_d/svn/parserll/trunk/src/parser
**
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
**
** Started on  Wed Apr 14 13:00:49 2010 dimitri jorge
** Last update Sun May 16 17:34:57 2010 dimitri jorge
*/

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "42sh.h"
#include "parserll.h"

int	check_quote_flag(char c, int flag)
{
  if (flag == 0 && c == '\'')
    flag = 1;
  else if (flag == 0 && c == '\"')
    flag = 2;
  else if (flag == 0 && c == '`')
    flag = 3;
  else if (flag == 1 && c == '\'')
    flag = 0;
  else if (flag == 2 && c == '\"')
    flag = 0;
  else if (flag == 3 && c == '`')
    flag = 0;
  return (flag);
}
