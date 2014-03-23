/*
** free_env.c for 42sh in /u/all/jorge_d/cu/svn/42shsvn/trunk/srcs
** 
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
** 
** Started on  Fri May  7 18:11:02 2010 dimitri jorge
** Last update Thu May 20 18:12:24 2010 julien di-marco
*/

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include "42sh.h"

void	free_env(t_env *begin)
{
  t_env	*tmp;

  while (begin)
    {
      tmp = begin;
      begin = begin->next;
      xfree(tmp->var);
      xfree(tmp);
    }
}
