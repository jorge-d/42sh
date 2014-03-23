/*
** free_tree.c for 42sh in /u/all/jorge_d/cu/svn/42shsvn/trunk/srcs/execution
** 
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
** 
** Started on  Tue May 11 18:42:13 2010 dimitri jorge
** Last update Sun May 23 14:49:00 2010 dimitri jorge
*/

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include "parserll.h"
#include "lib.h"

void		free_tree(t_tree *begin)
{
  if (begin)
    {
      free_tree(begin->next);
      free_tree(begin->right);
      free_tree(begin->left);
      free_table(begin->args);
      xfree(begin->full_path);
      xfree(begin);
    }
}
