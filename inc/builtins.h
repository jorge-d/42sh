/*
** builtins.h for 42sh in /u/all/jorge_d/cu/svn/42shsvn/trunk
** 
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
** 
** Started on  Wed Apr 21 17:35:31 2010 dimitri jorge
** Last update Fri May 21 14:12:35 2010 dimitri jorge
*/

#ifndef		__BUILTINS_H__
# define	__BUILTINS_H__

# include	"42sh.h"

int		hreact_ptr(t_tree *tree, t_shell *);

/*
** builtin functions
*/

int		my_cd(char *, t_tree *);
int		my_unsetenv(char **);
int		my_setenv(char **, t_tree *);
int		aff_env(t_tree *);
int		_check_var_syntax(char *);

/*
** builtin pointers
*/

int		chdir_ptr(t_tree *, t_shell *);
int		aff_env_ptr(t_tree *, t_shell *);
int		setenv_ptr(t_tree *, t_shell *);
int		unsetenv_ptr(t_tree *, t_shell *);
int		exit_ptr(t_tree *, t_shell *);
int		echo_ptr(t_tree *, t_shell *);
int		hist_ptr(t_tree *, t_shell *);

int		set_ptr(t_tree *, t_shell *);
int		unset_ptr(t_tree *, t_shell *);

int		alias_ptr(t_tree *, t_shell *);
int		unset_alias_ptr(t_tree *, t_shell *);

#ifdef		__BINDKEY_ON__
int		bindkey_ptr(t_tree *, t_shell *);
#endif		/* !__BINDKEY_ON_ */

#endif		/* !_BUILTINS_H__ */
