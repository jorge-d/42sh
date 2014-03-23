/*
** init_program.c for 42sh in /u/all/jorge_d/cu/svn/42shsvn/trunk/srcs/initialisation
**
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
**
** Started on  Fri May  7 18:04:49 2010 dimitri jorge
** Last update Sat May 22 14:25:42 2010 fares sabbagh
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include "42sh.h"
#include "hreact.h"
#include "set_environ.h"

#ifdef		__HREACT_ON__

static int	init_hreact(t_shell *shell)
{
  t_hreact	*dcmd;

  if ((dcmd = shell->st_hreact))
    {
      gl_resize = 0;
      dcmd->x_width_window = X_MAX_WIDHT_FRAME;
      dcmd->y_lenght_window = Y_MAX_LENGHT_FRAME;
      dcmd->flags = 0;
      dcmd->flags &= DISP_STATE;
      shell->st_hreact = dl_init_spe_disp(dcmd);
    }
  return (RT_SUCCESS);
}

#endif		/* __HREACT_ON__ */

static void	load_default_conf(t_shell *ptr, char **env)
{
  (void)ptr;
  _env_copy(env);
  fill_default_set_environ();
#ifdef		__HREACT_ON__
  init_hreact(ptr);
#endif		/* __HREACT_ON__ */
}

static void	load_personalized_conf(t_shell *ptr)
{
  read_file(ptr);
  load_hist_file(&(ptr->st_hist));
}

void		reset_line(t_shell *shell)
{
  if (shell && CHCK(shell->rl.flags, 0x04))
    {
      if (ioctl(STDIN_FILENO, TIOCSETA, &shell->terminal) == -1)
	perror("42sh");
      handle_sign(SIG_DFL);
    }
}

void		init_program(t_shell *ptr, char **env)
{
  ptr->rl.flags = 0;
  gl_st.tty = 0;
  ptr->flag |= SH_EXIT;
  ptr->rl.bind = NULL;
  ptr->rl.prompt = NULL;
  ptr->st_tree = NULL;
  ptr->st_alias = NULL;
  ptr->my_env = NULL;
  ptr->st_hist = NULL;
  ptr->rl.flags |= init_term(ptr);
#ifdef		__HREACT_ON__
  if (!(ptr->st_hreact = xcalloc(1, sizeof(t_hreact))))
    ptr->st_hreact = NULL;
# else
  ptr->st_hreact = NULL;
#endif		/* __HREACT_ON__ */
  load_default_conf(ptr, env);
  load_personalized_conf(ptr);
  set_env_to_set();
}
