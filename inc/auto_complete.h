/*
** readstd.c for mysh in /u/all/strzel_a/cu/rendu/c/my_ls
**
** Made by alexandre strzelewicz
** Login   <strzel_a@epitech.net>
**
** Started on  Mon Dec  7 15:08:13 2009 alexandre strzelewicz
** Last update Sun May 23 13:00:53 2010 julien di-marco
*/

#ifndef _AUTO_COMPLETE_H_
#define _AUTO_COMPLETE_H_

# define BUFF_SIZE	1024
# define ENV_VAR_SIZE	1024
# define MORE_SPACE	3

# define MAX_CHOICE_DIP 70

typedef struct	s_window
{
  int		nb_col;
  int		nb_row;
  int		size_longest;
  int		list_size;
}		t_window;

typedef struct	s_list
{
  char		*data;
  char		type;
  struct s_list	*previous;
  struct s_list	*next;
}		t_list;

#include	"my_readline.h"

char		*auto_complete(t_rl *st_rl, t_shell *);

t_list		*file_completion(char *command);
t_list		*current_file_completion(char *command);
t_list		*slash_completion(char *command);
t_list		*tilde_completion(char *command);

int		alias_completion(char *cmd, t_list **st_list,
				 t_alias *st_alias);
int		set_environ_completion(char *cmd, t_list **st_list);
int		builtin_completion(char *command, t_list **st_list);

int		_file_completion_1(char *buffer, char *file, char *command,
				   char *buffer_2);
int		_file_completion_2(char *buffer, char *buffer_2, char *path,
				   char *command);
int		_file_completion_tilde(char *buffer_2, char *path, char *cmd);
int		pre_display_file(int *count, t_list *st_list, char *command, \
				 UNUSED char *path, t_env *env);
int		concatenate_file(char *dest_str, char *src_str, char *to_add);
int		xfree_completion(char *st1, char *st2, char *st3,	\
				 t_list **st_list);
int		free_st_list(t_list *st_list);
int		memset_cpy_n_modif(char *path, char *command);
int		one_gap_modification(char *command);
int		optimise_completion(char *command, UNUSED int *count);
int		optimise_completion_2(char *buffer, char *command,
				      UNUSED int *count);
int		is_there_a_slash(char *str);

int		put_in_list(char *file, t_list **st_list, int type);

int		add_slash_to_buf_if_dir(char *buf, char *destbuf, char *path);
int		add_slash_to_buf_if_dir_without_conc(char *buf, char *buf2);
t_list		*display_file(void);
int		_file_completion_3(char *, char *, char *, char *);

char		*operate_auto_completion(t_list *, char *, char *, int *);

char		*forge_new_command(char *cmd, char *seq, int *i, int beg);

/*
** display
 */

int		display_auto_complete_list(t_list *st_list);
int		calc_longest_word_list(t_list *st_list);
int		how_much_column(int longest_size);
int		how_much_line(int arg_nb, int column_number);

int		display_list(t_list *st_list, t_window *st_window);


#endif /* _AUTO_COMPLETE_H_ */
