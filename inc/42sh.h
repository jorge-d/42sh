/*
** 42sh.h for Heade in /Users/lifely/Developer/project/42shsvn/trunk
**
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
**
** Started on  Mon May 17 00:58:27 2010 julien di-marco
** Last update Sun May 23 05:51:30 2010 julien di-marco
*/

#ifndef		__42SH_H__
# define	__42SH_H__

# include "lib.h"
# include "rl_def.h"
# include "parserll.h"

/*
** Activation des bonus a la compil:
** Commenter ou decommenter un define pour
** le desactiver ou l'Activer.
**
** "This is a features".
** Have Fun
**
*/

# ifdef __GNUC__
#  define UNUSED	__attribute__ ((unused))
# else
#  define UNUSED
# endif	/* !__GNUC__ */

# ifdef _FreeBSD_
#  define __HREACT_ON__
# endif /* !_FreeBSD_ */

# define __BINDKEY_ON__

/*
**	Defines
*/

# define OFF		0
# define ON		1

# define RT_SUCCESS	1
# define RT_FAILURE	0

# define SH_EXIT	0x01

# define FATAL_ERROR	-3

# define UNUSED_FLAG	0x02
# define UNUSED_FLAG_2	0x04

# define MAX_SET_SIZE	1024

/*
**	Structures
*/

typedef struct		s_signal
{
  int			number;
  char			*msg;
}			t_signal;

typedef struct		s_env
{
  char			*var;
  struct s_env		*next;
  struct s_env 		*prev;
}			t_env;

typedef struct		s_alias
{
  char			*alias;
  char			*cmd;
  struct s_alias	*next;
  struct s_alias	*prev;
}			t_alias;

typedef struct		s_hreact_cmd
{
  char			*spe_cmd;
  char			comment[1024];
}			t_hreact_cmd;

typedef struct		s_hreact
{
  int			x_width_window;
  int			y_lenght_window;
  t_hreact_cmd		*cmd;
  int			fork_pid;
  int			flags;
  int			x;
  int			y;
  char			*cmstr;
}			t_hreact;

typedef struct		s_hist
{
  char			*line;
  char			*time;
  int			i;
  int			aff;
  struct s_hist 	*next;
  struct s_hist 	*prev;
}			t_hist;

typedef struct		s_builtins
{
  char			*builtin_cmd;
  int			(*ptr_func)();
}			t_builtins;

typedef struct		s_gl
{
  t_env			*st_set;
  t_env			*st_env;
  t_ttysize		size;
  int			tty;
}			t_gl;

typedef struct		s_shell
{
  t_tree		*st_tree;
  t_alias		*st_alias;
  t_hist		*st_hist;
  t_hreact		*st_hreact;
  t_termios		terminal;
  t_rl			rl;
  char			**my_env;
  int			flag;
}			t_shell;

t_gl			gl_st;

/*
**	Prototypes
*/

/*
** History
*/

int		rewind_hist(t_shell *shell);
int		put_in_hist_list(t_hist **gl_list, char *builtin);
void		save_hist_to_file(t_hist *);
void		load_hist_file(t_hist **st_history);
void		save_to_history(t_shell *st_shell, char *line);

/*
** get_env.c
*/

char		*get_env_from_list(char *var);
char		*set_value(char *var, char *value);

/*
**
*/

void		lexor_and_parsor(char *line, t_shell *st_shell);
void		exit_42sh(t_shell *ptr);
void		init_program(t_shell *ptr, char **env);
void		my_put_in_list(t_env **begin, char *data);
int		check_builtins(t_shell *ptr, t_tree *tree);
char		*get_absolute_path(char *binary);
char		*get_full_path(char *path, char *binary);
int		is_builtin(char *cmd);

/*
** alias
*/

char		**expend_alias(char **cmd, t_alias *st_alias);

/*
** Free functions
*/

void		free_env(t_env *);
char		**list_to_table(t_env *env);
void		free_alias(t_alias *st_alias);
void		free_history(t_hist *st_hist);
void		free_hreact(t_hreact *st_hreact);

/*
** Execution
*/

int		write_statut(int statut);

void		main_execution(t_shell *st_shell);
int		execute_it(t_tree *tree, t_shell *st_shell);

int		check_var_on_env(char **args, t_tree *tree);
void		close_trees_fd(t_tree *begin);

int		spe_left(t_tree *tree, t_shell *st_shell);
int		left_redirection(t_tree *tree, t_shell *st_shell);

int		right_redirection(t_tree *tree, t_shell *st_shell);

int		execute_right_redir_spe(t_tree *tree, t_shell *st_shell);

void		set_fd_out(t_tree *begin, int fd);
void		set_fd_in(t_tree *begin, int fd);
int		check_quotes_and_unset(char *cmd, t_tree *tree);
int		execute_simple_command(t_tree *tree, t_shell *st_shell);
int		prepare_all_commands(t_tree *tree, t_shell *st_shell);
int		prepare_command(t_tree *tree, t_shell *st_shell);

void		set_fd_out(t_tree *begin, int fd);
void		set_fd_in(t_tree *begin, int fd);
int		check_quotes_and_unset(char *cmd, t_tree *tree);

void		remove_sequence_quote(char **cmd, t_tree *tree);

int		check_tilde(char *s);
int		concat_tilde(char **args, t_tree *tree, int i);
void		exec_line(char *cmd, t_shell *st_shell);


/*
** Execute commands
*/

int		execute_simple_command(t_tree *tree, t_shell *st_shell);
int		execute_last_command(t_tree *tree, t_shell *st_shell);
int		execution_chain(t_tree *tree, t_shell *st_shell);
int		execute_pipe_start(t_tree *tree, t_shell *st_shell);
int		execute_simple_pipe(t_tree *tree, t_shell *st_shell);
void		init_first_pipe(t_tree *tree, t_shell *st_shell, int *fd);
void		init_first_pipe_spe(t_tree *tree, t_shell *st_shell, int *fd);


/*
** prompt
*/

char		*generate_prompt(void);

int		read_file(t_shell *stShell);

/*
**	Functions - That user can bind - My Readline
*/

char		*my_readline(t_shell *shell, char *prompt);

char		*vsh_getline(t_rl *, t_shell *);

int		self_insert_command(t_shell *, t_rl *, char *);
int		overwrite_mode(t_shell *, t_rl *, char *);
int		backward_char(t_shell *, t_rl *, char *);
int		forward_char(t_shell *, t_rl *, char *);
int		accept_line(t_shell *, t_rl *, char *);
int		backward_delete_char(t_shell *, t_rl *, char *);
int		delete_char_or_lt_or_eof(t_shell *, t_rl *, char *);
int		clear_line(t_shell *, t_rl *, char *);
int		complete_word(t_shell *, t_rl *, char *);

int		down_line_or_history(t_shell *, t_rl *, char *);
int		up_line_or_history(t_shell *, t_rl *, char *);

int		clear_it(t_shell *, t_rl *, char *);
int		redraw(t_shell *, t_rl *, char *);

int		beginning_of_line(t_shell *, t_rl *, char *);
int		end_of_line(t_shell *, t_rl *, char *);

/*
** exit
*/

void		_env_copy(char **env);
void		reset_line(t_shell *shell);
void		handle_sign(void (*type)(int));
int		init_term(t_shell *sh);

#endif		/* !42SH_H__ */
