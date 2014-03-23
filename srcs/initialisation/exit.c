/*
** init_program.c for 42sh in /u/all/jorge_d/cu/svn/42shsvn/trunk/srcs/initialisation
** 
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
** 
** Started on  Fri May  7 18:04:49 2010 dimitri jorge
** Last update Sat May 22 12:35:25 2010 alexandre strzelewicz
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "42sh.h"
#include "set_environ.h"

void		exit_42sh(t_shell *ptr)
{
  save_hist_to_file(ptr->st_hist);
  if (gl_st.tty)
    close(gl_st.tty);
  free_database(&ptr->rl.bind);
  free_tree(ptr->st_tree);
  free_env(gl_st.st_set);
  free_env(gl_st.st_env);
  free_alias(ptr->st_alias);
  free_history(ptr->st_hist);
#ifdef	__HREACT_ON__
  free_hreact(ptr->st_hreact);
#endif	/* !__HREACT_ON__ */
  free_table(ptr->my_env);
  reset_line(ptr);
}
